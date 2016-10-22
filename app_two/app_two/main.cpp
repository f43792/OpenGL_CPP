/*
Secund app, from tutorial:
http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/


by Fabio Nascimento
21/out/2016

*/


// Include standard headers
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

//using namespace std;

int main()
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }


    return 0;
}
