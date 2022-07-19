/* A rectangle object that interacts with circle objects */
#ifndef _RECTANGLE_
#define _RECTANGLE_

#include <SDL2/SDL.h>
#include "boundary.h"
#include "../vec2.h"

class Rectangle {

private:
    SDL_Rect rect;
    
public:
    Rectangle(int x, int y, int w, int h);

    void Draw(SDL_Renderer* renderer);

    void Fill(SDL_Renderer* renderer);

    bool CollisionWithCircle(int cx, int cy, double rad, bool* leftCollision, bool* rightCollision, bool* topCollision, bool* bottomCollision);

    SDL_Rect getRect() { return rect; }

    
};

#endif