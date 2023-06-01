#include "Mazo.hpp"
#include "RenderManager.hpp"
#include <vector>
#include <algorithm>
#include <random>

Mazo::Mazo(RenderManager* rM) : rM(rM) {
    destRect = new SDL_Rect();
    destRect->x = 10;
    destRect->y = 5;
    destRect->w = 150;
    destRect->h = 250;
    std::string filename = "assets/Comodin.png";
    std::vector<infoCarta> cartasVec;
    cartasVec.reserve(60);

    for(int tipo = 0; tipo < 4; tipo++)
        for(int num = 0; num < 13; num++)
            cartasVec.emplace_back(tipo, num);

    for(int tipo = 4; tipo < 6; tipo++)
        for(int i = 0; i < 4; i++)
            cartasVec.emplace_back(tipo, -1);

    // Obtener un generador de números aleatorios
    std::random_device rd;
    std::mt19937 g(rd());

    // Aleatorizar el vector utilizando std::shuffle
    std::shuffle(cartasVec.begin(), cartasVec.end(), g);

    for (const auto& carta : cartasVec) {
        cartas.emplace(carta.tipo, carta.num);
    }
    texture = rM->loadImage(filename.c_str());
    

    // Liberar memoria del vector
    cartasVec.clear();
    cartasVec.shrink_to_fit();
}

Mazo::~Mazo(){
    rM->deleteTexture(texture);
} 

void Mazo::render(){
    rM->renderImage(texture, destRect);
}

infoCarta Mazo::sacarCarta(){
    infoCarta info = cartas.front();
    cartas.pop();
    return info;
}

void Mazo::ponerCarta(int tipo, int num){
    cartas.emplace(tipo, num);
}

bool Mazo::isClicked(int mouseX, int mouseY)
{
    return (mouseX >= destRect->x && mouseX < (destRect->x + destRect->w) &&
            mouseY >= destRect->y && mouseY < (destRect->y + destRect->h));
}