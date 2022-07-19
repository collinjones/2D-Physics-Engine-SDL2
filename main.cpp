#include "include/simulation.h"

int main(int argv, char** args) {

    Simulation physics_engine;

    // Check for any initialization errors
    if(physics_engine.CheckForErrors()) return EXIT_FAILURE;
    physics_engine.MainLoop();

    return EXIT_SUCCESS;
}