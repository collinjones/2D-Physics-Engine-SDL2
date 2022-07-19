#ifndef _TEXT_
#define _TEXT_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>

using namespace std;

class Text {
    
private:
    SDL_Rect* rect;

public:
    Text ();

    Text (SDL_Rect* r);

    void SetRect(SDL_Rect* r);

    void Render (SDL_Renderer* renderer, SDL_Color color, TTF_Font* font, const char* msg);

};

#endif