#include "UnoGame.hpp"
#include "RenderManager.hpp"

UnoGame::UnoGame(RenderManager* rM) : Scene() {
    renderMng = rM;

    //Prueba
    destinationRect.x = 0;
    destinationRect.y = 0;
    destinationRect.w = 200;
    destinationRect.h = 350;
    texture = renderMng->loadImage("assets/+4.png");
}


UnoGame::~UnoGame() {
    //Prueba
    renderMng->deleteTexture(texture);
}

void UnoGame::update() {
    //Prueba
    destinationRect.x = destinationRect.x + 1 == 400 ?
                                    0 : destinationRect.x+1;

    // Update de las clases
}

void UnoGame::render() {
    //Prueba
    renderMng->renderImage(texture, &destinationRect);

    // Renderizado de clases
}