#pragma once

#include <vector>
#include "Carta.hpp"

class Mazo;
class Mesa;
class RenderManager;
class NetManager;

class Player {
private:
    Mazo* mazo;
    Mesa* mesa;
    RenderManager* rM;
    NetManager* nM;
    std::vector<Carta*> mano;
    bool clicked = false;

public:
    Player(Mazo* mazo, RenderManager* rM, NetManager* nM, Mesa* mesa);
    ~Player();

    void iniGame();

    void update(SDL_Event& event);
    void render();

    void colocarCartaEnMesa(Carta* Carta);
};