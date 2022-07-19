#ifndef _CIRCLE_
#define _CIRCLE_

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include "object.h"
#include "../vec2.h"
#include "boundary.h"
#include "rectangle.h"
#include "peg.h"

using namespace std;

#define SIZE_SCALAR 5 /* a scalar for the size of the circle */

class Circle: public Object {

protected:
    const double restitution = 0.9;  /* Dampening when objects collide */
    double radius;
    double diameter;

    bool collisionWithBoundary; 
    bool collisionWithCircle;
    bool topCollision; 
    bool bottomCollision;
    bool leftCollision;
    bool rightCollision;

    bool attracter = false;
    bool repulser = false;

public:

    Circle();

    Circle(Vec2 pos, Vec2 vel, double m, SDL_Color col);

    /* true for the bool means attracter and false means repulser*/
    Circle(Vec2 pos, Vec2 vel, double m, SDL_Color col, bool attractOrRepulse);

    /* Circle drawing algorithm https://stackoverflow.com/questions/28346989/drawing-and-filling-a-circle */
    void Draw(SDL_Renderer* renderer);

    /* Draws the velocity of the object represented as a line */
    void DrawVelocity(SDL_Renderer* renderer);

    /* This stackoverflow post helped me implement this code */
    /* https://stackoverflow.com/questions/16417891/how-can-i-find-a-normal-vector-of-a-2d-line */
    /* Calculate bounce vector given incoming velocity vector and normal vector */
    void LineBounce(Vec2 normal);

    void CollisionEdges(int width, int height);

    void WrapAround(int WIDTH, int HEIGHT);

    /* Checks all boundaries in list for collision */
    void CollisionBoundaries(vector<Boundary*> boundaries);

    /* Checks for a single boundary collision */
    void CollisionBoundary(Boundary boundary);

    /* Loops through a list of circles to check if this circle is colliding, then resolve */
    void CollisionCircles(vector<Circle*> circles);

    /* Loops through a list of pegs to check if this circle is colliding, then resolve */
    void CollisionPegs(vector<Peg*> pegs);

    /* Checks and resolves collisions with other rectangles */
    void CollisionRectangles(vector<Rectangle*> rectangles);

    /* This is my altered version of the collision resolution algorithm */
    void ResolveCollisionPeg(Peg* peg);


    /* https://spicyyoghurt.com/tutorials/html5-javascript-game-development/collision-detection-physics was used to get the collision resolution algorithm with impulse */
    /* and momentum. Nothing else was used, all initial physics concepts came from NoC book. */
    /* Resolves a collision with another circle */
    void ResolveCollisionCircle(Circle* circle);

    /* Constrains a between b and c */
    double Constrain(double a, double b, double c);

    /* Both Attract and Repel force algorithms come from NoC book */
    /* F = (G(m1 * m2)/r^2) * r hat */
    void Attract(Circle* circ);

    void Repel(Circle* circ);

    /*
    Fdrag = -1/2 * p * v^2 * A * Cd * v-hat (vel unit vec)
    -1/2 = opposite direction! (1/2 is irrelevant for our purpose)
    p    = greek letter rho, refers to density of liquid
    v^2  = speed of object (magnitude of velocity!)^2
    A    = Frontal area of object pushing through liquid. Since we only operate on circles, this is irrelevant. 
    Cd   = coefficient of drag! How much drag will be applied?
    v-hat= velocity vector normalized (to become a unit vector, or v-hat) 
    https://en.wikipedia.org/wiki/Drag_equation */
    // One thing we can do with this is create "water". A box with collisions turned off and a slight opacity, so that when objects pass through it, the box's drag force is applied to each object inside. 
    // Calculates a drag force to be applied to a body of mass
    void Drag(double c);

    /* KINETIC FRICTION (as opposed to static friction) */
    // Ffrict = -µ * N * v-hat
    // -µ (mu) = coefficient of friction (ice, rubber, etc)
    // N       = normal force that the object is on
    // v-hat   = velocity unit vector
    // https://en.wikipedia.org/wiki/Friction
    void Friction(int height);

    void setCollisionWithBoundary(bool collided) { collisionWithBoundary = collided; }
    void setCollisionWithCircle(bool collided) { collisionWithCircle = collided; }
    bool getCollisionWithBoundary() { return collisionWithBoundary; }
    bool getCollisionWithCircle() { return collisionWithCircle; }
    double getRadius() { return radius; }

    bool getTopCollision() { return topCollision; }
    bool getBottomCollision() { return bottomCollision; }
    bool getLeftCollision() { return leftCollision; }
    bool getRightCollision() { return rightCollision; }

    bool getAtracter(){return attracter;}
    bool getRepulser(){return repulser;}

    void resetCollisions();

};

#endif