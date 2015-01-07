#include "main.h"

//鼠标回调
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		r3 += 1;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		s3 += 1;
	myDisplay();
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
	//层次建模移动
	if(key == 'C'|| key == 'c'){
			HierParam+=90;
			u += 90;
	}
	if(key == 'W'|| key == 'w'){
			Animation=0;
	}


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

		u = 1;//城堡旋转
		t1 = 1;r1 = 0;s1 = 5;//birdA
		t2 = 1;r2 = 0;s2 = 3;//birdB
		t3 = 0;r3 = 0;s3 = 1;//

		//光照
		ax = 0;ay = 0;az = 0;
		lx =0.5;ly =11;lz =5;
		pox = 0.0;poy = 0.0;poz = 0.0;

		//照相机位置
		ex[0] = -1;
		ey[0] = 11.0;
		ez[0] = 8.0;

		//观察对象位置
		fx[0] = 0.0;
		fy[0] = 7.0;
		fz[0] = 0.0;
		
		glutPostRedisplay();
	}
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