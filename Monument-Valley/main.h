#ifndef MAIN_H
#define MAIN_H

#pragma warning(disable:4819)
#pragma comment(lib, "glaux.lib")
#include <gl\glaux.h>
#include <TCHAR.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <gl\glut.h>


/*--------------------------------------------ȫ�ֱ�������(�ϱ߽�)---------------------------------------------*/

	extern GLuint texture[];// ����һ��ȫ�ֵ��������飬�����洢��λͼת��֮��õ���������Ӧ���������6����
	extern int u;

	const int n = 500;
	const GLfloat R1 = 0.1f;
	const GLfloat R2 = 0.09f;
	const GLfloat R3 = 0.075f;
	const GLfloat R4 = 0.006f;
	const GLfloat Pi = 3.1415926537f;
	extern int walk1[];
	extern int walk2[];
	extern int walk3[];
	extern int walk4[];

	extern int wa1;
	extern int wa2;
	extern int wb1;
	extern int wb2;
	extern int mb;//birdB�ȶ�
	extern int mi1;
	extern int mi2;

	extern int t1, r1, s1;
	extern int t2, r2, s2;
	extern int t3, r3, s3;

	extern int ax, ay, az;
	extern float lx, ly, lz;
	extern float pox, poy, poz;

	//���ù켣����
	extern GLfloat theta;
	extern GLfloat t;
	extern unsigned int iMore;
	extern int HierParam;
	extern int Animation;

	extern GLint view;
	extern GLfloat ex[]; //�۲���λ��
	extern GLfloat ey[];
	extern GLfloat ez[];
	extern GLfloat fx[]; //�۲����λ��
	extern GLfloat fy[];
	extern GLfloat fz[];
	extern GLint flag;
	
	extern GLfloat light_position[];//ָ����Դ��λ��
	extern float spot_directionx,spot_directiony,spot_directionz;//���þ۹ⷽ��
/*--------------------------------------------ȫ�ֱ��������±߽磩---------------------------------------------*/




/*--------------------------------------------getNormAndTranslate.cpp---------------------------------------------*/
void norm(GLfloat v1[3], GLfloat v2[3], GLfloat v3[3], GLfloat *nor );//��������
void translate(float =1);//ƽ��




/*--------------------------------------------birdA.cpp-----------------------------------------------*/
void drawBirdA();//��ѻ��״
void drawShadowBirdA();//��ѻ��Ӱ



/*--------------------------------------------birdB.cpp-----------------------------------------------*/
void drawBirdB();//��ѻ��״
void drawShadowBirdB();//��ѻ��Ӱ



/*-------------------------------------------castle.cpp------------------------------------------*/
void drawPart1();//��part1
void drawPart2();//��part2
void drawPart3();//��part3
void drawCastle();//���Ǳ�



/*--------------------------------------------cube.cpp------------------------------------------------*/
void drawCube(GLvoid);//����cube
void drawCube01(GLvoid);//����cube(�л��������)
void drawCube02(GLvoid);//����cube(�����ǵ�)
void drawCube03(GLvoid);//����cube(����)
void drawCube04(GLvoid);//����cube�����£�
void drawCube05(GLvoid);//����cube��Բ����
void drawCube06(GLvoid);//����cube(ϸ����)
void drawCube07(GLvoid);//����cube������������
void drawSolidTera();//��ʵ������׶



/*-------------------------------------------commandAndAction.cpp-------------------------------------*/
void mouse(int, int, int, int);//���ص�
void mykey(unsigned char, int, int);//���̻ص�
void mymenu(int);//�˵�
void idlefunc();//���ɹ켣�ƶ�
void funcOfB();//birdB�ȶ�



/*-------------------------------------------texturesAndEnviro.cpp------------------------------------*/
int LoadGLTextures();//��������&������
AUX_RGBImageRec *LoadBMP(char*);//����λͼ
void drawBackground();//������
void drawCoordinateSystem();//������ϵ
void materialLight1();//��������趨1    ���Ǳ��ͻ����Ĳ����趨
void materialLight2();//��������趨2	 ����ѻ�Ĳ����趨




/*-------------------------------------------sunAndLight.cpp------------------------------------------*/
void drawSun();//��̫��
void setLight();



/*--------------------------------------------main.cpp------------------------------------------------*/
void init();//��ʼ��
void myDisplay();
void reshape(int,int);
void assign();//��ȫ�ֱ�������ֵ
int main(int argc, char *argv[]);//������

#endif