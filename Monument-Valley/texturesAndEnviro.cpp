#include "main.h"

//����λͼ
AUX_RGBImageRec *LoadBMP(char *Filename)    // ����λͼ�ļ������ƽ��м���
{
	FILE *File=NULL;        // �ļ�ָ��

	if (!Filename)         // ���û��ָ��λͼ�ļ����ƾͷ���NULL
	{
		 return NULL;         
	}

	fopen_s(&File,Filename,"r");       // ����ָ����λͼ�ļ����ƣ��򿪸�λͼ�ļ�


	if (File)           // ���λͼ�ļ�����
	{
		fclose(File);         // ��Ϊֻ����Ҫ�ж������Ƿ���ڣ�������Ҫ��λͼ�ļ�����д���������Թر�λͼ�ļ�
		return auxDIBImageLoad(Filename);   // ��ʵ��ֻ��Ҫһ���������ڵ�λͼ�ļ������ƣ�ʵ�ּ���λͼ�ļ���������һ��ָ��
	}

	return NULL;          // λͼ�ļ�����ʧ�ܾͷ���NULL
}


//��������&������
int LoadGLTextures()         // ���ݼ��ص�λͼ��������
{
	int Status=FALSE;         // ָʾ�������Ƿ�ɹ��ı�־

	AUX_RGBImageRec *TextureImage[6];     // ����һ������ͼ�����飬����ָ�������СΪ6

	memset(TextureImage,0,sizeof(void *)*6);          // ��ʼ������ͼ�����飬Ϊ������ڴ�

	char *pictures[] = {// ����һ��λͼ�������飬��Ӧ6��λͼ
		"Data/No1.bmp",
		"Data/No2.bmp",
		"Data/No3.bmp",
		"Data/No4.bmp",
		"Data/No5.bmp",
		"Data/No6.bmp"
	};
	for(int i=0; i<6; i++)// ����λͼ�������飬����λͼ���Ʒֱ�����
	{
		if (TextureImage[i]=LoadBMP(pictures[i]))// ����λͼi�ɹ����޸�״̬��־����StatusΪTRUE
	   {
			Status=TRUE;        

			glGenTextures(1, &texture[i]);     // Ϊ��i��λͼ��������
			glBindTexture(GL_TEXTURE_2D, texture[i]);// �����ɵ���������ư󶨵�ָ����������
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[i]->sizeX, TextureImage[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[i]->data);

	   }

	   if (TextureImage[i])         // �ͷ�λͼ����ռ�õ��ڴ�ռ�
	   {
			if (TextureImage[i]->data)       
			{
				 free(TextureImage[i]->data);    
			}

			free(TextureImage[i]);        
	   }
	}
	return Status;          // �����������أ����سɹ�����ʧ�ܵı�־Status
}


//������
void drawBackground()      
{
	glScalef(1,1,1);


	// Front Face
	glBindTexture(GL_TEXTURE_2D, texture[0]);
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

	  
	// Top Face
	glBindTexture(GL_TEXTURE_2D, texture[2]);
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
}

//������ϵ
void drawCoordinateSystem()
{
	//�任
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