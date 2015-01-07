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


/*--------------------------------------------全局变量区域(上边界)---------------------------------------------*/

	extern GLuint texture[];// 创建一个全局的纹理数组，用来存储将位图转换之后得到的纹理，对应于立方体的6个面
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
	extern int mb;//birdB腿动
	extern int mi1;
	extern int mi2;

	extern int t1, r1, s1;
	extern int t2, r2, s2;
	extern int t3, r3, s3;

	extern int ax, ay, az;
	extern float lx, ly, lz;
	extern float pox, poy, poz;

	//设置轨迹参数
	extern GLfloat theta;
	extern GLfloat t;
	extern unsigned int iMore;
	extern int HierParam;
	extern int Animation;

	extern GLint view;
	extern GLfloat ex[]; //观察者位置
	extern GLfloat ey[];
	extern GLfloat ez[];
	extern GLfloat fx[]; //观察对象位置
	extern GLfloat fy[];
	extern GLfloat fz[];
	extern GLint flag;
	
	extern GLfloat light_position[];//指定光源的位置
	extern float spot_directionx,spot_directiony,spot_directionz;//设置聚光方向
/*--------------------------------------------全局变量区域（下边界）---------------------------------------------*/




/*--------------------------------------------getNormAndTranslate.cpp---------------------------------------------*/
void norm(GLfloat v1[3], GLfloat v2[3], GLfloat v3[3], GLfloat *nor );//画法向量
void translate(float =1);//平移




/*--------------------------------------------birdA.cpp-----------------------------------------------*/
void drawBirdA();//乌鸦形状
void drawShadowBirdA();//乌鸦阴影



/*--------------------------------------------birdB.cpp-----------------------------------------------*/
void drawBirdB();//乌鸦形状
void drawShadowBirdB();//乌鸦阴影



/*-------------------------------------------castle.cpp------------------------------------------*/
void drawPart1();//画part1
void drawPart2();//画part2
void drawPart3();//画part3
void drawCastle();//画城堡



/*--------------------------------------------cube.cpp------------------------------------------------*/
void drawCube(GLvoid);//绘制cube
void drawCube01(GLvoid);//绘制cube(有回形纹理的)
void drawCube02(GLvoid);//绘制cube(有三角的)
void drawCube03(GLvoid);//绘制cube(门上)
void drawCube04(GLvoid);//绘制cube（门下）
void drawCube05(GLvoid);//绘制cube（圆环）
void drawCube06(GLvoid);//绘制cube(细棱柱)
void drawCube07(GLvoid);//绘制cube（扁三棱柱）
void drawSolidTera();//画实心四棱锥



/*-------------------------------------------commandAndAction.cpp-------------------------------------*/
void mouse(int, int, int, int);//鼠标回调
void mykey(unsigned char, int, int);//键盘回调
void mymenu(int);//菜单
void idlefunc();//自由轨迹移动
void funcOfB();//birdB腿动



/*-------------------------------------------texturesAndEnviro.cpp------------------------------------*/
int LoadGLTextures();//创建纹理&绑定纹理
AUX_RGBImageRec *LoadBMP(char*);//加载位图
void drawBackground();//画背景
void drawCoordinateSystem();//画坐标系
void materialLight1();//物体材料设定1    给城堡和环境的材料设定
void materialLight2();//物体材料设定2	 给乌鸦的材料设定




/*-------------------------------------------sunAndLight.cpp------------------------------------------*/
void drawSun();//画太阳
void setLight();



/*--------------------------------------------main.cpp------------------------------------------------*/
void init();//初始化
void myDisplay();
void reshape(int,int);
void assign();//给全局变量赋初值
int main(int argc, char *argv[]);//主函数

#endif