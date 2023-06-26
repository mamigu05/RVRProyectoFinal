#include "UnoGame.hpp"

#include "RenderManager.hpp"
#include "NetManager.hpp"
#include "Mazo.hpp"
#include "Player.hpp"
#include "Mesa.hpp"

UnoGame::UnoGame(RenderManager* rM, NetManager* nM) : Scene() {
    renderMng = rM;
    netMng = nM;

    if(netMng->isServer())
        myTurn = true;
    else
        myTurn = false;

    m = new Mazo(renderMng);
    table = new Mesa();
    p = new Player(m, renderMng, netMng, table);
    p->iniGame();
    infoCarta info = m->sacarCarta();
    if(!netMng->isServer())
    {
        table->colocarCarta(new Carta(info.tipo, info.num, renderMng));
        netMng->sendCard(info.tipo, info.num, true);
    }
}


UnoGame::~UnoGame() {
    delete m;
    delete p;

}

void UnoGame::update(SDL_Event& event) {
    // Update de las clases
    if(myTurn)
    {
        p->update(event);
    }

    table->update();

    NetMessage* nm = netMng->getMessage();
    NetMessage* message = nm;
    message->newTurn = nm->newTurn;
    if(message != nullptr)
    {
        //myTurn = message->newTurn;
        //int color = nm->color;
        //int number = nm->number;
        //table->colocarCarta(new Carta(nm->color, nm->number, renderMng));
        //nm = nullptr;
    }
}

void UnoGame::render() {
    // Renderizado de clases
    m->render();
    p->render();
    table->render();
}