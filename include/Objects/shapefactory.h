#ifndef _CIRCLEFACTORY_
#define _CIRCLEFACTORY_

#include <iostream>
#include <string>
#include "../vec2.h"
#include "circle.h"
#include "peg.h"
#include "emitter.h"
#include "rectangle.h"
#include "boundary.h"


using namespace std;

class ShapeFactory{

    public:
        ShapeFactory();

        Circle* createCircle(Vec2 pos, Vec2 vel, double m);

        Circle* createCircle(Vec2 pos, Vec2 vel, double m, bool attractOrRepulse);

        Peg* createPeg(Vec2 pos, int size);

        Boundary* createBoundary(Vec2 start, Vec2 end);

        Emitter* createEmitter(double x, double y);

        Rectangle* createRectangle (int x, int y, int w, int h);
};

#endif