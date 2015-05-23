#include <iostream>
#include "handle.h"


sdlm::handle::handle() {}


void sdlm::handle::logSDLError(std::ostream &os, const std::string &msg) {
    os<<msg<<" error: "<<SDL_GetError()<<std::endl;
}


SDL_Texture* sdlm::handle::LoadTexture(std::string name, SDL_Renderer *ren) {
    std::string typ = &name.assign("[s]") ? "star.bmp" : "planet.bmp";
    SDL_Texture *texture = nullptr;
    SDL_Surface *loadedImage;
    loadedImage = SDL_LoadBMP("C:\\Users\\ono\\Desktop\\space_sim\\src\\items\\planet.bmp");
    if (loadedImage != nullptr){
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == nullptr){
            logSDLError(std::cout, "CreateTextureFromSurface");
        }
    }
    else {
        logSDLError(std::cout, "LoadBMP");
    }
    return texture;
}


void sdlm::handle::RenderTexture(const std::string &name,
                                 SDL_Renderer *ren,
                                 int x, int y) {
    SDL_Texture* tex = sdlm::handle::LoadTexture(name, ren);
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(tex, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, nullptr, &dst);
}

