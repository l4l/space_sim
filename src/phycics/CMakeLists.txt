cmake_minimum_required(VERSION 3.2)
project(SimPhycics)

set(SRC_PHYS source_file.h source_file.cpp)

add_library(libphys ${SRC_PHYS})