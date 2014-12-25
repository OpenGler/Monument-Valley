#pragma comment(lib, "glaux.lib")
#include <gl\glaux.h>
#include <TCHAR.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <gl\glut.h>


	GLuint texture[6];// 创建一个全局的纹理数组，用来存储将位图转换之后得到的纹理，对应于立方体的6个面
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

	//设置轨迹参数
	GLfloat theta = 0.5f;
	GLfloat t = 0.0f;
	unsigned int iMore = 0;

	GLint view = 0;
	GLfloat ex[3] = {-5, -5, -5}; //观察者位置
	GLfloat ey[3] = {10.0, 10.0, 10.0};
	GLfloat ez[3] = {10.0, 10.0, 10.0};
	GLfloat fx[3] = {0.0, 0.0, 0.0}; //观察对象位置
	GLfloat fy[3] = {5.0, 5.0, 5.0};
	GLfloat fz[3] = {0.0, 0.0, 0.0};
	GLint flag;
	//指定光源的位置
	GLfloat light_position[] = { lx,ly,lz,0.0 };
	static float spot_directionx=0.0,spot_directiony=0.0,spot_directionz=0.0;//设置聚光方向
	void setLight();

//画法向量
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
//画乌鸦A
void drawBirdA()
{
	//glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT, GL_AMBIENT);
	//设置材料属性
		GLfloat material_ambient1[] = {0.1, 0.1, 0.1, 1.0};
		GLfloat material_diffuse1[] = {0.5, 0.5, 0.5, 1.0};
		GLfloat material_specular1[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess1 = 1.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient1);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse1);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular1);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess1);

	//头
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//嘴巴上
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

	//嘴巴下
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

	//眼睛左
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,R1);
	glScalef(1, 1, 0.15);
	glutSolidSphere(R2,100,100);
	glPopMatrix();

			//设置材料属性
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

	//眼睛右
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

	//身子
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//右腿
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//左腿
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//右脚
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//左脚
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

	//设置材料属性
		GLfloat material_ambient[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_diffuse[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_specular[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_shininess = 1.0;

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);
		glMaterialf( GL_FRONT, GL_SHININESS, material_shininess);

		//头
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//嘴巴上
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i <= n/2; i++)
			glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
	glEnd();
	glPopMatrix();

	//嘴巴下
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i < n/2; i++){
			glVertex3f(0.0f,-1*R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
		}
	glEnd();
	glPopMatrix();

	//眼睛左
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

	//眼睛右
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

	//身子
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//右腿
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//左腿
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//右脚
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//左脚
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(-10*R4,0,2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)+2*R4);
	glEnd();
	glPopMatrix();


}

//画乌鸦B
void drawBirdB()
{
	//变换
	glTranslatef(1,0.0,0.0);
	glTranslatef(-0.1*t2,0.0,0.0);
	glRotatef(10*r2,0.0,1.0,0.0);
	glScalef(0.2*s2,0.2*s2,0.2*s2);

	//头
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,5*R1,0);
	glutSolidSphere(R1,100,100);
	glPopMatrix();

	//嘴巴上
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i <= n/2; i++)
			glVertex3f(0.0f,R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
	glEnd();
	glPopMatrix();

	//嘴巴下
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-3*R1,5*R1,0.0f);
		for(int i = 0; i < n/2; i++){
			glVertex3f(0.0f,-1*R1*sin(2*Pi/n*i)+5*R1, R1*cos(2*Pi/n*i));
		}
	glEnd();
	glPopMatrix();

	//眼睛左
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
	//眼睛右
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

	//身子
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,R1,0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(R1,3*R1,100,100);
	glPopMatrix();

	//右腿
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,R1,-2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj *objCylinder = gluNewQuadric();
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();
	//左腿
	glPushMatrix();
	glColor3f(0.0f,1.0f,1.0f);
	glTranslatef(0,R1,2*R4);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(objCylinder, R4, R4, R1, 32, 5);
	glPopMatrix();

	//右脚
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-10*R4,0,-2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)-2*R4);
	glEnd();
	glPopMatrix();
	//左脚
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f,1.0f,1.0f);
		glVertex3f(-10*R4,0,2*R4);
		for(int i = 0; i < n/2; i++)
			glVertex3f(0,2*R4*sin(2*Pi/n*i), 2*R4*cos(2*Pi/n*i)+2*R4);
	glEnd();
	glPopMatrix();
}

