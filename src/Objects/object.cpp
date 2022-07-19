#include <SDL2/SDL.h>
#include <vector>
#include "../../include/vec2.h"
#include "../../include/vecMath.h"
#include "../../include/Objects/object.h"

Object::Object(Vec2 pos, Vec2 vel, double m, SDL_Color col) {
    position = pos;
    velocity = vel;
    acceleration = Vec2(0, 0);
    mass = m;
    color = col;
}

Object::Object () {
    ;
}

/* Newton's Second Law: Force = Mass * Acceleration, or Acceleration = Force / Mass */
void Object::ApplyForce(Vec2 gravity) {
    /* == AN OBJECT FALLS (GRAVITY) AT THE SAME ACCELERATION INDEPENDENT OF ITS MASS == 
    *
    *  Without multiplying gravity with an objects mass, this gravity force being
    *      applied will be divided with the objects mass in the ApplyForce method, 
    *      causing gravity to act differently on each object. Galileo proved that 
    *      objects will fall with the same acceleration (gravity, in this case), 
    *      regardless of its mass. This new force is the objects weight.
    */
    Vec2 weight = VecMath::mult(gravity, mass);
    weight.divide(mass);  /* Divide by the mass of the object */
    acceleration.add(weight); /* We add, not set, here so that multiple forces can affect the object */
}

void Object::Update() {
    /* Euler integration algorithm:
    *   1. Add acceleration to velocity
    *   2. Add velocity to position 
    *   3. Clear the (set to 0) acceleration (acceleration DOES NOT accumulate)
    */
    velocity.add(acceleration);
    position.add(velocity);
    acceleration.setVec(0, 0); // or acceleration.mult(0);
}

void Object::debugging_setCircleToMouse() {
    int posX;
    int posY;
    SDL_GetMouseState(&posX, &posY);
    position.setVec(posX, posY);
}