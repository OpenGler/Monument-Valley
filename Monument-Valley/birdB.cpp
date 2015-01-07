#include "main.h"

//»­ÎÚÑ»B
void drawBirdB()
{
	materialLight2();

	//Í·
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//×ì°ÍÉÏ
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.0f,1.0f,1.0f);
		//glVertex3f(-3*R1,5*R1,0.0f);
		//for(int i = 0; i <= n/2; i++)
		//	glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));

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

	//×ì°ÍÏÂ
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		/*glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i < n/2; i++){
			glVertex3f(0.0f,-1*R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
		}*/
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

	//ÑÛ¾¦×ó
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

	//ÉèÖÃ²ÄÁÏÊôÐÔ
	materialLight3();

	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();

	materialLight2();


	//ÑÛ¾¦ÓÒ
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

	materialLight3();

	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,-R1);
	glScalef(1, 1, 0.25);
	glutSolidSphere(R3,100,100);
	glPopMatrix();

	materialLight2();

	//Éí×Ó
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//ÓÒÏÂÖ«
	glPushMatrix();
	glTranslatef(-R1,R1,0);
	glRotatef(-20*mi1, 0.0, 0.0, 1.0);
	glTranslatef(R1,-R1,0);
	//ÓÒÍÈ
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(-R1,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//ÓÒ½Å
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

	//×óÏÂÖ«
	glPushMatrix();
	glTranslatef(-R1,R1,0);
	glRotatef(-20*mi2, 0.0, 0.0, 1.0);
	glTranslatef(R1,-R1,0);
	//×óÍÈ
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(-R1,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//×ó½Å
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
