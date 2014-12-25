#pragma comment(lib, "glaux.lib")
#include <gl\glaux.h>
#include <TCHAR.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <gl\glut.h>


	GLuint texture[6];// ����һ��ȫ�ֵ��������飬�����洢��λͼת��֮��õ���������Ӧ���������6����
	static int u = 1;

	const int n = 500;
	const GLfloat R1 = 0.1f;
	const GLfloat R2 = 0.09f;
	const GLfloat R3 = 0.075f;
	const GLfloat R4 = 0.006f;
	const GLfloat Pi = 3.1415926537f;

	static float pox = 0.0;
	static float poy = 0.0;
	static float poz = 0.0;

	static int t1 = 1;
	static int r1 = 0;
	static int s1 = 3;

	static int t2 = 1;
	static int r2 = 0;
	static int s2 = 3;

	static int t3 = 0;
	static int r3 = 0;
	static int s3 = 1;

	static int ax = 0;
	static int ay = 0;
	static int az = 0;

	static float lx =0;
	static float ly =0.5;
	static float lz =0;

	//���ù켣����
	GLfloat theta = 0.5f;
	GLfloat t = 0.0f;
	unsigned int iMore = 0;

	GLint view = 0;
	GLfloat ex[3] = {-5, -5, -5}; //�۲���λ��
	GLfloat ey[3] = {10.0, 10.0, 10.0};
	GLfloat ez[3] = {10.0, 10.0, 10.0};
	GLfloat fx[3] = {0.0, 0.0, 0.0}; //�۲����λ��
	GLfloat fy[3] = {5.0, 5.0, 5.0};
	GLfloat fz[3] = {0.0, 0.0, 0.0};
	GLint flag;
	//ָ����Դ��λ��
	GLfloat light_position[] = { lx,ly,lz,0.0 };
	static float spot_directionx=0.0,spot_directiony=0.0,spot_directionz=0.0;//���þ۹ⷽ��
	void setLight();

//��������
void norm(GLfloat v1[3], GLfloat v2[3], GLfloat v3[3], GLfloat *nor )
{
	GLfloat vc1[3],vc2[3];
	GLfloat a,b,c;
	GLdouble r;

	vc1[0]= v2[0] - v1[0]; vc1[1]= v2[1] - v1[1]; vc1[2]= v2[2] - v1[2];
	vc2[0]= v3[0] - v1[0]; vc2[1]= v3[1] - v1[1]; vc2[2]= v3[2] - v1[2];
	a = vc1[1] * vc2[2] - vc2[1] * vc1[2];
	b = vc2[0] * vc1[2] - vc1[0] * vc2[2];
	c = vc1[0] * vc2[1] - vc2[0] * vc1[1];
	r = sqrt( a * a + b* b + c * c);
	nor[0] = a / r;
	nor[1] = b / r;
	nor[2] = c / r;
}
//����ѻA
void drawBirdA()
{
	//glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT, GL_AMBIENT);
	//���ò�������
		GLfloat material_ambient1[] = {0.1, 0.1, 0.1, 1.0};
		GLfloat material_diffuse1[] = {0.5, 0.5, 0.5, 1.0};
		GLfloat material_specular1[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess1 = 1.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient1);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse1);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular1);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess1);

	//ͷ
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//�����
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
	    GLfloat v1[3] = {-3*R1,5*R1,0.0f};
		GLfloat v2[3];
		GLfloat v3[3];
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i <= n/2; i++)
			if(i==0){
				v2[0]=0.0f;
				v2[1]=R1*sin(2*Pi/n*i)+5*R1;
				v2[2]=R1*cos(2*Pi/n*i);
				glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
			}
			else{
				v3[0]=0.0f;
				v3[1]=R1*sin(2*Pi/n*i)+5*R1;
				v3[2]=R1*cos(2*Pi/n*i);
				glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
				GLfloat normal[3];
				norm(v1,v2,v3,normal);
				glNormal3f(normal[0],normal[1],normal[2]);
				for(int j=0;j<3;j++){
					v2[j] = v3[j];
				}
			}			
	glEnd();
	glPopMatrix();

	//�����
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
		//glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i <= n/2; i++)
			if(i==0){
				v2[0]=0.0f;
				v2[1]=R1*sin(2*Pi/n*i)+5*R1;
				v2[2]=R1*cos(2*Pi/n*i);
				glVertex3f(0.0f,-R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
			}
			else{
				v3[0]=0.0f;
				v3[1]=R1*sin(2*Pi/n*i)+5*R1;
				v3[2]=R1*cos(2*Pi/n*i);
				glVertex3f(0.0f,-R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
				GLfloat normal[3];
				norm(v1,v2,v3,normal);
				glNormal3f(normal[0],normal[1],normal[2]);
				for(int j=0;j<3;j++){
					v2[j] = v3[j];
				}
			}
	glEnd();
	glPopMatrix();

	//�۾���
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

			//���ò�������
		GLfloat material_ambient2[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_diffuse2[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_specular2[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess2 = 100.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient2);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse2);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular2);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess2);

	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient1);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse1);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular1);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess1);

	//�۾���
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient2);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse2);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular2);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess2);

	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();

		GLfloat material_ambient3[] = {1.0, 0.0, 0.0, 1.0};
		GLfloat material_diffuse3[] = {1.0, 0.0, 0.0, 1.0};
		GLfloat material_specular3[] = {1.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess3 = 100.0;

		//glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient3);
		//glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse3);
		//glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular3);
		//glMaterialf( GL_FRONT, GL_SHININESS, material_shininess3);

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient1);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse1);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular1);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess1);

	//����
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//����
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//�ҽ�
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//���
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)+2*R4);
	glEnd();
	glPopMatrix();
}