//画太阳
void drawSun(){
			//设置材料属性
		GLfloat material_ambient[] = {0.1, 0.1, 0.1, 1.0};
		GLfloat material_diffuse[] = {0.0, 0.0, 0.0, 1.0};
		GLfloat material_specular[] = {0.0, 0.0, 0.0, 1.0};

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);

	//变换
	glMatrixMode(GL_MODELVIEW);//当前为模型视景矩阵

	glPushMatrix();
	glutSolidSphere(0.05,1000,1000);
	glPopMatrix();
} 

//画坐标系
void drawCoordinateSystem()
{
	//变换
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


//绘制cube
void drawCube(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第一个纹理texture[0]，进行贴纹理
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//画点
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第二个纹理texture[1]，进行贴纹理
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//设置法向量
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第三个纹理texture[2]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//设置法向量
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第四个纹理texture[3]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//设置法向量
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第五个纹理texture[4]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第六个纹理texture[5]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//绘制cube(有回形纹理的)
void drawCube01(GLvoid)         
{
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   选择第一个纹理texture[0]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};
	//设置法向量
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   选择第二个纹理texture[1]，进行贴纹理
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};

	//设置法向量
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    
	glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第三个纹理texture[2]，进行贴纹理
	glBegin(GL_QUADS);
    GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第四个纹理texture[3]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	 //设置法向量
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
   
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   选择第五个纹理texture[4]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   选择第六个纹理texture[5]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}
//绘制cube(有三角的)
void drawCube02(GLvoid)         
{
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第一个纹理texture[0]，进行贴纹理
	glBegin(GL_POLYGON);
	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {-0.9f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 0.9f, 1.0f};

	//设置法向量
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第二个纹理texture[1]，进行贴纹理
	glBegin(GL_POLYGON);
    GLfloat tex1v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 0.9f, -1.0f};
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 0.9f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.0f, -0.9f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.0f, -1.0f, -1.0f);
    //设置法向量
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第三个纹理texture[2]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, 1.0f};
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    //设置法向量
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第四个纹理texture[3]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = { -0.9f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = { -0.9f, -1.0f, 1.0f};
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( -0.9f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -0.9f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    //设置法向量
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第五个纹理texture[4]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, 0.9f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 0.9f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 0.9f, 1.0f);
    //设置法向量
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第六个纹理texture[5]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    //设置法向量
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);
	glEnd(); 

	// 斜面 Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第六个纹理texture[5]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex6v1[3] = {1.0f, 0.9f, -1.0f};
	GLfloat tex6v2[3] = {1.0f, 0.9f, 1.0f};
	GLfloat tex6v3[3] = {-1.0f, -0.9f, 1.0f};
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 0.9f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.9f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -0.9f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -0.9f, -1.0f);
    //设置法向量
	GLfloat tex6normal[3];
    norm(tex6v1,tex6v2,tex6v3,tex6normal);
	glNormal3f(tex6normal[0],tex6normal[1],tex6normal[2]);
	glEnd(); 

}
//绘制cube(门上)
void drawCube03(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[3]);//   选择第一个纹理texture[0]，进行贴纹理
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//画点
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第二个纹理texture[1]，进行贴纹理
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//设置法向量
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第三个纹理texture[2]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//设置法向量
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第四个纹理texture[3]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//设置法向量
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第五个纹理texture[4]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第六个纹理texture[5]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//绘制cube（门下）
void drawCube04(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[4]);//   选择第一个纹理texture[0]，进行贴纹理
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//画点
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第二个纹理texture[1]，进行贴纹理
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//设置法向量
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第三个纹理texture[2]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//设置法向量
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第四个纹理texture[3]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//设置法向量
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第五个纹理texture[4]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第六个纹理texture[5]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//绘制cube（圆环）
void drawCube05(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[5]);//   选择第一个纹理texture[0]，进行贴纹理
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//画点
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
	glBindTexture(GL_TEXTURE_2D, texture[5]);//   选择第二个纹理texture[1]，进行贴纹理
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//设置法向量
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第三个纹理texture[2]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//设置法向量
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第四个纹理texture[3]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//设置法向量
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第五个纹理texture[4]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   选择第六个纹理texture[5]，进行贴纹理
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//设置法向量
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//绘制cube(细棱柱)
void drawCube06(GLvoid)         
{       
	glPushMatrix();
	glScalef(0.1,2,0.1);
	glTranslatef(0.0f,0.5f,0.0f);
	drawCube();
	glPopMatrix();    
}

//绘制cube（扁三棱柱）
void drawCube07(GLvoid)         
{     	
	glPushMatrix();
	glScalef(0.5,0.5,0.1);
	glTranslatef(0.0f,1.0f,0.0f);
	drawCube02();
	glPopMatrix();      
	       
}

