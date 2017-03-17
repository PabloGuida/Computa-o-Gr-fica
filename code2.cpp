//ALGORITMO DE DEMONSTRAÇÃO OPENGL
#include<windows.h>
#include <GL/glut.h>
#include<iostream>
#include <stdlib.h>
 
using namespace std;
 
void teclaTeclado(unsigned char key, int x, int y)
{
switch(key)
{
case 27:
exit(0);
}
}
void initRendering()
{
glEnable(GL_DEPTH_TEST);
}
 
void tamanhoTela(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
}
 
float _angle=0.0;
float _cameraangle=30.0;
 
void desenhoCena()
{

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(1.0f,0.0f);
glTranslatef(0.0f, -10.0f);
 
glPushMatrix();
glTranslatef(5.0f, -1.0f);
glScalef(2.0f,2.0f);
glRotatef(_angle,1.0f,2.0f);
glBegin(GL_QUADS);
 
glVertex2f(-0.9f,0.0);
glVertex2f(0.6f,0.0);
glVertex2f(0.5f,0.0);
glVertex2f(-0.7f,0.0);
 
glEnd();

}
void atualiza(int value)
{
_angle+=2.0f;
if(_angle>360.f)
{
_angle-=360;
}
glutPostRedisplay();
glutTimerFunc(25,atualiza,0);
}
 
int main(int argc,char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(600,600);
 
 
glutCreateWindow("Rotação");
initRendering();
 
 
 
glutDisplayFunc(desenhoCena);
glutKeyboardFunc(teclaTeclado);
glutReshapeFunc(tamanhoTela);
 
glutTimerFunc(25,atualiza,0);

glutMainLoop();
 
 
return 0;
}