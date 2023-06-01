#pragma once

#include <string>

class SDL_Texture;
class RenderManager;

class Carta {
private:
    int tipo;
    int num;
    RenderManager* rM;

    std::string names[6] {"Azul", "Amarillo", "Verde", "Rojo", "+4", "Comodin"};
    SDL_Texture* texture;
public:
    Carta(int tipo, int num, RenderManager* rM);
    ~Carta();
    void update();
    void render(int posX, int posY, int width, int height);
};