//画实心四棱锥
void drawSolidTera()
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_TRIANGLES);

		/*前正面的绘制*/
	    GLfloat tex0v1[3] = {0.0,1,0.0};
		GLfloat tex0v2[3] = {-1,-1,1};
		GLfloat tex0v3[3] = {-1,-1,1};
		//设置法向量
		GLfloat tex0normal[3];
		norm(tex0v1,tex0v2,tex0v3,tex0normal);
		glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-1,-1,1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(1,-1,1);
	      

		/*右侧面的绘制*/
		GLfloat tex1v1[3] = {0.0,1,0.0};
		GLfloat tex1v2[3] = {1,-1,1};
		GLfloat tex1v3[3] = {1,-1,-1};
		//设置法向量
		GLfloat tex1normal[3];
		norm(tex1v1,tex1v2,tex1v3,tex1normal);
		glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(1,-1,1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(1,-1,-1);
		
		
		/*后侧面的绘制*/
		GLfloat tex2v1[3] = {0.0,1.0,0.0};
		GLfloat tex2v2[3] = {1.0,-1.0,-1.0};
		GLfloat tex2v3[3] = {-1.0,-1.0,-1.0};
		//设置法向量
		GLfloat tex2normal[3];
		norm(tex2v1,tex2v2,tex2v3,tex2normal);
		glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1.0,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0,-1.0,-1.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-1.0,-1.0,-1.0);
		
		//glEnd();

		
		/*左侧面的绘制*/
		GLfloat tex3v1[3] = {0.0,1.0,0.0};
		GLfloat tex3v2[3] = {-1.0,-1.0,-1.0};
		GLfloat tex3v3[3] = {-1.0,-1.0,1.0};
		//设置法向量
		GLfloat tex3normal[3];
		norm(tex3v1,tex3v2,tex3v3,tex3normal);
		glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1.0,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-1.0,-1.0,-1.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-1.0,-1.0,1.0);
        

	glEnd();
	glPopMatrix();
}

//画空心四棱锥
void drawWireTera()
{

}

//画part1
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
//画part2
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

					//反
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
//画part3
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
//画城堡
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



//画城堡阴影
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
//画背景
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
//平移
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
	
	glMatrixMode(GL_MODELVIEW);//当前为投影矩阵
	glLoadIdentity();
	//glFrustum(-1,1,-1,1,1.0f,10000.0f);//视景体
	gluLookAt(ex[view],ey[view],ez[view],
		fx[view],fy[view],fz[view],
		0.0,1.0,0.0);//视点转换
	

	glPushMatrix();
	drawCoordinateSystem();
	glPopMatrix();

	//glPushMatrix();
	////坐标变换
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

	GLfloat m[16];//课件上的
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

//加载位图
AUX_RGBImageRec *LoadBMP(char *Filename)    // 根据位图文件的名称进行加载
{
	FILE *File=NULL;        // 文件指针

	if (!Filename)         // 如果没有指定位图文件名称就返回NULL
	{
		 return NULL;         
	}

	fopen_s(&File,Filename,"r");       // 根据指定的位图文件名称，打开该位图文件


	if (File)           // 如果位图文件存在
	{
		fclose(File);         // 因为只是需要判断问题是否存在，而不需要对位图文件进行写操作，所以关闭位图文件
		return auxDIBImageLoad(Filename);   // 其实，只需要一个真正存在的位图文件的名称，实现加载位图文件，并返回一个指针
	}

	return NULL;          // 位图文件加载失败就返回NULL
}

//创建纹理&绑定纹理
int LoadGLTextures()         // 根据加载的位图创建纹理
{
	int Status=FALSE;         // 指示纹理创建是否成功的标志

	AUX_RGBImageRec *TextureImage[6];     // 创建一个纹理图像数组，这里指定数组大小为6

	memset(TextureImage,0,sizeof(void *)*6);          // 初始化纹理图像数组，为其分配内存

	char *pictures[] = {// 创建一个位图名称数组，对应6幅位图
		"Data/No1.bmp",
		"Data/No2.bmp",
		"Data/No3.bmp",
		"Data/No4.bmp",
		"Data/No5.bmp",
		"Data/No6.bmp"
	};
	for(int i=0; i<6; i++)// 遍历位图名称数组，根据位图名称分别生成
	{
		if (TextureImage[i]=LoadBMP(pictures[i]))// 加载位图i成功，修改状态标志变量Status为TRUE
	   {
			Status=TRUE;        

			glGenTextures(1, &texture[i]);     // 为第i个位图创建纹理
			glBindTexture(GL_TEXTURE_2D, texture[i]);// 将生成的纹理的名称绑定到指定的纹理上
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[i]->sizeX, TextureImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[i]->data);

	   }

	   if (TextureImage[i])         // 释放位图数组占用的内存空间
	   {
			if (TextureImage[i]->data)       
			{
				 free(TextureImage[i]->data);    
			}

			free(TextureImage[i]);        
	   }
	}
	return Status;          // 创建纹理并加载，返回成功或者失败的标志Status
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
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_COLOR_MATERIAL);
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

