#include "main.h"

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

//画太阳
void drawSun()
{
			//设置材料属性
		GLfloat material_ambient[] = {0.5, 0.5, 0.02, 1.0};
		GLfloat material_diffuse[] = {0.6, 0.5, 0.0, 1.0};
		GLfloat material_specular[] = {0.4, 0.4, 0.0, 1.0};

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);

	//变换
	glMatrixMode(GL_MODELVIEW);//当前为模型视景矩阵

	glPushMatrix();
	glutSolidSphere(0.05,1000,1000);
	glPopMatrix();
} 
