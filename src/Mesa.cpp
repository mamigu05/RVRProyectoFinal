#include "Mesa.hpp"
#include "Carta.hpp"

Mesa::Mesa()
{
}

void Mesa::colocarCarta(Carta* carta)
{
    ultimaCarta = carta;
    //cartasEnMesa.push_back(carta);
}

void Mesa::update()
{
    //ultimaCarta = obtenerUltimaCarta();
    if(ultimaCarta != nullptr)
        ultimaCarta->update(300, 100, 150, 250);
}

void Mesa::render()
{
    if (ultimaCarta != nullptr) {
        ultimaCarta->render();
    }
}

/*Carta* Mesa::obtenerUltimaCarta() {
    if (!cartasEnMesa.empty()) {
        return cartasEnMesa.back();
    } else {
        return nullptr;
    }
}*/
