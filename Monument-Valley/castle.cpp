#include "main.h"

//»­part1
void drawPart1()
{
	for(int x = -1;x <= 3; x++)
	{
		
			for(int y = 0; y < 18; y++)
			{
				if(x == -1){
					if(y > 0 && y < 5){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						glRotatef(90,0.0f,0.0f,1.0f);
						drawSolidTera();
						glPopMatrix();
					}
					if(y>=5&&y<10){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube05();
						glPopMatrix();
					}
					if(y>=10&&y<16){
						if(y==14){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube04();
							glPopMatrix();
						}else if(y==15){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube03();
							glPopMatrix();
						}else{
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							drawCube();
							glPopMatrix();
						}
					}
					if(y == 16){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube01();
						glPopMatrix();
					}
					if(y ==17){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawSolidTera();
						glPopMatrix();
					}
				}
				if(x == 0){
					if(y==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						glRotatef(180,0.0f,0.0f,1.0f);
						drawSolidTera();
						glPopMatrix();
					}
					if(y>0&&y<14){
						if(y==2||y==6||y==10){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube04();
							glPopMatrix();	
						}else if(y==3||y==7||y==11){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube03();
							glPopMatrix();	
						}else{
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,0.0f);
							drawCube();
							glPopMatrix();	
						}
					}
				}
				if(x == 1){
					if(y==1||y==5||y==9){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube();
						glPopMatrix();							
					}
					if(y==13){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube02();
						glPopMatrix();							
					}
				}
				if(x == 2){
					if(y==1||y==5||y==9){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube();
						glPopMatrix();							
					}	
				}
				if(x == 3){
					if(y==1||y==5||y==9){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,0.0f);
						drawCube02();
						glPopMatrix();							
					}
				}
			}
		
	}
}
//»­part2
void drawPart2()
{
	for(int y = 1; y <= 13; y++)
	{
		for(int x = -3; x<=3; x++)
		{
			for(int z = -2; z<=2;z++)
			{
				if(y==1){
					if(x==0){
						if(z>=-1&&z<=1){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube();
							glPopMatrix();
						}
						if(z==2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(-90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
						if(z==-2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
					}
					if((x==1||x==-1)&&z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube();
						glPopMatrix();
					}
					if(x==-2&&z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						glRotatef(180,0.0f,1.0f,0.0f);
						drawCube02();
						glPopMatrix();
					}
					if(x==2&&z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube02();
						glPopMatrix();
					}
				}
				if(y>=2&&y<=4&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				if(y==5&&x==0){
					if(z>=-1&&z<=1){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube();
							glPopMatrix();
						}
						if(z==2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(-90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
						if(z==-2){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							glRotatef(90,0.0f,1.0f,0.0f);
							drawCube02();
							glPopMatrix();
						}
				}
				if(y==6&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube04();
					glPopMatrix();
				}
				if(y==7&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube03();
					glPopMatrix();
				}
				if(y==8&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				if(y==9&&x==0){
					if(z==-1||z==0){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube();
						glPopMatrix();
					}
					if(z==-2){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						glRotatef(90,0.0f,1.0f,0.0f);
						drawCube02();
						glPopMatrix();
					}
				}
				if(y==10&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f-0.9f);
					drawCube06();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f+0.9f);
					drawCube06();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f-0.9f);
					drawCube06();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f+0.9f);
					drawCube06();
					glPopMatrix();
				}
				if(y==11&&x==0&&z==0){
					glPushMatrix();
					glTranslatef(x*2.0f-0.5f,y*2.0f,z*2.0f+0.9f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f+0.5f);
					glRotatef(90,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();
	
					glPushMatrix();
					glTranslatef(x*2.0f+0.5f,y*2.0f,z*2.0f-0.9f);
					glRotatef(180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f-0.5f);
					glRotatef(270,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					//·´
					glPushMatrix();
					glTranslatef(x*2.0f+0.5f,y*2.0f,z*2.0f+0.9f);
					glRotatef(180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f+0.9f,y*2.0f,z*2.0f-0.5f);
					glRotatef(90+180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();
	
					glPushMatrix();
					glTranslatef(x*2.0f-0.5f,y*2.0f,z*2.0f-0.9f);
					glRotatef(180+180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();

					glPushMatrix();
					glTranslatef(x*2.0f-0.9f,y*2.0f,z*2.0f+0.5f);
					glRotatef(270+180,0.0f,1.0f,0.0f);
					drawCube07();
					glPopMatrix();
				}
				if(y==12&&z==0){
					if(x>=-2&&x<=2){
						if(x==0){
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube05();
							glPopMatrix();
						}else{
							glPushMatrix();
							glTranslatef(x*2.0f,y*2.0f,z*2.0f);
							drawCube();
							glPopMatrix();
						}
					}
					if(x==-3){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						glRotatef(180,0.0f,1.0f,0.0f);
						drawCube02();
						glPopMatrix();
					}
					if(x==3){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube02();
						glPopMatrix();
					}
				}
				if(y==13&&z==0){
					if(x>=-1&&x<=1){
						glPushMatrix();
						glTranslatef(x*2.0f,y*2.0f,z*2.0f);
						drawCube();
						glPopMatrix();
					}
				}
			}
		}
	}
}
//»­part3
void drawPart3()
{
	int z=0;
	for(int x=-1;x<=1;x++)
	{
		for(int y=0; y<=3; y++)
		{
			if(x==-1&&y==0){
				glPushMatrix();
				glTranslatef(x*2.0f,y*2.0f,z*2.0f);
				glRotatef(180,0.0f,1.0f,0.0f);
				drawCube02();
				glPopMatrix();
			}
			if(x==1){
				if(y==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube02();
					glPopMatrix();
				}
				if(y==1||y==2){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				
			}
			if(x==0){
				if(y==0){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					drawCube();
					glPopMatrix();
				}
				if(y==2){
					glPushMatrix();
					glTranslatef(x*2.0f,y*2.0f,z*2.0f);
					glRotatef(90,0.0f,0.0f,1.0f);
					drawSolidTera();
					glPopMatrix();
				}
			}
		}
	}

}
//»­³Ç±¤
void drawCastle()
{
		//GLfloat material_ambient1[] = {0.3, 0.3, 0.3, 1.0};
	materialLight1();

	glPushMatrix();
	glRotatef(HierParam,0.0f,1.0f,0.0f);//i=1
	glTranslatef(-6*2,0.0f,0.0f);
	drawPart1();
	glPopMatrix();

	glPushMatrix();
	glRotatef(HierParam,0.0f,1.0f,0.0f);//i=1
	glTranslatef(6*2,0.0f,0.0f);
	glRotatef(180,0.0f,1.0f,0.0f);
	drawPart1();
	glPopMatrix();
  
	glPushMatrix();
	drawPart2();
	//glRotatef(HierParam,0.0f,1.0f,0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3*2.0f,13*2.0f,0.0f);
	glRotatef(HierParam,0.0f,1.0f,0.0f);//i=1
	drawPart3();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3*2.0f,13*2.0f,0.0f);
	glRotatef(180,0.0f,1.0f,0.0f);
	glRotatef(HierParam,0.0f,1.0f,0.0f);//i=1
	drawPart3();
	glPopMatrix();

}