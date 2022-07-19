#ifndef _DISPLAYPANEL_
#define _DISPLAYPANEL_

#include <SDL2/SDL.h>
#include "text.h"

#include <iostream>

class DisplayPanel {

protected:
    SDL_Rect* rect;
    SDL_Color panelColor;
    Text* text;

public:
    DisplayPanel(int x, int y, int w, int h, SDL_Color fColor);

    void Update(SDL_Renderer* renderer, SDL_Color textColor, TTF_Font* font, const char* str);

    void Draw(SDL_Renderer* renderer, int r, int g, int b);
};

#endif