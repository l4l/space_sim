#include "GUI.h"

sdlm::GUI::GUI() : delay(0), screen(nullptr), running(initSDL()) {}
sdlm::GUI::GUI(unsigned int dt) : delay(dt), screen(nullptr), running(initSDL()) {}

int sdlm::GUI::operator()(World *w) {
    SDL_Event ev;
    std::vector<World::Object> objects;
    initTexture();


    while(running) {
        objects = w->getObjects();

        while(SDL_PollEvent(&ev)) {
            event(&ev);
        }

        for(World::Object o: objects){
            prepare(o.getBody().getName(),
                    o.getCoord().getX(),
                    o.getCoord().getY());
        }

        renderer();
        SDL_Delay(delay);
        w->tick();
    }
    return 0;
}

void sdlm::GUI::initTexture() {
    SDL_Surface *loadedImage;
    loadedImage = SDL_LoadBMP("C:\\Users\\ono\\Desktop\\space_sim\\src\\items\\planet.bmp");
    if (loadedImage != nullptr){
        tex = SDL_CreateTextureFromSurface(render, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (tex == nullptr)
            sdlm::handle::logSDLError(std::cout, "CreateTextureFromSurface");
    }
    else
        sdlm::handle::logSDLError(std::cout, "LoadBMP");
    SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
}

void sdlm::GUI::prepare(std::string const name, double x, double y) {
    dst.x = (int)x;
    dst.y = (int)y;
    SDL_RenderCopy(render, tex, nullptr, &dst);
}
