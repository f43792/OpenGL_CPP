/*
OpenGL app using SDL

Tutorial from:
https://www.youtube.com/watch?v=DkiKgQRiMRU&index=5&list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh

by FCN - OCT/2016

26-Oct-2016       FCN         - Set app to use Makefile

*/

#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"

using namespace std;

int main()
{
    // Create display object, responsable for SDL
    // initialization and O.S. <-> GL bindings
    Display display(800, 600, "Hello opengl");

    //Create vertices
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
                          Vertex(glm::vec3(0, 0.5, 0)),
                          Vertex(glm::vec3(0.5, -0.5, 0)), };

    //Create a mesh, passing the recem created vertices
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));



    // Main loop. display.IsClosed come to true
    // when SDL got SDL_QUIT on Poll event loop
    while(!display.IsClosed())
    {
        // While not, still cleanring the screen
        // with passed RGBA color
        display.Clear(0.35f, 0.0f, 0.45f, 1.0f);

        mesh.Draw();

        // And calling he update method
        display.Update();
    }

    return 0;
}
