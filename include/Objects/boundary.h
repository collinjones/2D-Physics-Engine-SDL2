/* A boundary object is a line from posA to posB */
#ifndef _BOUNDARY_
#define _BOUNDARY_ 

#include <SDL2/SDL.h>
#include "../vec2.h"
#include <iostream>
using namespace std;

class Boundary {
private:
    Vec2 start;
    Vec2 end;
    double len;
    Vec2 normal;

public:

    Boundary ();

    Boundary (Vec2 start, Vec2 end);

    void Setup();

    void Draw (SDL_Renderer* renderer);

    /* https://www.jeffreythompson.org/collision-detection/circle-circle.php */
    bool CircleIntersect(Vec2 pos, double rad);

    /* https://www.jeffreythompson.org/collision-detection/circle-circle.php */
    bool PointIntersect(Vec2 point);
    /* https://www.jeffreythompson.org/collision-detection/line-circle.php */
    void CalcLineNormal();

    void setStart(int x, int y);

    void setEnd(int x, int y);

    double getLen() { return len; }
    Vec2 getStart() { return start; }
    Vec2 getEnd() { return end; }
    Vec2 getNormal() { return normal; }

};

#endif