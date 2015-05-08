cmake_minimum_required(VERSION 3.2)
project(SpaceSim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BASE "${CMAKE_SOURCE_DIR}/src")
set(PHYS_DIR ${BASE}/phys)
set(SDLM_DIR ${BASE}/sdlm)
set(APP_DIR ${BASE}/sim)

add_subdirectory(${PHYS_DIR})
add_subdirectory(${SDLM_DIR})

include_directories(${PHYS_DIR})
include_directories(${SDLM_DIR})
include_directories(${APP_DIR})

FILE(GLOB SRCS src/sim/*.cpp
               src/sim/*.h)

add_executable(SpaceSim ${SRCS} )


include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(SpaceSim ${SDL2_LIBRARIES})

target_link_libraries(SpaceSim phys)
target_link_libraries(SpaceSim sdlm)