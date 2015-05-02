cmake_minimum_required(VERSION 3.2)
project(SimPhycics)

set(SRC_PHYS Object.cpp Object.h
             Coordinate.cpp Coordinate.h
             Vector.cpp Vector.h)

add_library(libphys ${SRC_PHYS})