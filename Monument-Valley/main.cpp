#include "main.h"

	GLuint texture[6];

	int u = 1;
	int t1 = 1, r1 = 0, s1 = 9;
	int t2 = 1, r2 = 0, s2 = 9;
	int t3 = 0, r3 = 0, s3 = 1;
	int walk1[6] = {-1,-1,0,1,1,0};//鸟行走-腿上
	int walk2[6] = {1,0,0,0,1,0};//鸟行走-腿下
	int walk3[6] = {1,1,0,-1,-1,0};//鸟行走-腿上
	int walk4[6] = {0,1,0,1,0,0};//鸟行走-腿下
	int wa1 = 0;//鸟行走
	int wa2 = 0;//鸟行走
	int wb1 = 0;//鸟行走
	int wb2 = 0;//鸟行走
	int mb = 0;//birdB腿动
	int mi1 = 0;
	int mi2 = 0;
	int ax = 0, ay = 0, az = 0;
	float lx =0.5, ly =11, lz =5;
	float pox = 0.0, poy = 0.0, poz = 0.0;

	//设置轨迹参数
	GLfloat theta = 0.5f;
	GLfloat t = 0.0f;
	unsigned int  iMore = 0;
	int HierParam = 0;
	int Animation = 90;

	GLint view = 0;
	GLfloat ex[3] = {-1, -1, -1};
	GLfloat ey[3] = {11.0, 11.0, 11.0};
	GLfloat ez[3] = {8.0, 8.0, 8.0};

	//观察对象位置
	GLfloat fx[3] = { 0.0, 0.0, 0.0};
	GLfloat fy[3] = { 7.0, 7.0, 7.0};
	GLfloat fz[3] = { 0.0, 0.0, 0.0};
	
	//指定光源的位置
	GLfloat light_position[4] = { lx, ly, lz, 0.0};

	//设置聚光方向
	float spot_directionx=0.0;
	float spot_directiony=0.0;
	float spot_directionz=0.0;

int main(int argc, char *argv[])

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE|GLUT_DEPTH);

    glutInitWindowPosition(10, 10);

    glutInitWindowSize(600, 600);

    glutCreateWindow("乌鸦王国");

    glutDisplayFunc(&myDisplay);
	glutReshapeFunc(reshape);
	init();

	glutMouseFunc(mouse);//鼠标响应
	glutKeyboardFunc(mykey); //键盘响应

	glutIdleFunc(myDisplay);

	glutCreateMenu(mymenu); //右键菜单
	glutAddMenuEntry("Clear Screen", 1);//添加菜单1
	glutAddMenuEntry("Restore", 2);//添加菜单2
	glutAttachMenu(GLUT_RIGHT_BUTTON);//右键菜单
	 
	glutMainLoop();

    return 0;
}

void init()
{
	//glClearColor(1.0,1.0,1.0,1.0);
	//glColor3f(0.0f,0.0f,0.0f);
	//glShadeModel(GL_SMOOTH);
	

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f,0.0f,0.0f);
	glShadeModel(GL_SMOOTH);
	setLight();

	glCullFace(GL_BACK);                        //背面裁剪(背面不可见)
    glEnable(GL_CULL_FACE);                        //启用裁剪
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures();  //载入纹理贴图
	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);*/
}

void reshape(int w,int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1,1,-1,1,1.0f,10000.0f);//视景体
	//if (w <= h)
	//	glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h/(GLfloat)w, 1.5 * (GLfloat)h/(GLfloat)w, -10.0, 10.0);
	//else
	//	glOrtho(-1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	// 防止除数即高度为0
	// (你可以设置窗口宽度为0).
	//if (h == 0)
	//	h = 1;
	float ratio = 1.0* w / h;

	//// 单位化投影矩阵。
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	//// 设置视口大小为整个窗口大小
	//glViewport(0, 0, w, h);
	//glFrustum(-1,1,-1,1,1.0f,10000.0f);//视景体

	//设置正确的投影矩阵
	gluPerspective(75, ratio, 1, 100);
	/*if (w <= h)
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h/(GLfloat)w, 1.5 * (GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);*/

}