void drawShadowBirdA()
{

	//���ò�������
		GLfloat material_ambient[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_diffuse[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_specular[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess = 1.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess);

		//ͷ
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//�����
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i <= n/2; i++)
			glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
	glEnd();
	glPopMatrix();

	//�����
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i < n/2; i++){
			glVertex3f(0.0f,-1*R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
		}
	glEnd();
	glPopMatrix();

	//�۾���
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();

	//�۾���
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//����
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//�ҽ�
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//���
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)+2*R4);
	glEnd();
	glPopMatrix();


}

//����ѻB
void drawBirdB()
{
	//�任
	glTranslatef(1,0.0,0.0);
	glTranslatef(-0.1*t2,0.0,0.0);
	glRotatef(10*r2,0.0,1.0,0.0);
	glScalef(0.2*s2,0.2*s2,0.2*s2);

	//ͷ
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//�����
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i <= n/2; i++)
			glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
	glEnd();
	glPopMatrix();

	//�����
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i < n/2; i++){
			glVertex3f(0.0f,-1*R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
		}
	glEnd();
	glPopMatrix();

	//�۾���
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();
	//�۾���
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//����
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//�ҽ�
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//���
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-10*R4,0,2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)+2*R4);
	glEnd();
	glPopMatrix();
}

//��̫��
void drawSun(){
			//���ò�������
		GLfloat material_ambient[] = {0.1, 0.1, 0.1, 1.0};
		GLfloat material_diffuse[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_specular[] = {0.0, 0.0, 0.0, 1.0};

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);

	//�任
	glMatrixMode(GL_MODELVIEW);//��ǰΪģ���Ӿ�����

	glPushMatrix();
	glutSolidSphere(0.05,1000,1000);
	glPopMatrix();
} 

//������ϵ
void drawCoordinateSystem()
{
	//�任
	glTranslatef(0.0,0.0,0.0);
	glRotatef(0.0,0.0,1.0,0.0);
	glScalef(1,1,1);

	glPushMatrix();
	//glColor3f(0.82, 0.82, 0.82);
	glBegin(GL_LINES);
	float i, j;
	for (i = -30; i <= 30; i = i + 0.5)
	{
		glVertex3f(i, 0, -30);
		glVertex3f(i,0, 30);
	}
	for (j = -30; j <=30; j += 0.5)
	{
		glVertex3f(-30, 0, j);
		glVertex3f(30, 0, j);
	}
	glEnd();
	glPopMatrix();

}