//鼠标回调
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		r3 += 1;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		s3 += 1;
	myDisplay();
}

//自由轨迹移动
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
//键盘回调
void mykey(unsigned char key, int x, int y)
{
	//乌鸦A
	if(key == 'Q'|| key == 'q') //平移
		translate();
	if(key == 'Z'|| key == 'z') //平移
		translate();
	if(key == 'A'|| key == 'a')//放大
		s1 += 1;
	if(key == 'S'|| key == 's')//缩小
		s1 -= 1;
	if(key == 'E'|| key == 'e')//旋转
		r1 += 1;
	if(key == 'X'|| key == 'x')//旋转
		r1 -= 1;

	//乌鸦B
	if(key == 'P'|| key == 'p') //平移
		t2 += 1;
	if(key == 'M'|| key == 'm') //平移
		t2 -= 1;
	if(key == 'K'|| key == 'k')//放大
		s2 += 1;
	if(key == 'L'|| key == 'l')//缩小
		s2 -= 1;
	if(key == 'O'|| key == 'o')//旋转
		r2 += 1;
	if(key == 'N'|| key == 'n')//旋转
		r2 -= 1;

	//光源
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
	
	//城堡
	if(key == 'U'|| key == 'u')//y-
			u +=1;


	//改变观察者位置
	if(key == '1') //上
		ey[view] += 0.05f;
	if(key == '2') //下
		ey[view] -= 0.05f;
	if(key == '3') //左
		ex[view] -= 0.05f;
	if(key == '4') //右
		ex[view] += 0.05f;
	if(key == '5') //前
		ez[view] += 0.05f;
	if(key == '6') //后
		ez[view] -= 0.05f;

	//改变观察对象位置
	if(key == '7') //上
		fy[view] += 0.05f;
	if(key == '8') //下
		fy[view] -= 0.05f;
	if(key == '9') //左
		fx[view] -= 0.05f;
	if(key == '0') //右
		fx[view] += 0.05f;

	//控制自由轨迹移动
	if(key=='T'||key=='t'){
		iMore=0;
		glutIdleFunc(idlefunc);
	}
	glutPostRedisplay();
}

//菜单
void mymenu(int id)
{
	if(id == 1) //清除图像
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glutSwapBuffers();
	}
	if(id == 2) //还原
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
		GLfloat ex[3] = {-1.0, 0.0, 0.0}; //观察者位置
		GLfloat ey[3] = {1.0, 0.0, 0.0};
		GLfloat ez[3] = {2.0, 2.0, 2.0};
		GLfloat fx[3] = {0.0, 0.0, 0.0}; //观察对象位置
		GLfloat fy[3] = {1.0, 1.0, 1.0};
		GLfloat fz[3] = {0.0, 0.0, 0.0};
		glutPostRedisplay();
	}
}

void setLight(){

		light_position[0] = lx;
		light_position[1] = ly;
		light_position[2] = lz;

	
	//设置光源属性
		//GLfloat light_ambient[] = {0.1, 0.1, 0.1, 1.0};//没有环境光
		GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};//没有环境光
		GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0}; //镜面反射为白色
		GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0}; // 漫反射为白色
		GLfloat spot_direction[] = {spot_directionx,spot_directiony,spot_directionz};//聚光方向


	//用定义好的光源属性给指定光源GL_LIGHT0进行设置
		glLightfv(GL_LIGHT0 , GL_AMBIENT , light_ambient);
		glLightfv(GL_LIGHT0 , GL_DIFFUSE , light_diffuse);
		glLightfv(GL_LIGHT0 , GL_SPECULAR , light_specular);
		glLightfv(GL_LIGHT0 , GL_POSITION , light_position);
		glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,spot_direction);
	
	glEnable(GL_LIGHTING); // 开启光照渲染
	glEnable(GL_LIGHT0);//开启设置的光源GL_LIGHT0

	
}

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
//Merry Christmas