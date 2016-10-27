/*
OpenGL app using SDL

Tutorial from:
https://www.youtube.com/watch?v=DkiKgQRiMRU&index=5&list=PLEETnX-uPtBXT9T-hD0Bj31DSnwio-ywh

by FCN - OCT/2016

*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

using namespace std;

// Class used to initialize SDL and set O.S. (ei.: window) and SDL
// typically by a context object
class Display
{
    public:
        // Constructor.
        Display(int width, int height, const std::string& title);

        // Update method, called on main.cpp own loop
        void Update();

        // Methos to check there is a query to close application
        bool IsClosed();

        // Methos to clear screen, using the passed colors
        void Clear(float r, float g, float b, float a);

        // Method to show passed string on terminal (fcn)
        void showText(string Text);

        // Destructor
        virtual ~Display();

    protected:
        // Message counter incrementary method (fcn)
        void incMessageCounter(void);
        // getter of message counter (fcn)
        long int getMessageCounter(void);
    private:
        // Have no ideia what is
        Display(const Display& other);
        // Same here
        Display& operator=(const Display& other);

        // Pointer to SDL_Window obj
        SDL_Window* m_Window;
        // SDL_Context, used to bind stuff beatween Windows and GL
        SDL_GLContext m_glContext;

        // Class variables
        bool m_queryToClose;
        long int m_messageCounter;

};

#endif // DISPLAY_H
