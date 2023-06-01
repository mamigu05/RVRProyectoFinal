#include "UnoGame.hpp"

#include "RenderManager.hpp"
#include "Mazo.hpp"
#include "Player.hpp"

UnoGame::UnoGame(RenderManager* rM) : Scene() {
    renderMng = rM;

    //Prueba
    destinationRect.x = 0;
    destinationRect.y = 0;
    destinationRect.w = 200;
    destinationRect.h = 350;
    texture = renderMng->loadImage("assets/+4.png");

    m = new Mazo();
    p = new Player(m, renderMng);
    p->iniGame();
}


UnoGame::~UnoGame() {
    delete m;
    delete p;

}

void UnoGame::update() {
    // Update de las clases
    p->update();
}

void UnoGame::render() {
    // Renderizado de clases
    m->render();
    p->render();
}