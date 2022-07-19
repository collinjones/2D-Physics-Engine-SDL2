
#include <SDL2/SDL.h>
#include "../../include/vec2.h"
#include "../../include/Objects/shapefactory.h"


using namespace std;

ShapeFactory::ShapeFactory(){
;
}

Circle* ShapeFactory::createCircle(Vec2 pos, Vec2 vel, double m){
    SDL_Color col;
    col.r = 255;
    col.g = 0;
    col.b = 0;
    col.a = 255;
    Circle* crc = new Circle(pos, vel, m, col);
    return crc;
}

Circle* ShapeFactory::createCircle(Vec2 pos, Vec2 vel, double m, bool attractOrRepulse){
    Circle* crc;
    if(attractOrRepulse == true)
    {
        SDL_Color col;
        col.r = 0;
        col.g = 255;
        col.b = 0;
        col.a = 255;
        crc = new Circle(pos, vel, m, col,true);
    }
    else
    {
        SDL_Color col;
        col.r = 0;
        col.g = 0;
        col.b = 255;
        col.a = 255;
        crc = new Circle(pos, vel, m, col,false);
    }
    return crc;
}

Peg* ShapeFactory::createPeg(Vec2 pos, int size){
    SDL_Color col;
        col.r = 128;
        col.g = 0;
        col.b = 128;
        col.a = 255;
    Peg* pg = new Peg(pos, size, col);
    return pg;
}

Boundary* ShapeFactory::createBoundary(Vec2 start, Vec2 end)
{
    Boundary* bound = new Boundary(start, end);
    return bound;
}

Emitter* ShapeFactory::createEmitter(double x, double y)
{
    Emitter* emit = new Emitter(x,y);
    return emit;
}

Rectangle* ShapeFactory::createRectangle (int x, int y, int w, int h)
{
    Rectangle* rect = new Rectangle(x,y,w,h);
    return rect;
}