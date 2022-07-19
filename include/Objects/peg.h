/* A peg is a circle object that does not move, it is static */
#ifndef _PEG_
#define _PEG_

#include <SDL2/SDL.h>
#include "../vec2.h"

class Peg {

private:

    Vec2 position;
    Vec2 velocity;
    double radius;
    double mass;
    double diameter;
    SDL_Color color;

public:

    Peg(Vec2 pos, double m, SDL_Color col);

    /* Circle drawing algorithm https://stackoverflow.com/questions/28346989/drawing-and-filling-a-circle */
    void Draw(SDL_Renderer* renderer);

    Vec2 getPos() { return position; }
    Vec2 getVel() { return velocity; }
    double getRadius() { return radius; }
    double getMass() { return mass; }
    

};

#endif
