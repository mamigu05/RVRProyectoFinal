#include "Carta.hpp"

#include "RenderManager.hpp"

Carta::Carta(int tipo, int num, RenderManager* rM) : tipo(tipo), num(num), rM(rM) {

    std::string filename = "assets/" + names[tipo];

    destRect = new SDL_Rect();

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

void Carta::update(int posX, int posY, int width, int height) {
    destRect->x = posX;
    destRect->y = posY;
    destRect->w = width;
    destRect->h = height;
}

void Carta::render(){
    rM->renderImage(texture, destRect);
}

bool Carta::isClicked(int mouseX, int mouseY)
{
    return (mouseX >= destRect->x && mouseX < (destRect->x + destRect->w) &&
            mouseY >= destRect->y && mouseY < (destRect->y + destRect->h));
}