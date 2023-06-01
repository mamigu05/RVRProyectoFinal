#pragma once

#include "Scene.hpp"
#include <SDL2/SDL.h>

class RenderManager;
class Mazo;
class Player;
class Mesa;

class UnoGame : public Scene {
private:
    RenderManager* renderMng;
    Mazo* m;
    Player* p;
    Mesa* table;
    //Prueba de renderizado y movimiento sin clases
    SDL_Rect destinationRect;
    SDL_Texture* texture;

public:
    UnoGame(RenderManager* rM);
    ~UnoGame();
    void update(SDL_Event& event);
    void render();
};