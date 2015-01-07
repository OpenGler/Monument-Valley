#include "main.h"

//����ѻB
void drawBirdB()
{
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

	//����֫
	glPushMatrix();
	glTranslatef(-R1,R1,0);
	glRotatef(-20*mi1, 0.0, 0.0, 1.0);
	glTranslatef(R1,-R1,0);
	//����
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(-R1,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//�ҽ�
	glPushMatrix();
	glTranslatef(-R1,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	//����֫
	glPushMatrix();
	glTranslatef(-R1,R1,0);
	glRotatef(-20*mi2, 0.0, 0.0, 1.0);
	glTranslatef(R1,-R1,0);
	//����
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(-R1,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//���
	glPushMatrix();
	glTranslatef(-R1,0,0);
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-10*R4,0,2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)+2*R4);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