void myDisplay()
{
	if(Animation<90){
		u++;
		HierParam++;
		Animation++;
	}
	setLight();
	glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);//当前为投影矩阵
	glLoadIdentity();
	//glFrustum(-1,1,-1,1,1.0f,10000.0f);//视景体
	gluLookAt(ex[view],ey[view],ez[view],
		fx[view],fy[view],fz[view],
		0.0,1.0,0.0);//视点转换
	
	//画birdA
	glPushMatrix();
	//坐标变换
	if(iMore<8&&iMore>0){
		translate(0.6);
	}
	else if(iMore==8||iMore == 16|| iMore == 24|| iMore==32){
		r1+=9;
		translate(0.6);
	}
	else if(iMore>8&&iMore<16){
		//r1=9;
	 	translate(0.6);
	}	
	else if(iMore>16&&iMore<24){
		//r1=18;
	 	translate(0.6);
	}	
	else if(iMore>24&&iMore<32){
		//r1=27;
	 	translate(0.6);
	}	
	if(pox>=3.3||pox<=-3.3)
		glRotatef(HierParam,0.0f,1.0f,0.0f);
	if((pox>=1.1||pox<=-1.1)&&(pox<=3.3||pox>=-3.3))
		glRotatef(HierParam,0.0f,1.0f,0.0f);
	glTranslatef(pox,27*0.35,poy);
	glRotatef(10*r1,0.0,1.0,0.0);
	glScalef(0.2*s1,0.2*s1,0.2*s1);
	//glRotatef(u,0.0,1.0,0.0);
	drawBirdA();
	glPopMatrix();

	GLfloat m[16];//课件上的
    int i;
	for(i=0;i<16;i++) m[i]=0.0;
    m[0]=m[5]=m[10]=1.0;
	m[7]=-1.0/light_position[1];
	
	//画birdA阴影
	glPushMatrix();
	glTranslatef(light_position[0], light_position[1],light_position[2]);
	glMultMatrixf(m);
	glTranslatef(-light_position[0], -light_position[1],-light_position[2]);
	glTranslatef(pox,0.0,poy);
	glRotatef(10*r1,0.0,1.0,0.0);
	glScalef(0.2*s1,0.2*s1,0.2*s1);
	drawShadowBirdA();
	glPopMatrix();

	//画birdB
	//glPushMatrix();	
	//glTranslatef(4*0.35,31*0.35-R1*0.2*s2,1*0.35-R1*0.2*s2);
	//glRotatef(90,0.0,1.0,0.0);
	//glRotatef(HierParam,0.0f,1.0f,0.0f);
	//glScalef(0.2*s2,0.2*s2,0.2*s2);
	//drawBirdB();
	//glPopMatrix();

	//画太阳
	glPushMatrix();
	glTranslatef(lx,ly,lz);
	drawSun();
	glPopMatrix();

	//画背景纹理
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	drawBackground();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//画城堡
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glRotatef(u,0.0,1.0,0.0);
	//glScalef(0.35,0.35,0.35);
	drawCastle();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	//glPushMatrix();
	//glScalef(0.35,0.35,0.35);
	//glTranslatef(3*2.0f,13*2.0f,0.0f);
	//glRotatef(180,0.0f,1.0f,0.0f);
	//glRotatef(HierParam,0.0f,1.0f,0.0f);//i=1
	//
	//glPushMatrix();
	//drawPart3();
	//glPopMatrix();

	//glPushMatrix();	
	//glTranslatef(2,5-R1*0.2*s2,1-R1*0.2*s2);
	//glRotatef(90,0.0,1.0,0.0);
	//glScalef(0.2*s2,0.2*s2,0.2*s2);
	//drawBirdB();
	//glPopMatrix();
	//glPopMatrix();

	//画城堡阴影
	/*glPushMatrix();
	glTranslatef(light_position[0], light_position[1],light_position[2]);
	glMultMatrixf(m);
	glTranslatef(-light_position[0], -light_position[1],-light_position[2]);

	glPushMatrix();
	glScalef(0.02,0.02,0.02);
	drawShadowCastle();
	glPopMatrix();*/

	glutSwapBuffers();

}
