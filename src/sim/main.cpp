#include <GUI.h>
#include "serializator.h"
#include "consts.h"
#include "printer.h"

#include "iostream"
#include "fstream"

void looper(std::istream&, std::ostream&, World);

int main(int argc, char *argv[]) {

    bool isGui = true;
    bool isIn = false;
    bool isBIn = false;
    bool isOut = false;

    std::ifstream in; in.setf(std::ios::scientific); std::cin.setf(std::ios::scientific);
    std::ofstream out; out.setf(std::ios::scientific); std::cout.setf(std::ios::scientific);

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            std::string s(argv[i]);
            if (DEBUG) std::cout<<'\t'<<s<<std::endl;

            if (!isGui &&
                (s == "-gui" ||
                 s == "-g"))
                isGui = true;
            else if (isGui &&
                     (s == "-c" ||
                      s == "--console" ||
                      s == "-console"))
                isGui = false;

            if (s.find("-i", 0) == 0 && !isIn && !isBIn) {
                in.open(s.substr(2), std::ios::in);
                isIn = in.is_open();
            } else if (s.find("-bi", 0) == 0 && !isBIn) { //binary
                in.open(s.substr(3), std::ios::binary);
                isBIn = in.is_open();
            } else if (s.find("-o", 0) == 0 && !isOut) {
                out.open(s.substr(2), std::ios::out);
                isOut = out.is_open();
            }
        }
    }

    World world(0.3);
    if (isBIn)
        in>>world;

    // Test
    const phys::Vector v1(0,0,0), v2(0,0,0);
    const Coordinate c1(500,500,0), c2(450,450,0);
    world.addBody(phys::Body("Planet111", v1, 10e+11), c1);
    world.addBody(phys::Body("Planet222", v2, 10e+11), c2);
 //   world.addBody(phys::Body("Planet333", v3, 10e+11), c3);


    //looper((isIn ? in : std::cin),
          // (isOut ? out : std::cout),
          // world);
    if (isGui) {
        sdlm::GUI gui(0);
        gui(&world);
    }
    return 0;
}

void looper(std::istream &in, std::ostream &out, World world) {

    std::string ln;

_loop:
    while (!in.eof()) {
        in>>ln;
        char first = ln[0];
        if (first == 'h' || ln == "help") {
            out<<help()<<std::endl;
        } else if (first == 'p'){
            out<<print(world)<<std::endl;
        } else if (first == 't') {
            unsigned long time = 1;
            if (ln.size() != 1)
                time = std::stoul(ln.substr(1, ln.size()-1));
            while (time-- > 0)
                world.tick();
        } else if (first == 'i') {
            long num = std::stoul(ln.substr(1, ln.size()-1));
            if (num < world.getObjects().size() && num >= 0)
                out<<print(world.getObjects().at(num));
        } else if (first == 'n') {
            std::string name = ln.substr(1, ln.size()-1);
            auto obj = world.getObjects();
            for (int i = 0; i < obj.size(); ++i) {
                if (obj[i].getBody().getName() == name) {
                    out<<"ID: "<<i<<std::endl;
                    goto _loop; //None of us are perfect
                }
            }
        } else if (first == 'a' | first == 's') {
            std::string name;
            phys::Vector speed;
            double mass;
            Coordinate coordinate;

            if (first == 'a') out<<"Enter name: ";
            in>>name;
            if (first == 'a') out<<"Enter vector speed: ";
            in>>speed;
            if (first == 'a') out<<"Enter object mass: ";
            in>>mass;
            if (first == 'a') out<<"Enter coordinate of object: ";
            in>>coordinate;
            world.addBody(phys::Body(name, speed, mass), coordinate);

        } else if (first == 'd') {
            long num = std::stoul(ln.substr(1, ln.size()-1));
            if (num < world.getObjects().size() && num >= 0)
                world.removeBody(num);
        } else if (first == 'q' || ln == "quit")
            return;
    }

}