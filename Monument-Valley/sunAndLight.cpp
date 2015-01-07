#include "main.h"

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

//��̫��
void drawSun()
{
			//���ò�������
		GLfloat material_ambient[] = {0.5, 0.5, 0.02, 1.0};
		GLfloat material_diffuse[] = {0.6, 0.5, 0.0, 1.0};
		GLfloat material_specular[] = {0.4, 0.4, 0.0, 1.0};

		glMaterialfv( GL_FRONT, GL_AMBIENT, material_ambient);
		glMaterialfv( GL_FRONT, GL_DIFFUSE, material_diffuse);
		glMaterialfv( GL_FRONT, GL_SPECULAR, material_specular);

	//�任
	glMatrixMode(GL_MODELVIEW);//��ǰΪģ���Ӿ�����

	glPushMatrix();
	glutSolidSphere(0.05,1000,1000);
	glPopMatrix();
} 
