#include "Mazo.hpp"

#include <vector>
#include <algorithm>
#include <random>

Mazo::Mazo() {
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

    // Liberar memoria del vector
    cartasVec.clear();
    cartasVec.shrink_to_fit();
}

Mazo::~Mazo(){

}

void Mazo::render(){
    // Renderizar una imagen de mazo
}

infoCarta Mazo::sacarCarta(){
    infoCarta info = cartas.front();
    cartas.pop();
    return info;
}

void Mazo::ponerCarta(int tipo, int num){
    cartas.emplace(tipo, num);
}