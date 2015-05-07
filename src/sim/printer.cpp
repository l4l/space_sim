#include "printer.h"

#include "iostream"
#include "sstream"

#define DBNL std::endl<<std::endl

std::string help() {
    return std::string("\nHelp description.\n\n\th - prints this help\n\t"
                               "help - same as h\n\t"
                               "p - prints current state of world\n\t"
                               "t%NUM% - make %NUM% ticks of world\n\t"
                               "t - same as t1\n\t"
                               "i%NUM% - get info about %NUM%-th object\n\t"
                               "n%TEXT% - get id of object with name %TEXT%\n\t"
                               "a - opens interactive object adding tool\n\t"
                               "s - same as \"a\" but more silently\n\t"
                               "d%NUM% - delete %NUM%-th object\n\t"
                               "q - quit(also work \"quit\" and EOF)"
                               "\nID dont link staticly to the special object "
                               "so make sure that you call correct id\n");
}

std::string print(const Coordinate &coordinate) {
    if (DEBUG) std::cout<<"\n\tNow at print(Coordinate&)\n";
    std::stringstream str("");
    str<<std::scientific;
    str<<"X: "<<std::to_string(coordinate.getX())
     <<", Y: "<<std::to_string(coordinate.getY())
     <<", Z: "<<std::to_string(coordinate.getZ());
    return str.str();
}

std::string print(const phys::Vector &vector) {
    if (DEBUG) std::cout<<"\n\tNow at print(phys::Vector&)\n";
    auto c = vector.getEnd();
    return print(c);
}

std::string print(const phys::Body &body) {
    if (DEBUG) std::cout<<"\n\tNow at print(phys::Body&)\n";
    auto s = body.getSpeed();
    std::stringstream str("");
    str<<std::scientific;
    str<<"Name: "<<body.getName()<<std::endl
       <<"Mass: "<<std::to_string(body.getMass())<<std::endl
       <<"Speed: "<<print(s)<<std::endl;
    return str.str();
}

std::string print(const World::Object &object) {
    if (DEBUG) std::cout<<"\n\tNow at print(World::Object&)\n";
    auto b = object.getBody();
    auto c = object.getCoord();
    std::stringstream str("");
    str<<print(b)<<"Coords: "<<print(c);
    return str.str();
}

std::string print(const World &world) {
    if (DEBUG) std::cout<<"\n\tNow at print(World&)\n";
    std::stringstream str("");
    str<<"*** World description"<<DBNL
       <<"dt = "<<std::scientific<<std::to_string(world.getDt())<<DBNL;
    auto obj = world.getObjects();
    for (int i = 0; i < obj.size(); ++i) {
        str<<"*** ID: "<<std::to_string(i)<<std::endl
           <<print(obj[i]);
    }
    str<<std::endl<<"*** End desc."<<DBNL;
    return str.str();
}
