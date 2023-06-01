#pragma once

#include <string>
#include <SDL2/SDL.h>

class RenderManager;

class Carta {
private:
    int tipo;
    int num;
    RenderManager* rM;

    std::string names[6] {"Azul", "Amarillo", "Verde", "Rojo", "+4", "Comodin"};
    SDL_Texture* texture;
    SDL_Rect* destRect;
public:
    Carta(int tipo, int num, RenderManager* rM);
    ~Carta();
    void update(int posX, int posY, int width, int height);
    void render();
    bool isClicked(int mouseX, int mouseY);
};