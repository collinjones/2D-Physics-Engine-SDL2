/* An emitter is just an object that spits many other objects */

#ifndef _EMITTER_
#define _EMITTER_

#include <SDL2/SDL.h>
#include "circle.h"
#include "../vec2.h"

class Emitter {

private:

    Vec2 pos;
    int numObjects;

public:

    Emitter(double x, double y);

    void Emit(vector<Circle*> *circles);
};

#endif