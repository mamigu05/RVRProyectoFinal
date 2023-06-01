#pragma once

#include <queue>

struct infoCarta {
    int tipo;
    int num;

    infoCarta(int t, int n) : tipo(t), num(n) {}
};

class Mazo{
private:
    std::queue<infoCarta> cartas;

public:
    Mazo();
    ~Mazo();
    void render();

    infoCarta sacarCarta();
    void ponerCarta(int tipo, int num);
};