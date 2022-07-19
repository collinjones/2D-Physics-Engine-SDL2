#ifndef _OBJECT_
#define _OBJECT_ 

#include <SDL2/SDL.h>
#include <vector>
#include "../vec2.h"
#include "../vecMath.h"

class Object {

    protected:
        Vec2 position; 
        Vec2 velocity;
        Vec2 acceleration;
        double mass;
        SDL_Color color; 
           

    public:

        Object(Vec2 pos, Vec2 vel, double m, SDL_Color col);

        Object ();

        /* Newton's Second Law: Force = Mass * Acceleration, or Acceleration = Force / Mass */
        void ApplyForce(Vec2 gravity);

        void Update();

        void subVel(Vec2 vel) { velocity.sub(vel); }
        void setVel(Vec2 vel) { velocity = vel; }
        
        Vec2 getPos() { return position; }
        Vec2 getVel() { return velocity; }
        Vec2 getAcc() { return acceleration; }
        double getMass() { return mass; }

        void debugging_setCircleToMouse();
        
        void Draw(SDL_Renderer* renderer);
};

#endif