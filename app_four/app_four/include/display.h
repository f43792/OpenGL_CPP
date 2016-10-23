#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>

#include <string>

class Display
{
    public:
        Display(int width, int height, const std::string& title);

        void Update();
        bool IsClosed();
        void Clear(float r, float g, float b, float a);

        virtual ~Display();

    protected:
    private:
        Display(const Display& other);
        Display& operator=(const Display& other);

        SDL_Window* m_Window;
        SDL_GLContext m_glContext;

        bool m_queryToClose;

};

#endif // DISPLAY_H
