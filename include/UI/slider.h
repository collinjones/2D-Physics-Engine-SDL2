#ifndef _SLIDER_
#define _SLIDER_

#include <SDL2/SDL.h>
#include <iostream>
#include "text.h"
#include "../vec2.h"

using namespace std;

class Slider {

protected:
    SDL_Rect bounds;
    Vec2 dinglePosition;
    Vec2 start; 
    Vec2 end;
    const int radius = 8;
    const int diameter = radius * 2;
    int currentValue;
    bool clicked;

public:

    Slider(int x, int y, int w, int h);

    void Draw(SDL_Renderer* renderer);

    void SetDinglePosition(int y);

    /* Constrains a between b and c */
    double Constrain(double a, double b, double c);

    // POINT/CIRCLE
    bool pointCircle(float px, float py, float cx, float cy, float r);

    bool mouseOver(int x, int y);

    void SetClicked(bool c) { clicked = c; }
    bool GetClicked() { return clicked; }
    int GetCurrentValue() { return currentValue; }

};

#endif