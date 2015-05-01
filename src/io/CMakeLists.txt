cmake_minimum_required(VERSION 3.2)
project(SimIO)

set(SRC_IO source_file.h source_file.cpp)

add_library(libio STATIC ${SRC_IO})