#include "main.h"

	GLuint texture[6];

	int u = 1;
	int t1 = 1, r1 = 0, s1 = 3;
	int t2 = 1, r2 = 0, s2 = 3;
	int t3 = 0, r3 = 0, s3 = 1;

	int ax = 0, ay = 0, az = 0;
	float lx =0, ly =0.5, lz =0;
	float pox = 0.0, poy = 0.0, poz = 0.0;

	//���ù켣����
	GLfloat theta = 0.5f;
	GLfloat t = 0.0f;
	unsigned int  iMore = 0;

	GLint view = 0;
	GLfloat ex[3] = {-5, -5, -5};
	GLfloat ey[3] = {10.0, 10.0, 10.0};
	GLfloat ez[3] = {10.0, 10.0, 10.0};

	//�۲����λ��
	GLfloat fx[3] = { 0.0, 0.0, 0.0};
	GLfloat fy[3] = { 5.0, 5.0, 5.0};
	GLfloat fz[3] = { 0.0, 0.0, 0.0};
	
	//ָ����Դ��λ��
	GLfloat light_position[4] = { lx, ly, lz, 0.0};

	//���þ۹ⷽ��
	float spot_directionx=0.0;
	float spot_directiony=0.0;
	float spot_directionz=0.0;

	//int u = 1;
	//int t1 = 1, r1 = 0, s1 = 3;
	//int t2 = 1, r2 = 0, s2 = 3;
	//t3 = 0; r3 = 0; s3 = 1;

	//ax = ay = az = 0;
	//lx =0;ly =0.5; lz =0;
	//pox = 0.0; poy = 0.0; poz = 0.0;

	////���ù켣����
	//theta = 0.5f;
	//t = 0.0f;
	//iMore = 0;

	//view = 0;
	//ex[0] = ex[1] = ex[2] = -5;
	//ey[0] = ey[1] = ey[2] = 10.0;
	//ez[0] = ez[1] = ez[2] = 10.0;

	////�۲����λ��
	//fx[0] = fx[1] = fx[2] = 0.0;
	//fy[0] = fy[1] = fy[2] = 5.0;
	//fz[0] = fz[1] = fz[2] = 0.0;
	//
	////ָ����Դ��λ��
	//light_position[0] = lx;
	//light_position[1] = ly;
	//light_position[2] = lz;
	//light_position[3] = 0.0;

	////���þ۹ⷽ��
	//spot_directionx=0.0;
	//spot_directiony=0.0;
	//spot_directionz=0.0;

int main(int argc, char *argv[])

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE|GLUT_DEPTH);

    glutInitWindowPosition(10, 10);

    glutInitWindowSize(600, 600);

    glutCreateWindow("��ѻ����");

    glutDisplayFunc(&myDisplay);
	glutReshapeFunc(reshape);
	init();

	glutMouseFunc(mouse);//�����Ӧ
	glutKeyboardFunc(mykey); //������Ӧ

	glutIdleFunc(myDisplay);

	glutCreateMenu(mymenu); //�Ҽ��˵�
	glutAddMenuEntry("Clear Screen", 1);//��Ӳ˵�1
	glutAddMenuEntry("Restore", 2);//��Ӳ˵�2
	glutAttachMenu(GLUT_RIGHT_BUTTON);//�Ҽ��˵�
	 
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

	glCullFace(GL_BACK);                        //����ü�(���治�ɼ�)
    glEnable(GL_CULL_FACE);                        //���òü�
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures();  //����������ͼ
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_COLOR_MATERIAL);
}

void reshape(int w,int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1,1,-1,1,1.0f,10000.0f);//�Ӿ���
	//if (w <= h)
	//	glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h/(GLfloat)w, 1.5 * (GLfloat)h/(GLfloat)w, -10.0, 10.0);
	//else
	//	glOrtho(-1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	// ��ֹ�������߶�Ϊ0
	// (��������ô��ڿ��Ϊ0).
	//if (h == 0)
	//	h = 1;
	float ratio = 1.0* w / h;

	//// ��λ��ͶӰ����
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	//// �����ӿڴ�СΪ�������ڴ�С
	//glViewport(0, 0, w, h);
	//glFrustum(-1,1,-1,1,1.0f,10000.0f);//�Ӿ���

	//������ȷ��ͶӰ����
	gluPerspective(75, ratio, 1, 100);
	/*if (w <= h)
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h/(GLfloat)w, 1.5 * (GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);*/

}


void myDisplay()
{
	setLight();
	glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);//��ǰΪͶӰ����
	glLoadIdentity();
	//glFrustum(-1,1,-1,1,1.0f,10000.0f);//�Ӿ���
	gluLookAt(ex[view],ey[view],ez[view],
		fx[view],fy[view],fz[view],
		0.0,1.0,0.0);//�ӵ�ת��
	

	glPushMatrix();
	drawCoordinateSystem();
	glPopMatrix();

	//glPushMatrix();
	////����任
	//if(iMore<8&&iMore>0){
	//	translate(0.6);
	//}
	//else if(iMore==8||iMore == 16|| iMore == 24|| iMore==32){
	//	r1+=9;
	//	translate(0.6);
	//}
	//else if(iMore>8&&iMore<16){
	//	//r1=9;
	// 	translate(0.6);
	//}	
	//else if(iMore>16&&iMore<24){
	//	//r1=18;
	// 	translate(0.6);
	//}	
	//else if(iMore>24&&iMore<32){
	//	//r1=27;
	// 	translate(0.6);
	//}	
	//glTranslatef(pox,0.0,poy);
	////glTranslatef(+pox,0.0,0.0);
	//glRotatef(10*r1,0.0,1.0,0.0);
	//glScalef(0.2*s1,0.2*s1,0.2*s1);
	//drawBirdA();
	//glPopMatrix();

	GLfloat m[16];//�μ��ϵ�
    int i;
	for(i=0;i<16;i++) m[i]=0.0;
    m[0]=m[5]=m[10]=1.0;
	m[7]=-1.0/light_position[1];

	/*glPushMatrix();
	glTranslatef(light_position[0], light_position[1],light_position[2]);
	glMultMatrixf(m);
	glTranslatef(-light_position[0], -light_position[1],-light_position[2]);
	
	glTranslatef(pox,0.0,poy);
	glRotatef(10*r1,0.0,1.0,0.0);
	glScalef(0.2*s1,0.2*s1,0.2*s1);
	drawShadowBirdA();
	glPopMatrix();*/

	//glPushMatrix();
	//glScalef(0.5,0.5,0.5);
	//glTranslatef(1,0.0,0.0);
	//drawBirdB();
	//glPopMatrix();

	glPushMatrix();
	glTranslatef(lx,ly,lz);
	drawSun();
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	//glTranslatef(0.0,0.0,-2.0f);
	glRotatef(2*u,0.0,1.0,0.0);
	glScalef(0.35,0.35,0.35);
	drawCastle();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

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
