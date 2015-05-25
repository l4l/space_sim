#include <iostream>
#include "handle.h"

sdlm::handle::handle() {}


void sdlm::handle::logSDLError(std::ostream &os, const std::string &msg) {
    os<<msg<<" error: "<<SDL_GetError()<<std::endl;
}

void sdlm::handle::loadFromFile(const char * fileDir, World * w) {
    std::ifstream loadFile;
    std::string name;
    phys::Vector speed;
    double mass;
    Coordinate coordinate;
    loadFile.open(fileDir);
    while(!loadFile.eof()) {
        loadFile >> name;
        loadFile >> speed;
        loadFile >> mass;
        loadFile >> coordinate;
        w->addBody(phys::Body(name, speed, mass), coordinate);
    }
    loadFile.close();
}

void sdlm::handle::clickCreator(World* w) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    int i = rand() % 6 - 3, j = rand() % 6 - 3, k = rand() % 6 - 3;
    const phys::Vector v1(i, j, k);
    const Coordinate c1(x, y, 0);
    w->addBody(phys::Body("PlanetN", v1, 10e+11), c1);

}