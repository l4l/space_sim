cmake_minimum_required(VERSION 3.2)
project(SimGUI)

include_directories(${SimPhycics_SOURCE_DIR})

set(SRC_SDLM initSDL.cpp renderer.cpp
     GUI.cpp GUI.h event.cpp loop.cpp
      handle.cpp handle.h getResourcePath.cpp
      cleanUp.h cleanUp.cpp )


add_library(sdlm ${SRC_SDLM}  )


include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(sdlm ${SDL2_LIBRARIES})