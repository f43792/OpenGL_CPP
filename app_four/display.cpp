/*
OpenGL app using SDL

Tutorial from:
https://www.youtube.com/watch?v=DkiKgQRiMRU&index=5&list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh

by FCN - OCT/2016

*/

#include "display.h"
#include <iostream>
#include <GL/glew.h>
#include <string>

Display::Display(int width, int height, const std::string& title)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_Window);

    GLenum GL_Status = glewInit();

    m_queryToClose = false;
    m_messageCounter = 0;

    if (GL_Status != GLEW_OK)
    {
        std::cerr << "OpenGL failed to initalize." << std::endl;
    } else
    {
        showText("OpenGL initialized.");
    }



}

Display::~Display()
{
    showText("Exiting...");
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

bool Display::IsClosed()
{
    return m_queryToClose;
}

void Display::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::showText(std::string Text)
{
    std::cout << this->getMessageCounter()  << " ] "<< Text << std::endl;
}

void Display::incMessageCounter(void)
{
    this -> m_messageCounter++;
}

long int Display::getMessageCounter(void)
{
    this->incMessageCounter();
    return this->m_messageCounter;
}

void Display::Update()
{
    SDL_GL_SwapWindow(m_Window);

    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            m_queryToClose = true;
        }
    }

}
