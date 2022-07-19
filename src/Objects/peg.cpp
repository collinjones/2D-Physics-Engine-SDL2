#include "../../include/Objects/peg.h"
#include "../../include/vec2.h"
#include <SDL2/SDL.h>

Peg::Peg(Vec2 pos, double m, SDL_Color col) {
    position = pos;
    mass = m;
    radius = 3 * mass;
    diameter = 2 * radius;
    color = col;
    velocity.setVec(0, 0);
}

/* Circle drawing algorithm https://stackoverflow.com/questions/28346989/drawing-and-filling-a-circle */
void Peg::Draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < diameter; w++) {
        for (int h = 0; h < diameter; h++) {
            double dx = radius - w;
            double dy = radius - h;
            if ( (dx*dx + dy*dy) <= (radius * radius) ) {
                SDL_RenderDrawPoint(renderer, position.getX() + dx, position.getY() + dy);
            }
        }
    }
}
