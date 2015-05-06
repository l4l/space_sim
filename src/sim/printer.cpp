#include "printer.h"

#include "iostream"

std::string help() {
    return std::string("\nHelp description.\n\n\th - prints this help\n\t"
                               "help - same as h\n\t"
                               "p - prints current state of world\n\t"
                               "t%NUM% - make %NUM% ticks of world\n\t"
                               "t - same as t1\n\t"
                               "i%NUM% - get info about %NUM%-th object\n\t"
                               "n%TEXT% - get id of object with name %TEXT%\n"
                               "\nID dont link staticly to the special object "
                               "so make sure that you call correct id");
}

std::string print(Coordinate &coordinate) {
    if (DEBUG) std::cout<<"\n\tNow at print(Coordinate&)\n";
    return std::string("X: ").append(std::to_string(coordinate.getX()))
                       .append(", Y: ").append(std::to_string(coordinate.getY()))
                       .append(", Z: ").append(std::to_string(coordinate.getZ())).append("\n");
}

std::string print(phys::Vector &vector) {
    if (DEBUG) std::cout<<"\n\tNow at print(phys::Vector&)\n";
    auto c = vector.getEnd();
    return print(c);
}

std::string print(phys::Body &body) {
    if (DEBUG) std::cout<<"\n\tNow at print(phys::Body&)\n";
    auto s = body.getSpeed();
    auto a = body.getAcc();
    return std::string("Name: ").append(body.getName()).append("\n")
            .append("Mass: ").append(std::to_string(body.getMass())).append("\n")
            .append("Speed: ").append(print(s)).append("\n")
            .append("Acceleration: ").append(print(a)).append("\n");
}

std::string print(World::Object &object) {
    if (DEBUG) std::cout<<"\n\tNow at print(World::Object&)\n";
    auto b = object.getBody();
    auto c = object.getCoord();
    return std::string(print(b))
            .append("Coords: ").append(print(c));
}

std::string print(World &world) {
    if (DEBUG) std::cout<<"\n\tNow at print(World&)\n";
    std::string s("*** World description\n\n");
    s.append("dt = ").append(std::to_string(world.getDt())).append("\n");
    auto obj = world.getObjects();
    for (int i = 0; i < obj.size(); ++i) {
        s.append("*** ID: ").append(std::to_string(i));
        s.append(print(obj[i]));
    }
    s.append("\n*** End desc.\n\n");
    return s;
}
