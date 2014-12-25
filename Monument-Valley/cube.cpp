#include "main.h"

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
	//还没写
}