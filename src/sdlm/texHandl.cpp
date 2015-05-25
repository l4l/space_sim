#include <iostream>
#include "texHandl.h"


sdlm::texHandl::texHandl(){}


void sdlm::texHandl::logSDLError(std::ostream &os, const std::string &msg){
    os << msg << " error: " << SDL_GetError() << std::endl;
}


SDL_Texture* sdlm::texHandl::LoadTexture(std::string name, SDL_Renderer *ren){
    std::string typ = &name.assign("[s]") ? "star.bmp" : "planet.bmp";
    SDL_Texture *texture = nullptr;
    SDL_Surface *loadedImage = SDL_LoadBMP(sdlm::GUI::getResourcePath("space_sim").append(typ).c_str());
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


void sdlm::texHandl::RenderTexture(const std::string &name, SDL_Renderer *ren, int x, int y){
    SDL_Texture* tex = sdlm::texHandl::LoadTexture(name, ren);
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

