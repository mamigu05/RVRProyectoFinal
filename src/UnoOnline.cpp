#include "UnoOnline.hpp"

#include "SceneManager.hpp"
#include "RenderManager.hpp"

#include <SDL2/SDL.h>

#include "UnoGame.hpp"

UnoOnline::UnoOnline() : sceneMng(nullptr) {}

UnoOnline::~UnoOnline() {

}

bool UnoOnline::init() {
    sceneMng = new SceneManager();
    renderMng = new RenderManager();

    if(!renderMng->init())
        return false;

    sceneMng->addScene(new UnoGame(renderMng));
    return true;
}

void UnoOnline::run() {
    bool quit = false;
    while (quit == false)
    {
        SDL_Event windowEvent; 
        while (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
        }

        renderMng->clear();

        sceneMng->currentScene()->update();
        sceneMng->currentScene()->render();

        renderMng->render();
    }
}

void UnoOnline::release() {
    renderMng->release();
    delete renderMng; renderMng = nullptr;
    delete sceneMng; sceneMng = nullptr;
}