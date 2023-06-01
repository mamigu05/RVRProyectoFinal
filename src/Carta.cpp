#include "Carta.hpp"

#include <SDL2/SDL.h>
#include "RenderManager.hpp"

Carta::Carta(int tipo, int num, RenderManager* rM) : tipo(tipo), num(num), rM(rM) {

    std::string filename = "assets/" + names[tipo];

    if(tipo < 4){
        if(num < 10)
            filename += std::to_string(num);
        else if(num == 10)
            filename += "+2";
        else if(num == 11)
            filename += "Prohibido";
        else if(num == 12)
            filename += "Flechas";
    }

    filename += ".png";

    texture = rM->loadImage(filename.c_str());
}

Carta::~Carta(){
    rM->deleteTexture(texture);
}

void Carta::update() {
    // Si clican sacarlo a la mesa
}

void Carta::render(int posX, int posY, int width, int height){
    SDL_Rect destRect;
    destRect.x = posX;
    destRect.y = posY;
    destRect.w = width;
    destRect.h = height;

    rM->renderImage(texture, &destRect);
}