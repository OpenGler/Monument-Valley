#include "main.h"

void drawBirdA()
{
	//glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT, GL_AMBIENT);
	//…Ë÷√≤ƒ¡œ Ù–‘
		GLfloat material_ambient1[] = {0.1, 0.1, 0.1, 1.0};
		GLfloat material_diffuse1[] = {0.5, 0.5, 0.5, 1.0};
		GLfloat material_specular1[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess1 = 1.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient1);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse1);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular1);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess1);

	//Õ∑
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//◊Ï∞Õ…œ
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

	//◊Ï∞Õœ¬
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

	//—€æ¶◊Û
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

			//…Ë÷√≤ƒ¡œ Ù–‘
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

	//—€æ¶”“
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

	//…Ì◊”
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//”“Õ»
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//◊ÛÕ»
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//”“Ω≈
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//◊ÛΩ≈
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

	//…Ë÷√≤ƒ¡œ Ù–‘
		GLfloat material_ambient[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_diffuse[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_specular[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess = 1.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess);

		//Õ∑
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//◊Ï∞Õ…œ
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i <= n/2; i++)
			glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
	glEnd();
	glPopMatrix();

	//◊Ï∞Õœ¬
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i < n/2; i++){
			glVertex3f(0.0f,-1*R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
		}
	glEnd();
	glPopMatrix();

	//—€æ¶◊Û
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

	//—€æ¶”“
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

	//…Ì◊”
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//”“Õ»
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//◊ÛÕ»
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//”“Ω≈
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//◊ÛΩ≈
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)+2*R4);
	glEnd();
	glPopMatrix();


}
