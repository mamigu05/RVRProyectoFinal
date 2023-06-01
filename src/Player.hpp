#pragma once

#include <vector>
#include "Carta.hpp"

class Mazo;
class RenderManager;

class Player {
private:
    Mazo* mazo;
    RenderManager* rM;
    std::vector<Carta*> mano;

public:
    Player(Mazo* mazo, RenderManager* rM);
    ~Player();

    void iniGame();

    void update();
    void render();
};