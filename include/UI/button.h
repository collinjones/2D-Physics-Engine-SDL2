#ifndef _BUTTON_
#define _BUTTON_

#include <SDL2/SDL.h>
#include <iostream>
#include "text.h"

using namespace std;

class Button {

protected:
    SDL_Rect button;

    SDL_Color fillColor;
    SDL_Color hoverColor;
    SDL_Color originalColor;
    SDL_Color borderColor;
    const int hoverOffset = 50;
    
    bool mouseOver;
    const char* str;
    Text* text;
    int id;
    
public:

    Button(int x, int y, int w, int h, SDL_Color fColor, SDL_Color bColor, const char* s, int myID);

    void Update(SDL_Renderer* renderer, int mx, int my, SDL_Color textColor, TTF_Font* font, SDL_Window* currentWin);

    void Draw(SDL_Renderer* renderer, int r, int g, int b);

    int ProcessClick(float px, float py, int whichButton);

    void MouseOverBehavior(SDL_Renderer* renderer, float px, float py, SDL_Window* currentWin);

    // https://www.jeffreythompson.org/collision-detection/point-rect.php
    bool IsMouseOver(float px, float py);

    int getID();

};

#endif