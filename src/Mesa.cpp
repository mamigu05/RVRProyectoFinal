#include "Mesa.hpp"
#include "Carta.hpp"

Mesa::Mesa()
{
}

void Mesa::colocarCarta(Carta* carta)
{
    cartasEnMesa.push_back(carta);
}

void Mesa::update()
{

}

void Mesa::render()
{
    Carta* ultimaCarta = obtenerUltimaCarta();
    if (ultimaCarta != nullptr) {
        // Define las coordenadas y dimensiones de la posición donde deseas renderizar la última carta
        ultimaCarta->update(300, 100, 150, 250);
        ultimaCarta->render();
    }
}

Carta* Mesa::obtenerUltimaCarta() {
    if (!cartasEnMesa.empty()) {
        return cartasEnMesa.back();
    } else {
        return nullptr;
    }
}
