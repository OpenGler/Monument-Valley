#include "main.h"

//���ص�
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		r3 += 1;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		s3 += 1;
	myDisplay();
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