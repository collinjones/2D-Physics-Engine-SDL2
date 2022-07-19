#include <SDL2/SDL.h>
#include <iostream>

#include "../../include/Objects/boundary.h"
#include "../../include/vec2.h"
using namespace std;


Boundary::Boundary () {
    ;
}

Boundary::Boundary (Vec2 start, Vec2 end) {
    this->start = start;
    this->end = end;
    len = start.Distance(end);
    CalcLineNormal();
}

void Boundary::Setup() {
    len = start.Distance(end);
    CalcLineNormal();
}

void Boundary::Draw (SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawLine(renderer, start.getX(), start.getY(), end.getX(), end.getY());
}

/* https://www.jeffreythompson.org/collision-detection/circle-circle.php */
bool Boundary::CircleIntersect(Vec2 pos, double rad) {

    /* Check if either end intesects the circle */
    bool inside1 = start.IntersectCircle(pos, rad);
    bool inside2 = end.IntersectCircle(pos, rad);
    if(inside1 || inside2) {
        /* This is the reason why balls will clip through lines. Need to figure out a way to prevent that here */
        /* Maybe add a 1x1, 2x2, or 3x3 rect at either end to naturally bounce off? might cause more issues though */
        return true;
    }

    double dot = (( (pos.getX() - start.getX()) * (end.getX() - start.getX()) \
    + (pos.getY() - start.getY()) * (end.getY() - start.getY()))) / pow(len, 2);

    double closestX = start.getX() + (dot * (end.getX() - start.getX()));
    double closestY = start.getY() + (dot * (end.getY() - start.getY()));
    Vec2 closestVec(closestX, closestY);

    bool onSegment = PointIntersect(closestVec);
    if (!onSegment) {
        return false;
    }
    double distX = closestX - pos.getX();
    double distY = closestY- pos.getY();
    double distance = sqrt( (distX*distX) + (distY*distY) );

    if(distance <= rad) {
        return true;
    }
    return false;
}

/* https://www.jeffreythompson.org/collision-detection/circle-circle.php */
bool Boundary::PointIntersect(Vec2 point) {
    double dist1 = point.Distance(start);
    double dist2 = point.Distance(end);
    double buffer = 0.1;

    if (dist1 + dist2 >= len - buffer && dist1 + dist2 <= len + buffer) {
        return true;
    }
    return false;
    

}
/* https://www.jeffreythompson.org/collision-detection/line-circle.php */
void Boundary::CalcLineNormal() {
    /* Calculates and sets the normal vector of the boundary */
    double dx = end.getX() - start.getX();
    double dy = end.getY() - start.getY();
    Vec2 n(dy, -dx);

    n.Normalize();
    normal = n;
}

void Boundary::setStart(int x, int y) { 
    start.setX(x); 
    start.setY(y); 
}

void Boundary::setEnd(int x, int y) { 
    end.setX(x); 
    end.setY(y); 
}