//����cube
void drawCube(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f( 1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(-1.0f, 1.0f, 1.0f);
	
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube(�л��������)
void drawCube01(GLvoid)         
{
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);
	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};
	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    
	glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
    GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	 //���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
   
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}
//����cube(�����ǵ�)
void drawCube02(GLvoid)         
{
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ���һ������texture[0]������������
	glBegin(GL_POLYGON);
	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {-0.9f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 0.9f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( -0.9f, -1.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 0.9f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_POLYGON);
    GLfloat tex1v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 0.9f, -1.0f};
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 0.9f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.0f, -0.9f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.0f, -1.0f, -1.0f);
    //���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, 1.0f};
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    //���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = { -0.9f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = { -0.9f, -1.0f, 1.0f};
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( -0.9f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -0.9f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    //���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, 0.9f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 0.9f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 0.9f, 1.0f);
    //���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    //���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);
	glEnd(); 

	// б�� Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex6v1[3] = {1.0f, 0.9f, -1.0f};
	GLfloat tex6v2[3] = {1.0f, 0.9f, 1.0f};
	GLfloat tex6v3[3] = {-1.0f, -0.9f, 1.0f};
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 0.9f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.9f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -0.9f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -0.9f, -1.0f);
    //���÷�����
	GLfloat tex6normal[3];
    norm(tex6v1,tex6v2,tex6v3,tex6normal);
	glNormal3f(tex6normal[0],tex6normal[1],tex6normal[2]);
	glEnd(); 

}
//����cube(����)
void drawCube03(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[3]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f( 1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(-1.0f, 1.0f, 1.0f);
	
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube�����£�
void drawCube04(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[4]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f( 1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(-1.0f, 1.0f, 1.0f);
	
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube��Բ����
void drawCube05(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[5]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); 
	glVertex3f( 1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); 
	glVertex3f( 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); 
	glVertex3f(-1.0f, 1.0f, 1.0f);
	
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[5]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube(ϸ����)
void drawCube06(GLvoid)         
{       
	glPushMatrix();
	glScalef(0.1,2,0.1);
	glTranslatef(0.0f,0.5f,0.0f);
	drawCube();
	glPopMatrix();    
}

//����cube������������
void drawCube07(GLvoid)         
{     	
	glPushMatrix();
	glScalef(0.5,0.5,0.1);
	glTranslatef(0.0f,1.0f,0.0f);
	drawCube02();
	glPopMatrix();      
	       
}

//��ʵ������׶
void drawSolidTera()
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_TRIANGLES);

		/*ǰ����Ļ���*/
	    GLfloat tex0v1[3] = {0.0,1,0.0};
		GLfloat tex0v2[3] = {-1,-1,1};
		GLfloat tex0v3[3] = {-1,-1,1};
		//���÷�����
		GLfloat tex0normal[3];
		norm(tex0v1,tex0v2,tex0v3,tex0normal);
		glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-1,-1,1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(1,-1,1);
	      

		/*�Ҳ���Ļ���*/
		GLfloat tex1v1[3] = {0.0,1,0.0};
		GLfloat tex1v2[3] = {1,-1,1};
		GLfloat tex1v3[3] = {1,-1,-1};
		//���÷�����
		GLfloat tex1normal[3];
		norm(tex1v1,tex1v2,tex1v3,tex1normal);
		glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(1,-1,1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(1,-1,-1);
		
		
		/*�����Ļ���*/
		GLfloat tex2v1[3] = {0.0,1.0,0.0};
		GLfloat tex2v2[3] = {1.0,-1.0,-1.0};
		GLfloat tex2v3[3] = {-1.0,-1.0,-1.0};
		//���÷�����
		GLfloat tex2normal[3];
		norm(tex2v1,tex2v2,tex2v3,tex2normal);
		glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1.0,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0,-1.0,-1.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-1.0,-1.0,-1.0);
		
		//glEnd();

		
		/*�����Ļ���*/
		GLfloat tex3v1[3] = {0.0,1.0,0.0};
		GLfloat tex3v2[3] = {-1.0,-1.0,-1.0};
		GLfloat tex3v3[3] = {-1.0,-1.0,1.0};
		//���÷�����
		GLfloat tex3normal[3];
		norm(tex3v1,tex3v2,tex3v3,tex3normal);
		glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1.0,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-1.0,-1.0,-1.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-1.0,-1.0,1.0);
        

	glEnd();
	glPopMatrix();
}

//����������׶
void drawWireTera()
{

}

//��part1
void drawPart1()
{
	for(int x = -1;x <= 3; x++)
	{
		
			for(int y = 0; y < 18; y++)
			{
				if(x == -1){
					if(y > 0 && y < 5){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						glRotatef(90,0.0f,0.0f,1.0f);
						drawSolidTera();
						glPopMatrix();
					}
					if(y>=5&&y<10){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube05();
						glPopMatrix();
					}
					if(y>=10&&y<16){
						if(y==14){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube04();
							glPopMatrix();
						}else if(y==15){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube03();
							glPopMatrix();
						}else{
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							drawCube();
							glPopMatrix();
						}
					}
					if(y == 16){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube01();
						glPopMatrix();
					}
					if(y ==17){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawSolidTera();
						glPopMatrix();
					}
				}
				if(x == 0){
					if(y==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						glRotatef(180,0.0f,0.0f,1.0f);
						drawSolidTera();
						glPopMatrix();
					}
					if(y>0&&y<14){
						if(y==2||y==6||y==10){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube04();
							glPopMatrix();	
						}else if(y==3||y==7||y==11){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube03();
							glPopMatrix();	
						}else{
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							drawCube();
							glPopMatrix();	
						}
					}
				}
				if(x == 1){
					if(y==1||y==5||y==9){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube();
						glPopMatrix();							
					}
					if(y==13){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube02();
						glPopMatrix();							
					}
				}
				if(x == 2){
					if(y==1||y==5||y==9){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube();
						glPopMatrix();							
					}	
				}
				if(x == 3){
					if(y==1||y==5||y==9){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube02();
						glPopMatrix();							
					}
				}
			}
		
	}
}
//��part2
void drawPart2()
{
	for(int y = 1; y <= 13; y++)
	{
		for(int x = -3; x<=3; x++)
		{
			for(int z = -2; z<=2;z++)
			{
				if(y==1){
					if(x==0){
						if(z>=-1&&z<=1){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube();
							glPopMatrix();
						}
						if(z==2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(-90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
						if(z==-2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
					}
					if((x==1||x==-1)&&z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube();
						glPopMatrix();
					}
					if(x==-2&&z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						glRotatef(180,0.0f,1.0f,0.0f);
						drawCube02();
						glPopMatrix();
					}
					if(x==2&&z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube02();
						glPopMatrix();
					}
				}
				if(y>=2&&y<=4&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				if(y==5&&x==0){
					if(z>=-1&&z<=1){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube();
							glPopMatrix();
						}
						if(z==2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(-90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
						if(z==-2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
				}
				if(y==6&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube04();
					glPopMatrix();
				}
				if(y==7&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube03();
					glPopMatrix();
				}
				if(y==8&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				if(y==9&&x==0){
					if(z==-1||z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube();
						glPopMatrix();
					}
					if(z==-2){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						glRotatef(90,0.0f,1.0f,0.0f);
						drawCube02();
						glPopMatrix();
					}
				}
				if(y==10&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f-0.9f);
					drawCube06();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f+0.9f);
					drawCube06();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f-0.9f);
					drawCube06();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f+0.9f);
					drawCube06();
					glPopMatrix();
				}
				if(y==11&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f-0.5f,y*2.0f,z*2.0f+0.9f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f+0.5f);
					glRotatef(90,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();
	
					glPushMatrix();
					glTranslatef(x*2.0f+0.5f,y*2.0f,z*2.0f-0.9f);
					glRotatef(180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f-0.5f);
					glRotatef(270,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					//��
					glPushMatrix();
					glTranslatef(x*2.0f+0.5f,y*2.0f,z*2.0f+0.9f);
					glRotatef(180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f-0.5f);
					glRotatef(90+180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();
	
					glPushMatrix();
					glTranslatef(x*2.0f-0.5f,y*2.0f,z*2.0f-0.9f);
					glRotatef(180+180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f+0.5f);
					glRotatef(270+180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();
				}
				if(y==12&&z==0){
					if(x>=-2&&x<=2){
						if(x==0){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube05();
							glPopMatrix();
						}else{
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube();
							glPopMatrix();
						}
					}
					if(x==-3){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						glRotatef(180,0.0f,1.0f,0.0f);
						drawCube02();
						glPopMatrix();
					}
					if(x==3){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube02();
						glPopMatrix();
					}
				}
				if(y==13&&z==0){
					if(x>=-1&&x<=1){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube();
						glPopMatrix();
					}
				}
			}
		}
	}
}
//��part3
void drawPart3()
{
	int z=0;
	for(int x=-1;x<=1;x++)
	{
		for(int y=0; y<=3; y++)
		{
			if(x==-1&&y==0){
				glPushMatrix();
				glTranslatef(x*2.0f,y*2.0f,z*2.0f);
				glRotatef(180,0.0f,1.0f,0.0f);
				drawCube02();
				glPopMatrix();
			}
			if(x==1){
				if(y==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube02();
					glPopMatrix();
				}
				if(y==1||y==2){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				
			}
			if(x==0){
				if(y==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				if(y==2){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					glRotatef(90,0.0f,0.0f,1.0f);
					drawSolidTera();
					glPopMatrix();
				}
			}
		}
	}

}
//���Ǳ�
void drawCastle()
{
		//GLfloat material_ambient1[] = {0.3, 0.3, 0.3, 1.0};
		GLfloat material_ambient1[] = {0.5, 0.5, 0.5, 1.0};
		GLfloat material_diffuse1[] = {0.9, 0.9, 0.9, 1.0};
		GLfloat material_specular1[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess1 = 1.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient1);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse1);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular1);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess1);

	glPushMatrix();
	glTranslatef(-6*2,0.0f,0.0f);
	drawPart1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6*2,0.0f,0.0f);
	glRotatef(180,0.0f,1.0f,0.0f);
	drawPart1();
	glPopMatrix();

	glPushMatrix();
	drawPart2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3*2.0f,13*2.0f,0.0f);
	drawPart3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3*2.0f,13*2.0f,0.0f);
	glRotatef(180,0.0f,1.0f,0.0f);
	drawPart3();
	glPopMatrix();

}



//���Ǳ���Ӱ
void drawShadowCastle(){

		GLfloat material_ambient[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_diffuse[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_specular[] = {0.0, 0.0, 0.0, 1.0};
		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);

	glPushMatrix();
	glTranslatef(-6*2,0.0f,0.0f);
	drawPart1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6*2,0.0f,0.0f);
	glRotatef(180,0.0f,1.0f,0.0f);
	drawPart1();
	glPopMatrix();

	glPushMatrix();
	drawPart2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3*2.0f,13*2.0f,0.0f);
	drawPart3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3*2.0f,13*2.0f,0.0f);
	glRotatef(180,0.0f,1.0f,0.0f);
	drawPart3();
	glPopMatrix();
}
//������
void drawBackground()
{
	glScalef(1,1,1);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-80.0f,0.0f,-80.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(80.0f,0.0f,-80.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-80.0f,0.0f,80.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(80.0f,0.0f,80.0f);

	glTexCoord2f(1.0f,1.0f);glVertex3f(-80.0f,0.0f,-80.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(80.0f,0.0f,-80.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(80.0f,80.0f,-80.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-80.0f,80.0f,-80.0f);

	glPopMatrix();
}
//ƽ��
void translate(float temp = 1){
	pox-= 0.1*temp*cos(10*r1*Pi/180);
	poy+= 0.1*temp*sin(10*r1*Pi/180);
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

	glPushMatrix();
	//glTranslatef(0.0,0.0,-2.0f);
	glRotatef(2*u,0.0,1.0,0.0);
	glScalef(0.35,0.35,0.35);
	drawCastle();
	glPopMatrix();

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

//����λͼ
AUX_RGBImageRec *LoadBMP(char *Filename)    // ����λͼ�ļ������ƽ��м���
{
	FILE *File=NULL;        // �ļ�ָ��

	if (!Filename)         // ���û��ָ��λͼ�ļ����ƾͷ���NULL
	{
		 return NULL;         
	}

	fopen_s(&File,Filename,"r");       // ����ָ����λͼ�ļ����ƣ��򿪸�λͼ�ļ�


	if (File)           // ���λͼ�ļ�����
	{
		fclose(File);         // ��Ϊֻ����Ҫ�ж������Ƿ���ڣ�������Ҫ��λͼ�ļ�����д���������Թر�λͼ�ļ�
		return auxDIBImageLoad(Filename);   // ��ʵ��ֻ��Ҫһ���������ڵ�λͼ�ļ������ƣ�ʵ�ּ���λͼ�ļ���������һ��ָ��
	}

	return NULL;          // λͼ�ļ�����ʧ�ܾͷ���NULL
}

//��������&������
int LoadGLTextures()         // ���ݼ��ص�λͼ��������
{
	int Status=FALSE;         // ָʾ�������Ƿ�ɹ��ı�־

	AUX_RGBImageRec *TextureImage[6];     // ����һ������ͼ�����飬����ָ�������СΪ6

	memset(TextureImage,0,sizeof(void *)*6);          // ��ʼ������ͼ�����飬Ϊ������ڴ�

	char *pictures[] = {// ����һ��λͼ�������飬��Ӧ6��λͼ
		"Data/No1.bmp",
		"Data/No2.bmp",
		"Data/No3.bmp",
		"Data/No4.bmp",
		"Data/No5.bmp",
		"Data/No6.bmp"
	};
	for(int i=0; i<6; i++)// ����λͼ�������飬����λͼ���Ʒֱ�����
	{
		if (TextureImage[i]=LoadBMP(pictures[i]))// ����λͼi�ɹ����޸�״̬��־����StatusΪTRUE
	   {
			Status=TRUE;        

			glGenTextures(1, &texture[i]);     // Ϊ��i��λͼ��������
			glBindTexture(GL_TEXTURE_2D, texture[i]);// �����ɵ���������ư󶨵�ָ����������
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[i]->sizeX, TextureImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[i]->data);

	   }

	   if (TextureImage[i])         // �ͷ�λͼ����ռ�õ��ڴ�ռ�
	   {
			if (TextureImage[i]->data)       
			{
				 free(TextureImage[i]->data);    
			}

			free(TextureImage[i]);        
	   }
	}
	return Status;          // �����������أ����سɹ�����ʧ�ܵı�־Status
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

//���ص�
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		r3 += 1;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		s3 += 1;
	myDisplay();
}

//���ɹ켣�ƶ�
void idlefunc()
{
	if(iMore < 200 )
	{
		iMore += 1;
		glutPostRedisplay();
		::Sleep(5);
	}
	else
		iMore = 0;
}
//���̻ص�
void mykey(unsigned char key, int x, int y)
{
	//��ѻA
	if(key == 'Q'|| key == 'q') //ƽ��
		translate();
	if(key == 'Z'|| key == 'z') //ƽ��
		translate();
	if(key == 'A'|| key == 'a')//�Ŵ�
		s1 += 1;
	if(key == 'S'|| key == 's')//��С
		s1 -= 1;
	if(key == 'E'|| key == 'e')//��ת
		r1 += 1;
	if(key == 'X'|| key == 'x')//��ת
		r1 -= 1;

	//��ѻB
	if(key == 'P'|| key == 'p') //ƽ��
		t2 += 1;
	if(key == 'M'|| key == 'm') //ƽ��
		t2 -= 1;
	if(key == 'K'|| key == 'k')//�Ŵ�
		s2 += 1;
	if(key == 'L'|| key == 'l')//��С
		s2 -= 1;
	if(key == 'O'|| key == 'o')//��ת
		r2 += 1;
	if(key == 'N'|| key == 'n')//��ת
		r2 -= 1;

	//��Դ
	if(key == 'F'|| key == 'f') //x-
		lx -=0.2;
	if(key == 'H'|| key == 'h') //x+
		lx +=0.2;
	if(key == 'V'|| key == 'v')//z-
		lz -=0.2;
	if(key == 'B'|| key == 'b')//z+
		lz +=0.2;
	if(key == 'Y'|| key == 'y')//y+
		ly +=0.2;
	if(key == 'G'|| key == 'g')//y-
		ly -=0.2;
	
	//�Ǳ�
	if(key == 'U'|| key == 'u')//y-
			u +=1;


	//�ı�۲���λ��
	if(key == '1') //��
		ey[view] += 0.05f;
	if(key == '2') //��
		ey[view] -= 0.05f;
	if(key == '3') //��
		ex[view] -= 0.05f;
	if(key == '4') //��
		ex[view] += 0.05f;
	if(key == '5') //ǰ
		ez[view] += 0.05f;
	if(key == '6') //��
		ez[view] -= 0.05f;

	//�ı�۲����λ��
	if(key == '7') //��
		fy[view] += 0.05f;
	if(key == '8') //��
		fy[view] -= 0.05f;
	if(key == '9') //��
		fx[view] -= 0.05f;
	if(key == '0') //��
		fx[view] += 0.05f;

	//�������ɹ켣�ƶ�
	if(key=='T'||key=='t'){
		iMore=0;
		glutIdleFunc(idlefunc);
	}
	glutPostRedisplay();
}

//�˵�
void mymenu(int id)
{
	if(id == 1) //���ͼ��
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
	}
	if(id == 2) //��ԭ
	{
		glClear(GL_COLOR_BUFFER_BIT);
		t1 = 1;
		r1 = 0;
		s1 = 3;
		t2 = 1;
		r2 = 0;
		s2 = 3;
		t3 = 0;
		r3 = 0;
		s3 = 1;
		GLfloat ex[3] = {-1.0, 0.0, 0.0}; //�۲���λ��
		GLfloat ey[3] = {1.0, 0.0, 0.0};
		GLfloat ez[3] = {2.0, 2.0, 2.0};
		GLfloat fx[3] = {0.0, 0.0, 0.0}; //�۲����λ��
		GLfloat fy[3] = {1.0, 1.0, 1.0};
		GLfloat fz[3] = {0.0, 0.0, 0.0};
		glutPostRedisplay();
	}
}

void setLight(){

		light_position[0] = lx;
		light_position[1] = ly;
		light_position[2] = lz;

	
	//���ù�Դ����
		//GLfloat light_ambient[] = {0.1, 0.1, 0.1, 1.0};//û�л�����
		GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};//û�л�����
		GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0}; //���淴��Ϊ��ɫ
		GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0}; // ������Ϊ��ɫ
		GLfloat spot_direction[] = {spot_directionx,spot_directiony,spot_directionz};//�۹ⷽ��


	//�ö���õĹ�Դ���Ը�ָ����ԴGL_LIGHT0��������
		glLightfv(GL_LIGHT0 , GL_AMBIENT , light_ambient);
		glLightfv(GL_LIGHT0 , GL_DIFFUSE , light_diffuse);
		glLightfv(GL_LIGHT0 , GL_SPECULAR , light_specular);
		glLightfv(GL_LIGHT0 , GL_POSITION , light_position);
		glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spot_direction);
	
	glEnable(GL_LIGHTING); // ����������Ⱦ
	glEnable(GL_LIGHT0);//�������õĹ�ԴGL_LIGHT0

	
}

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
//Merry Christmas