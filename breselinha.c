#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

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
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}



void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 1.0,0.0);
  
  
  int x,y,x1=40,y1=200,x2=200,y2=10;
  //s1 e s2 guardaram o sinal de x2-x1 e y2-y1
  int delta_x, delta_y, s1 , s2;
  int aux, troca; 
  int e;

  x = x1; y = y1; delta_x = abs(x2 - x1); delta_y = abs(y2 - y1);
  
  if(x2 - x1 < 0)
    s1 = -1;
  else 
    s1 = +1;
  
  if(y2 - y1 < 0)
    s2 = -1;
  else 
    s2 = +1;


  if(delta_y < delta_x){
    aux = delta_x;
    delta_x = delta_y;
    delta_x = aux;
    troca = 1;
  }
  else{
    troca = 0;
  }
  
  e = 2*delta_y - delta_x;

  for(i=1; i<=delta_x;i++){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
    while(e >= 0){
     if(troca == 1){
      x = x + s1;
     }
     else{
      y = y + s2;
     }
     e = e - 2*delta_x;
    }

    if(troca == 1){
      y = y + s2;
    }
    else{
      x = x + s1;
    }
    e = e + 2*delta_y;    
  }
  /*
  glBegin(GL_LINES);
    glVertex2i(40,200); glVertex2i(200,10);
    glEnd();
    glFlush();
  */
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}
