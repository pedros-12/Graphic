#include <GL/glut.h>
#include <stdlib.h>

//vetor que ira representar as iniciais
GLubyte tux[] = {
 0x0,  0x0,  0x0,   0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0xc0, 0x33,  0x0, 
 0x0,  0xc0, 0x33,   0x0, 
 0x0,  0xc0, 0x33,  0x0, 
 0x0,  0xc0, 0x33,  0x0, 
 0x0,  0xc0, 0x33,  0x0, 
 0x0,  0xff, 0x3f,  0x0, 
 0x0,  0xff, 0x3f,  0x0, 
 0x0,  0xc3, 0x33,  0x0, 
 0x0,  0xc3, 0x33,  0x0, 
 0x0,  0xc3, 0x33,  0x0, 
 0x0,  0xff, 0x33,  0x0, 
 0x0,  0xff, 0x33,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 

};

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
    
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize (300, 300); 
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
  glOrtho (0, 300, 0, 300, -1 ,1);

  glClear(GL_COLOR_BUFFER_BIT);
  
  glPolygonMode(GL_FRONT, GL_LINE);
  glColor3f (0.0, 0.0, 0.0);
  
  glBegin(GL_POLYGON);
  glVertex2i(50,50);  	glVertex2i(250,50);
  glVertex2i(250,250);	glVertex2i(50,250);
  glEnd();

  glPolygonMode(GL_BACK, GL_FILL);
  glEnable(GL_POLYGON_STIPPLE);
  glColor3f(0.0, 0.0, 1.0);
  glPolygonStipple(tux);
  glBegin(GL_POLYGON);
  glVertex2i(50,100);   glVertex2i(50,200);
  glVertex2i(100,250);  glVertex2i(200,250);
  glVertex2i(250,200);   glVertex2i(250,100);
  glVertex2i(200,50);  glVertex2i(100,50);
  
  glEnd();
  glFlush();
}

void display(void){
  int i;
  
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:
  break;
  }
}