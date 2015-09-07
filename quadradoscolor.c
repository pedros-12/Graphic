/* programa teste-make.c */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);
void convertToRgb(float);


float r,g,b;
//cada vertice do quadrado começara com um angulo determinado que serão incrementados {0 , 90 , 180 , 270}
float h[4]={0.0,90.0,180.0,270.0}, I=0.8,S=1.0;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glutTimerFunc(33,timer,1);
  //glShadeModel (GL_FLAT);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}


void timer(int value){
	int i;	
	//incrementa o grau de cada vertice em 1
	for(i=0;i<4;i++){
		h[i]=h[i]+1;
		if(h[i] >= 360)
			h[i] = 0;
	}	
	glutPostRedisplay();
	glutTimerFunc(100,timer,1);	
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  convertToRgb(h[0]);//transforma o valor do primeiro vertice em rgb associado a um valor HSI
  
  glColor3f (r, g, b);
  glBegin(GL_POLYGON);
  glVertex2f(0.25,0.25);
  convertToRgb(h[1]);

  glColor3f (r, g, b);
  glVertex2f(0.75,0.25);
  convertToRgb(h[2]);
  
  glColor3f (r, g, b);
  glVertex2f(0.75,0.75);
  convertToRgb(h[3]);
  
  glColor3f (r, g, b);
  glVertex2f(0.25,0.75);
  
  glEnd();
  glFlush();
}


//Função convertecer HSI - RGB do professor
void convertToRgb(float h){	
	if(h <120){
		b = I * (1 - S)/3;
		r = I * (1 + (S*cos( (h*PI)/180.0 ) )/(cos( ((60-h)*PI)/180.0 ) ) ) /3;
		g = 3*I - (r+b);
	}
	else if(h < 240){
		h = h-120.0;		
		r = I * (1 - S)/3;
		g = I * (1 + (S*cos( (h*PI)/180.0 ) )/(cos( ((60-h)*PI)/180.0 ) ) ) /3;
		b = 3*I - (r+g);
	}
	else{
		h = h - 240.0;
		g = I * (1 - S)/3;
		b = I * (1 + (S*cos( (h*PI)/180.0 ) )/(cos( ((60-h)*PI)/180.0 ) ) ) /3;
		r = 3*I - (g+b);
	}
}
