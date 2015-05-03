cmake_minimum_required(VERSION 3.2)
project(SimPhycics)

set(SRC_PHYS Body.cpp Body.h
             Coordinate.cpp Coordinate.h
             Vector.cpp Vector.h
             World.cpp World.h)

add_library(phys ${SRC_PHYS})