#include "main.h"

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


//画背景
void drawBackground()      
{
	glScalef(1,1,1);


	// Front Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);
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

	  
	// Top Face
	glBindTexture(GL_TEXTURE_2D, texture[2]);
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