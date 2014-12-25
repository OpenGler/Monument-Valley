#include "main.h"

//����cube
void drawCube(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube(�л��������)
void drawCube01(GLvoid)         
{
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);
	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};
	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    
	glEnd();

	  // Back Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    
	glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
    GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	 //���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
   
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}
//����cube(�����ǵ�)
void drawCube02(GLvoid)         
{
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ���һ������texture[0]������������
	glBegin(GL_POLYGON);
	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {-0.9f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 0.9f, 1.0f};

	//���÷�����
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_POLYGON);
    GLfloat tex1v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 0.9f, -1.0f};
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 0.9f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.0f, -0.9f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.0f, -1.0f, -1.0f);
    //���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, 1.0f};
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    //���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = { -0.9f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = { -0.9f, -1.0f, 1.0f};
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( -0.9f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( -0.9f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    //���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, 0.9f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 0.9f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 0.9f, 1.0f);
    //���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    //���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);
	glEnd(); 

	// б�� Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex6v1[3] = {1.0f, 0.9f, -1.0f};
	GLfloat tex6v2[3] = {1.0f, 0.9f, 1.0f};
	GLfloat tex6v3[3] = {-1.0f, -0.9f, 1.0f};
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 0.9f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.9f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -0.9f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -0.9f, -1.0f);
    //���÷�����
	GLfloat tex6normal[3];
    norm(tex6v1,tex6v2,tex6v3,tex6normal);
	glNormal3f(tex6normal[0],tex6normal[1],tex6normal[2]);
	glEnd(); 

}
//����cube(����)
void drawCube03(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[3]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube�����£�
void drawCube04(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[4]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
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
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube��Բ����
void drawCube05(GLvoid)         
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	  // Front Face
	glBindTexture(GL_TEXTURE_2D, texture[5]);//   ѡ���һ������texture[0]������������
	glBegin(GL_QUADS);

	GLfloat tex0v1[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex0v2[3] = {1.0f, -1.0f, 1.0f};
	GLfloat tex0v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex0normal[3];
    norm(tex0v1,tex0v2,tex0v3,tex0normal);
	glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

	//����
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
	glBindTexture(GL_TEXTURE_2D, texture[5]);//   ѡ��ڶ�������texture[1]������������
	glBegin(GL_QUADS);
    GLfloat tex1v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex1v2[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex1v3[3] = { 1.0f, 1.0f, -1.0f};
	//���÷�����
	GLfloat tex1normal[3];
    norm(tex1v1,tex1v2,tex1v3,tex1normal);
	glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);
	
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

	  // Top Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[2]������������
	glBegin(GL_QUADS);
	GLfloat tex2v1[3] = {-1.0f, 1.0f, -1.0f};
	GLfloat tex2v2[3] = {-1.0f, 1.0f, 1.0f};
	GLfloat tex2v3[3] = {1.0f, 1.0f, -1.0f};

	//���÷�����
	GLfloat tex2normal[3];
    norm(tex2v1,tex2v2,tex2v3,tex2normal);
	glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
   
	glEnd();

	  // Bottom Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����ĸ�����texture[3]������������
	glBegin(GL_QUADS);
	GLfloat tex3v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex3v2[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex3v3[3] = {1.0f, -1.0f, 1.0f};

	//���÷�����
	GLfloat tex3normal[3];
    norm(tex3v1,tex3v2,tex3v3,tex3normal);
	glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);

	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Right face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ����������texture[4]������������
	glBegin(GL_QUADS);
	GLfloat tex4v1[3] = {1.0f, -1.0f, -1.0f};
	GLfloat tex4v2[3] = {1.0f, 1.0f, -1.0f};
	GLfloat tex4v3[3] = {1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex4normal[3];
    norm(tex4v1,tex4v2,tex4v3,tex4normal);
	glNormal3f(tex4normal[0],tex4normal[1],tex4normal[2]);

	   glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    
	glEnd();

	  // Left Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);//   ѡ�����������texture[5]������������
	glBegin(GL_QUADS);
	GLfloat tex5v1[3] = {-1.0f, -1.0f, -1.0f};
	GLfloat tex5v2[3] = {-1.0f, -1.0f, 1.0f};
	GLfloat tex5v3[3] = {-1.0f, 1.0f, 1.0f};

	//���÷�����
	GLfloat tex5normal[3];
    norm(tex5v1,tex5v2,tex5v3,tex5normal);
	glNormal3f(tex5normal[0],tex5normal[1],tex5normal[2]);

	   glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	   glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	   glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	   glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
	glEnd();         
}

//����cube(ϸ����)
void drawCube06(GLvoid)         
{       
	glPushMatrix();
	glScalef(0.1,2,0.1);
	glTranslatef(0.0f,0.5f,0.0f);
	drawCube();
	glPopMatrix();    
}

//����cube������������
void drawCube07(GLvoid)         
{     	
	glPushMatrix();
	glScalef(0.5,0.5,0.1);
	glTranslatef(0.0f,1.0f,0.0f);
	drawCube02();
	glPopMatrix();      
	       
}

//��ʵ������׶
void drawSolidTera()
{       
	//glTranslatef(0.0f,0.0f,-5.0f);
	glScalef(1,1,1);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_TRIANGLES);

		/*ǰ����Ļ���*/
	    GLfloat tex0v1[3] = {0.0,1,0.0};
		GLfloat tex0v2[3] = {-1,-1,1};
		GLfloat tex0v3[3] = {-1,-1,1};
		//���÷�����
		GLfloat tex0normal[3];
		norm(tex0v1,tex0v2,tex0v3,tex0normal);
		glNormal3f(tex0normal[0],tex0normal[1],tex0normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-1,-1,1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(1,-1,1);
	      

		/*�Ҳ���Ļ���*/
		GLfloat tex1v1[3] = {0.0,1,0.0};
		GLfloat tex1v2[3] = {1,-1,1};
		GLfloat tex1v3[3] = {1,-1,-1};
		//���÷�����
		GLfloat tex1normal[3];
		norm(tex1v1,tex1v2,tex1v3,tex1normal);
		glNormal3f(tex1normal[0],tex1normal[1],tex1normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(1,-1,1);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(1,-1,-1);
		
		
		/*�����Ļ���*/
		GLfloat tex2v1[3] = {0.0,1.0,0.0};
		GLfloat tex2v2[3] = {1.0,-1.0,-1.0};
		GLfloat tex2v3[3] = {-1.0,-1.0,-1.0};
		//���÷�����
		GLfloat tex2normal[3];
		norm(tex2v1,tex2v2,tex2v3,tex2normal);
		glNormal3f(tex2normal[0],tex2normal[1],tex2normal[2]);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1.0,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(1.0,-1.0,-1.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-1.0,-1.0,-1.0);
		
		//glEnd();

		
		/*�����Ļ���*/
		GLfloat tex3v1[3] = {0.0,1.0,0.0};
		GLfloat tex3v2[3] = {-1.0,-1.0,-1.0};
		GLfloat tex3v3[3] = {-1.0,-1.0,1.0};
		//���÷�����
		GLfloat tex3normal[3];
		norm(tex3v1,tex3v2,tex3v3,tex3normal);
		glNormal3f(tex3normal[0],tex3normal[1],tex3normal[2]);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(0.0,1.0,0.0);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(-1.0,-1.0,-1.0);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(-1.0,-1.0,1.0);
        

	glEnd();
	glPopMatrix();
}

//����������׶
void drawWireTera()
{
	//��ûд
}