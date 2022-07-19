#ifndef _TOGGLEBUTTON_
#define _TOGGLEBUTTON_

#include <SDL2/SDL.h>
#include <iostream>
#include "button.h"

using namespace std;

class ToggleButton : public Button {

private:
    bool activated;
    SDL_Color onColor;
    SDL_Color offColor;
    const char* offText;
    const char* onText;
    int id;
    
public:

    ToggleButton(int x, int y, int w, int h, SDL_Color fColor, SDL_Color bColor, const char* str, const char* toggleStr, int myID);

    int ProcessClick(float px, float py);

    void Update(SDL_Renderer* renderer, int mx, int my, SDL_Color textColor, TTF_Font* font, SDL_Window* currentWin);

    void SetClickedColor();

    void SetUnclickedColor();

    void Draw(SDL_Renderer* renderer, int r, int g, int b);

    int getID() { return id; }
};

#endif