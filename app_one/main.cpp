/*
First try on openGl c++ application
Fabio Nascimento @ 21/out/2016

Dependencies:
freeglut - sudo apt install libfreeglut-dev
glew - sudo apt install libglew-dev
glm - sudo apt install libglm-dev
Set to use just Atom and Makefile ;)
*/

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>


void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glutSolidTeapot(.5);
  glFlush();
}



int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitDisplayMode(GLUT_RGB);

  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);

  glutCreateWindow("Teapot");

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}
