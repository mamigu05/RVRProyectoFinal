#include "UnoGame.hpp"

#include "RenderManager.hpp"
#include "Mazo.hpp"
#include "Player.hpp"
#include "Mesa.hpp"

UnoGame::UnoGame(RenderManager* rM) : Scene() {
    renderMng = rM;

    //Prueba
    destinationRect.x = 0;
    destinationRect.y = 0;
    destinationRect.w = 200;
    destinationRect.h = 350;
    texture = renderMng->loadImage("assets/+4.png");

    m = new Mazo(renderMng);
    table = new Mesa();
    p = new Player(m, renderMng, table);
    p->iniGame();
}


UnoGame::~UnoGame() {
    delete m;
    delete p;

}

void UnoGame::update(SDL_Event& event) {
    // Update de las clases
    p->update(event);
}

void UnoGame::render() {
    // Renderizado de clases
    m->render();
    p->render();
    table->render();
}