#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void print(int x,int y);

//coordenadas do centro da circunferencias
int cx = 128, cy = 128;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Desenhando uma linha");
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 0.0, 1.0);
  
  int x=0,r=50;
  int y = r;
  int d = 1 - r;

  print(x,y);

  while(y > x){
    if(d < 0){
      d = d + 2*x + 3;
      x = x + 1;
    }
    else{
      d = d + 2*(x-y) + 5;
      x = x + 1;
      y = y - 1;
    }
    print(x,y);
  }
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

void print(int x,int y){
  //quando um pomto e escolhido para ser desenhado no pegamos os seus representantes no outro octantes e também desenhamos
  glBegin(GL_POINTS);
  glVertex2i(x+cx,y+cy);
  glEnd();
    
  glBegin(GL_POINTS);
  glVertex2i(y+cy,x+cx);
  glEnd();

  glBegin(GL_POINTS);
  glVertex2i(y+cy,-x+cx);
  glEnd();

  glBegin(GL_POINTS);
  glVertex2i(x+cx,-y+cy);
  glEnd();

  glBegin(GL_POINTS);
  glVertex2i(-x+cx,-y+cy);
  glEnd();

  glBegin(GL_POINTS);
  glVertex2i(-y+cy,-x+cx);
  glEnd();

  glBegin(GL_POINTS);
  glVertex2i(-y+cy,x+cx);
  glEnd();

  glBegin(GL_POINTS);
  glVertex2i(-x+cx,y+cy);
  glEnd();
  glFlush();
}