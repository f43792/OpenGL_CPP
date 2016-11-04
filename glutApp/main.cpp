#include <stdio.h>
#include <string>
#include <iostream>

#if defined(HAVE_FREEGLUT)

#ifdef WIN32
#include "../include/GL/freeglut.h"
#else
#include <GL/freeglut.h>
#endif

#else

#include <GL/glut.h>

#endif

#define PROGRAM "glversion"

using namespace std;

void render()
{

    glClear (GL_COLOR_BUFFER_BIT);

    //# draw white polygon (rectangle) with corners at
    //# (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    glColor3f (1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.25, 0.25, 0.0);
    glVertex3f (0.75, 0.25, 0.0);
    glVertex3f (0.75, 0.75, 0.0);
    glVertex3f (0.25, 0.75, 0.0);
    glEnd();

    //# don't wait!
    //# start processing buffered OpenGL routines
    //glFlush ();
    glutSwapBuffers();
}

GLuint initGlut(int argc, char **argv)
{
    //char *version = NULL;
    const GLubyte* version = NULL;
    const GLubyte* vendor  = NULL;
    const GLubyte* devGPU  = NULL;
    //char *extensions = NULL;
    GLuint idWindow = 0;

    //int glutVersion;
    glutInit(&argc, argv);
    glutInitWindowPosition(100 , 100);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    idWindow = glutCreateWindow(PROGRAM);
    glutSetWindowTitle("glut Application");
    //glutHideWindow();

    //glutVersion = glutGet(0x01FC);
    //version =     (char*)glGetString(GL_VERSION);
    version  = glGetString(GL_VERSION);
    vendor   = glGetString(GL_VENDOR);
    devGPU   = glGetString(GL_RENDERER);
    //extensions =  (char*)glGetString(GL_EXTENSIONS);
    //printf("GLUT=%d\nVERSION=%s\nVENDOR=%s\nRENDERER=%s\n", glutVersion,version,vendor,renderer); //EXTENSIONS=%s\n , extensions
    cout << "Version: " << version  << endl;
    cout << "Verndor: " << vendor   << endl;
    cout << "Device: "  << devGPU   << endl;
    //cout << "Glut version: " << glutVersion << endl;

    return idWindow;

}

int main(int argc, char **argv)
{
    GLuint idWindow = 0;
    float xPos;

    xPos = 0.25;

    idWindow = initGlut(argc, argv);
    glClearColor(0.3, 0.0, 0.45, 0.0);
    glutDisplayFunc(render);



    glutMainLoop();

    glutDestroyWindow(idWindow);
    return(0);
}
