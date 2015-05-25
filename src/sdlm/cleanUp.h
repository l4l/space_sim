#ifndef CLEANUP_H
#define CLEANUP_H

#include <bits/move.h>
#include <SDL.h>

template<typename T, typename... Argument>
void cleanup(T *t, Argument&&... argument){
	cleanup(t);
	cleanup(std::forward<Argument>(argument)...);
}

template<>
void cleanup(SDL_Window *win);

template<>
void cleanup(SDL_Renderer *ren);

template<>
void cleanup(SDL_Texture *tex);

template<>
void cleanup(SDL_Surface *surf);

#endif
