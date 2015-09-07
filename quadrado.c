#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int aux =0;

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
  if(aux ==0)
	glColor3f (1.0, 0.0, 0.0);
  else
  	glColor3f (0.0, 0.0, 1.0);

  glBegin(GL_POLYGON);
  glVertex2i(30,30);  
  glVertex2i(226,30);
  glVertex2i(226,226);  
  glVertex2i(30,226);
  glEnd();
  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  case 97:
	aux = 1;
	display();
	break;
  case 118:
  	aux =0;
  	display();
  	break; 
  }
}
