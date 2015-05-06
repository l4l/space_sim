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

    std::ifstream in;
    std::ofstream out;

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

    World world(0);
    if (isBIn) {
        in>>world;
    }

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
    World *w;
    if (&world == 0)
        w = new World(DEF_TIME);
    else
        w = new World(world);

    std::string ln;

    while (!in.eof()) {
        in>>ln;
        if (ln == "h" || ln == "help") {
            out<<help();
            out<<std::endl;
        } else if (ln == "p"){
            out<<print(world);
            out<<std::endl;
        } else if (ln == "t") {
            w->tick();
        }
    }

    delete w;
}
