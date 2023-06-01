#include "Player.hpp"

#include "Mazo.hpp"
#include "Mesa.hpp"
#include "RenderManager.hpp"

Player::Player(Mazo* mazo, RenderManager* rM, Mesa* mesa) : mazo(mazo), rM(rM), mesa(mesa) {}

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

void Player::update(SDL_Event& event) {
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
                mano[iC]->update(x, y, wC, hC);
                iC++;
            }
            x += wC;
        }
        x = 25;
        y += hC;
    }
    if (event.type == SDL_MOUSEBUTTONUP) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        for (Carta* c : mano) {
            if (c->isClicked(mouseX, mouseY)) {
                colocarCartaEnMesa(c);
                //mano.erase(it);
                break;
            }
        }
        if(mazo->isClicked(mouseX, mouseY) && !clicked)
        {
            infoCarta info = mazo->sacarCarta();
            mano.push_back(new Carta(info.tipo, info.num, rM));
            clicked = true;
        }
    }
    else
        clicked = false;  
}

void Player::render(){
    for(Carta* c : mano)
        c->render();
}

void Player::colocarCartaEnMesa(Carta* carta)
{
    mesa->colocarCarta(carta);
}