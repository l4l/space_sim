#include "serializator.h"
#include "consts.h"
#include "printer.h"

#include "iostream"
#include "fstream"

void looper(std::istream&, std::ostream&, World);

int main(int argc, char const *argv[]) {

    bool isGui = false;
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

    World world(DEF_TIME);
    if (isBIn)
        in>>world;

    if (!isGui)
        looper((isIn ? in : std::cin),
               (isOut ? out: std::cout),
               world);
    else {
        //Create window and so on..
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
            ulong time = 1;
            if (ln.size() != 1)
                time = std::stoul(ln.substr(1, ln.size()-1));
            while (time-- > 0)
                world.tick();
        } else if (first == 'i') {
            ulong num = std::stoul(ln.substr(1, ln.size()-1));
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
            ulong num = std::stoul(ln.substr(1, ln.size()-1));
            if (num < world.getObjects().size() && num >= 0)
                world.removeBody(num);
        } else if (first == 'q' || ln == "quit")
            return;
    }

}
