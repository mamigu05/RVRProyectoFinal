#include "Player.hpp"

#include "Mazo.hpp"
#include "RenderManager.hpp"

Player::Player(Mazo* mazo, RenderManager* rM) : mazo(mazo), rM(rM) {}

Player::~Player() {
    for(Carta* c : mano) {
        delete c; c = nullptr;
    }

    mano.clear();
}

void Player::iniGame() {
    for(int i = 0; i < 7; i++) {
        infoCarta info = mazo->sacarCarta();
        mano.push_back(new Carta(info.tipo, info.num, rM));
    }
}

void Player::update() {
    for(Carta* c : mano)
        c->update();
}

void Player::render(){
    int numCartas = mano.size();

    float proporcion = 750 / numCartas;

    int filas = proporcion < 38 ? 2 : 1;
    int columnas = numCartas % 2 == 0 ? numCartas / filas : (numCartas / filas) + 1;

    int wC = filas == 1 ?
            ((int) proporcion > 75 ?
                                75
                                : (int) proporcion)
            : 37;

    int hC = wC * 2;
    int x = 25; int y = 425;


    int iC = 0;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(iC < numCartas){
                mano[iC]->render(x, y, wC, hC);
                iC++;
            }
            x += wC;
        }
        x = 25;
        y += hC;
    }
}