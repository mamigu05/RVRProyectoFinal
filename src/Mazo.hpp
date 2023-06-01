#pragma once

#include <queue>
#include <SDL2/SDL.h>

class RenderManager;

struct infoCarta {
    int tipo;
    int num;

    infoCarta(int t, int n) : tipo(t), num(n) {}
};

class Mazo{
private:
    std::queue<infoCarta> cartas;
    SDL_Texture* texture;
    SDL_Rect* destRect;
    RenderManager* rM;
public:
    Mazo(RenderManager* rM);
    ~Mazo();
    void render();

    infoCarta sacarCarta();
    void ponerCarta(int tipo, int num);
    bool isClicked(int mouseX, int mouseY);
};