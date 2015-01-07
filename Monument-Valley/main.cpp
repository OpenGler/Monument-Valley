#include "main.h"

	GLuint texture[6];

	int u = 1;
	int t1 = 1, r1 = 0, s1 = 9;
	int t2 = 1, r2 = 0, s2 = 9;
	int t3 = 0, r3 = 0, s3 = 1;
	int walk1[6] = {-1,-1,0,1,1,0};//������-����
	int walk2[6] = {1,0,0,0,1,0};//������-����
	int walk3[6] = {1,1,0,-1,-1,0};//������-����
	int walk4[6] = {0,1,0,1,0,0};//������-����
	int wa1 = 0;//������
	int wa2 = 0;//������
	int wb1 = 0;//������
	int wb2 = 0;//������
	int mb = 0;//birdB�ȶ�
	int mi1 = 0;
	int mi2 = 0;
	int ax = 0, ay = 0, az = 0;
	float lx =0.5, ly =11, lz =5;
	float pox = 0.0, poy = 0.0, poz = 0.0;

	//���ù켣����
	GLfloat theta = 0.5f;
	GLfloat t = 0.0f;
	unsigned int  iMore = 0;
	int HierParam = 0;
	int Animation = 90;

	GLint view = 0;
	GLfloat ex[3] = {-1, -1, -1};
	GLfloat ey[3] = {11.0, 11.0, 11.0};
	GLfloat ez[3] = {8.0, 8.0, 8.0};

	//�۲����λ��
	GLfloat fx[3] = { 0.0, 0.0, 0.0};
	GLfloat fy[3] = { 7.0, 7.0, 7.0};
	GLfloat fz[3] = { 0.0, 0.0, 0.0};
	
	//ָ����Դ��λ��
	GLfloat light_position[4] = { lx, ly, lz, 0.0};

	//���þ۹ⷽ��
	float spot_directionx=0.0;
	float spot_directiony=0.0;
	float spot_directionz=0.0;

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
	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);*/
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
	if(Animation<90){
		u++;
		HierParam++;
		Animation++;
	}
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
	
	//��birdA
	glPushMatrix();
	//����任
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

	GLfloat m[16];//�μ��ϵ�
    int i;
	for(i=0;i<16;i++) m[i]=0.0;
    m[0]=m[5]=m[10]=1.0;
	m[7]=-1.0/light_position[1];
	
	//��birdA��Ӱ
	glPushMatrix();
	glTranslatef(light_position[0], light_position[1],light_position[2]);
	glMultMatrixf(m);
	glTranslatef(-light_position[0], -light_position[1],-light_position[2]);
	glTranslatef(pox,0.0,poy);
	glRotatef(10*r1,0.0,1.0,0.0);
	glScalef(0.2*s1,0.2*s1,0.2*s1);
	drawShadowBirdA();
	glPopMatrix();

	//��birdB
	//glPushMatrix();	
	//glTranslatef(4*0.35,31*0.35-R1*0.2*s2,1*0.35-R1*0.2*s2);
	//glRotatef(90,0.0,1.0,0.0);
	//glRotatef(HierParam,0.0f,1.0f,0.0f);
	//glScalef(0.2*s2,0.2*s2,0.2*s2);
	//drawBirdB();
	//glPopMatrix();

	//��̫��
	glPushMatrix();
	glTranslatef(lx,ly,lz);
	drawSun();
	glPopMatrix();

	//����������
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	drawBackground();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
	//���Ǳ�
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

	//���Ǳ���Ӱ
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
