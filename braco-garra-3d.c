#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, p=0 , i=0, m=0,b=0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  //glEnable(GL_DEPTH_TEST);
  //glutSwapBuffers();
  //glEnable(GL_CULL_FACE);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT); 
  glPushMatrix(); 

  glColor3f(1.0,0.0,0.0);
  /* origem posicionada no ombro */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);

  /* origem posicionada no centro do braço */ 
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutSolidCube (1.0);//desenha um cubo de tamanho 1 centrado na origem
  glPopMatrix();
   
  glColor3f(0.0,1.0,0.0);
  /* origem posicionada no cotovelo */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutSolidCube (1.0);
  glPopMatrix();

  glColor3f(0.0,0.0,1.0);
  //Dedo p
  glPushMatrix();
  glTranslatef (1.0, -0.2, 0.0);
  glRotatef ((GLfloat) p, 0.0, 0.0, 1.0);
  glTranslatef (0.4, 0.0, 0.0);
  glPushMatrix();
  glScalef (0.8, 0.4, 0.2);
  glutSolidCube(1.0);
  glPopMatrix();
  glPopMatrix();

  glColor3f(1.0,1.0,0.0);
  //dedo i
  glPushMatrix();
  glTranslatef (1.0, 0.2, 0.5);
  glRotatef ((GLfloat) i, 0.0, 0.0, 1.0);
  glTranslatef (0.4, 0.0, 0.0);
  glPushMatrix();
  glScalef (0.8, 0.4, 0.2);
  glutSolidCube(1.0);
  glPopMatrix();
  glPopMatrix();

  glColor3f(1.0,0.0,1.0);
  //dedo m
  glTranslatef (1.0, 0.2, -0.5);
  glRotatef ((GLfloat) m, 0.0, 0.0, 1.0);
  glTranslatef (0.4, 0.0, 0.0);
  glPushMatrix();
  glScalef (0.8, 0.4, 0.2);
  glutSolidCube(1.0);
  glPopMatrix();

  /* origem volta para o sistema de coordenadas original */
  glPopMatrix();
  glRotatef ((GLfloat) b, 0.0, 1.0, 0.0);
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'i':
    i = (i + 5) % 360;
    glutPostRedisplay();
    break;
  case 'I':
    i = (i - 5) % 360;
    glutPostRedisplay();
    break;  
  case 'p':
    p = (p + 5) % 360;
    glutPostRedisplay();
    break;
  case 'P':
    p = (p - 5) % 360;
    glutPostRedisplay();
    break;  
  case 'm':
    m = (m + 5) % 360;
    glutPostRedisplay();
    break;
  case 'M':
    m = (m - 5) % 360;
    glutPostRedisplay();
    break;
    case 'b':
    b = (b + 1) % 360;
    glutPostRedisplay();
    break;
  case 'B':
    b = (b - 1) % 360;
    glutPostRedisplay();
    break;      
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}

