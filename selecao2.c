#include <GL/glut.h>
#include <stdlib.h>

//vetor hexadecimal para montar o mapa de bits
GLubyte tux[] = {
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x7f,  0xfe,  0x0, 
 0x0,  0xc4,  0x23,  0x0, 
 0x1,  0x83,  0x21,  0x80, 
 0x1,  0x7,  0xe0,  0x80, 
 0x1,  0x7,  0xf0,  0x80, 
 0x1,  0x8f,  0xf9,  0x80, 
 0x0,  0xff,  0xff,  0x0, 
 0x0,  0x4f,  0xf1,  0x0, 
 0x0,  0x6f,  0xf1,  0x0, 
 0x0,  0x2f,  0xf3,  0x0, 
 0x0,  0x27,  0xe2,  0x0, 
 0x0,  0x30,  0x66,  0x0, 
 0x0,  0x1b,  0x1c,  0x0, 
 0x0,  0xb,  0x88,  0x0, 
 0x0,  0xb,  0x98,  0x0, 
 0x0,  0x8,  0x18,  0x0, 
 0x0,  0xa,  0x90,  0x0, 
 0x0,  0x8,  0x10,  0x0, 
 0x0,  0xc,  0x30,  0x0, 
 0x0,  0x6,  0x60,  0x0, 
 0x0,  0x3,  0xc0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0
};

GLfloat r,g,b;
char aux = 'f';

int m[4][4] = { 
                30,143,113,226,   //(x1,y1)(x2,y2)
                143,226,226,143,  //(x1,y1)(x2,y2)              
                30,30,113,133,    //(x1,y1)(x2,y2)
                143,30,226,113    //(x1,y1)(x2,y2)
              };

void init(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);//utiliza dois buffers um principal e outro auxiliar. Todos os objetos deverão ser desenhados no buffer
                                              //auxiliar. Quando a func glutSwapBuffers() for chamada o buffer auxiliar passa a ser o principal
                                              //
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Preenchendo regiões");
  init(); 
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);//define a função que o GLut deverá chamar  quando ocorrerem eventos de mouse
  glutMainLoop();
  return 0;
}

//Inicializa os quadrados amarelos com as bordas pretas
void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
  r=0; g=1; b=0;
  int i;
  
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_POLYGON_STIPPLE);
  //glPolygonMode(GL_BACK, GL_LINE); // desenha o fundo apenas com linhas
  //quadrados
  // 1
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();
  //2
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();
  //3
  glBegin(GL_POLYGON);
  glVertex2i(30,113);  glVertex2i(113,113);
  glVertex2i(113,30);  glVertex2i(30,30); 
  glEnd();
  //4
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30);  glVertex2i(143,30); 
  glEnd();
 
  //Bordas
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(0.0,0.0,0.0);
  //b1
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();  
  //b2
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();
  //b3
  glBegin(GL_POLYGON);
  glVertex2i(30,113);  glVertex2i(113,113);
  glVertex2i(113,30);  glVertex2i(30,30); 
  glEnd();
  //b4
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30);  glVertex2i(143,30); 
  glEnd();

  glFlush();
  //glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'f':
    aux = 'f';
    break;
  case 'b':
    aux = 'b';
    break;
  }
}

//para desenhar o poligono a origem fica no vertice (inferior esquerdo), já no para pegar as coordenadas do mouse a referência é o
//vertice (superior esquerdo)
void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
      r=(GLfloat)rand()/(RAND_MAX+1.0);
      g=(GLfloat)rand()/(RAND_MAX+1.0);
      b=(GLfloat)rand()/(RAND_MAX+1.0);
      //glutPostRedisplay();

      if(aux == 'f')
        glPolygonMode(GL_BACK, GL_FILL);// se for para mudar a face usamos o FILL
      else if(aux == 'b')
        glPolygonMode(GL_BACK, GL_LINE);

      //printf("x = %d  y = %d \n", x, y );
      glColor3f(r,g,b);
      if((x >= 30 && x <= 113) && (y >=143 && y <=226)){
        glBegin(GL_POLYGON);
        glVertex2i(30,113);  glVertex2i(113,113);
        glVertex2i(113,30);  glVertex2i(30,30); 
        glEnd();
      }
      //2
      else if((x >= 143 && x <= 226) && (y >=143 && y <=226)){
        glBegin(GL_POLYGON);
        glVertex2i(143,113); glVertex2i(226,113);
        glVertex2i(226,30);  glVertex2i(143,30); 
        glEnd();
      }
      //3
      else if((x >= 30 && x <= 113 && y >=30 && y <=113)){
        glBegin(GL_POLYGON);
        glVertex2i(30,226);  glVertex2i(113,226);
        glVertex2i(113,143); glVertex2i(30,143); 
        glEnd();
      }
      //4
      else if((x >= 143 && x <= 226 && y >=30 && y <=113)){
        glBegin(GL_POLYGON);
        glVertex2i(143,226); glVertex2i(226,226);
        glVertex2i(226,143); glVertex2i(143,143); 
        glEnd();
      }
      glFlush();
      //glutSwapBuffers();
    }
  break;
  
  }
}
