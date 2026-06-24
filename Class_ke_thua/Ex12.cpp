#include <iostream>
using namespace std;

class Artist {
protected:
    int creativity;
public:
    Artist(int c = 0) : creativity(c) {}
    void draw() {
        cout << "Artist draws with creativity = " << creativity << endl;
    }
};

class Coder {
protected:
    int logic;
public:
    Coder(int l = 0) : logic(l) {}
    void code() {
        cout << "Coder writes logic = " << logic << endl;
    }
};

class GameDev : public Artist, public Coder {
public:
    GameDev(int c, int l) : Artist(c), Coder(l) {}
    void develop() {
        draw();
        code();
        cout << "GameDev is developing a game." << endl;
    }
};

int main() {
    GameDev gd(8, 10);
    gd.draw();
    gd.code();
    gd.develop();
    return 0;
}
