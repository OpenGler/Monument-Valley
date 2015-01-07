#include "main.h"
using namespace std;


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

//平移
void translate(float temp){
	pox-= 0.1*temp*cos(10*r1*Pi/180);
	poy+= 0.1*temp*sin(10*r1*Pi/180);
	cout<<"pox : "<<pox<<endl;
	cout<<"poy : "<<poy<<endl;
}