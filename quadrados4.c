#include <GL/glut.h>
#include <stdlib.h>

void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  /*glShadeModel (GL_FLAT);*/
  glOrtho (0, 10.0, 0, 10.0, 0 ,1.0);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}


void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  
  //Desenha o Primeiro quadrado
  glColor3f (0.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(0.0,0.0);
  glVertex2f(2.0,0.0);
  glVertex2f(2.0,2.0);
  glVertex2f(0.0,2.0);
  glEnd();

  //2 Quadrado
  glColor3f (1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(2.0,2.0);
  glVertex2f(4.0,2.0);
  glVertex2f(4.0,4.0);
  glVertex2f(2.0,4.0);
  glEnd();

  //3 quadrado
  glColor3f (0.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(4.0,4.0);
  glVertex2f(6.0,4.0);
  glVertex2f(6.0,6.0);
  glVertex2f(4.0,6.0);
  glEnd();

  //4 quadrado
  glColor3f (0.0, 0.0, 1.0);
  glBegin(GL_POLYGON);
  glVertex2f(6.0,6.0);
  glVertex2f(8.0,6.0);
  glVertex2f(8.0,8.0);
  glVertex2f(6.0,8.0);
  glEnd();

  glFlush();
}
