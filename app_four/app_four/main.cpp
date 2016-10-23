/*
Another tutorial, this time from:
https://www.youtube.com/watch?v=DkiKgQRiMRU&index=5&list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh
*/

#include <iostream>
#include <GL/glew.h>
#include "display.h"


using namespace std;

int main()
{
    Display Display(800, 600, "Hello opengl");

    while(!Display.IsClosed())
    {

    Display.Clear(0.35f, 0.0f, 0.45f, 1.0f);
    Display.Update();

    }

    return 0;
}
