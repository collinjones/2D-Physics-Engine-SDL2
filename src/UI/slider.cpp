#include "../../include/UI/slider.h"

Slider::Slider(int x, int y, int w, int h) {
    bounds.x = x;
    bounds.y = y;
    bounds.w = w;
    bounds.h = h;
    clicked = false;
    currentValue = 1;
    
    dinglePosition.setX(x);
    dinglePosition.setY(y);
    start.setX(x);
    start.setY(y);
    end.setX(x);
    end.setY(y + h);
}

void Slider::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer,220,220,220,255);
    SDL_RenderDrawLine(renderer, (int) start.getX(), (int) start.getY(), (int) end.getX(), (int) end.getY());
    SDL_SetRenderDrawColor(renderer,160,160,160,255);
    for (int w = 0; w < diameter; w++) {
        for (int h = 0; h < diameter; h++) {
            double dx = radius - w;
            double dy = radius - h;
            if ( (dx*dx + dy*dy) <= (radius * radius) ) {
                SDL_RenderDrawPoint(renderer, dinglePosition.getX() + dx, dinglePosition.getY() + dy);
            }
        }
    }
}

void Slider::SetDinglePosition(int y) {
    dinglePosition.setY(Constrain(y, start.getY(), start.getY() + bounds.h));
    int result =  1 + (100 - 1) * ((dinglePosition.getY() - start.getY()) / (end.getY() - start.getY()));
    currentValue = result;
}

/* Constrains a between b and c */
double Slider::Constrain(double a, double b, double c)
{
    if (a<b)
        return b;
    else if(a > c)
        return c;
    else
        return a;
}

// POINT/CIRCLE
bool Slider::pointCircle(float px, float py, float cx, float cy, float r) {
    // get distance between the point and circle's center
    // using the Pythagorean Theorem
    float distX = px - cx;
    float distY = py - cy;
    float distance = sqrt( (distX*distX) + (distY*distY) );

    // if the distance is less than the circle's
    // radius the point is inside!
    if (distance <= r) {
        return true;
    }
    return false;
}

bool Slider::mouseOver(int x, int y){ 
    return pointCircle(x, y, dinglePosition.getX(), dinglePosition.getY(), radius);
}
