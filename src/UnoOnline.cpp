#include "UnoOnline.hpp"

#include "SceneManager.hpp"
#include "RenderManager.hpp"
#include "NetManager.hpp"

#include <SDL2/SDL.h>
#include <thread>

#include "UnoGame.hpp"

UnoOnline::UnoOnline() : sceneMng(nullptr) {}

UnoOnline::~UnoOnline() {

}

bool UnoOnline::init(NetManager* nM) {
    sceneMng = new SceneManager();
    renderMng = new RenderManager();
    netMng = nM;

    if(!renderMng->init())
        return false;

    sceneMng->addScene(new UnoGame(renderMng, netMng));
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

        sceneMng->currentScene()->update(windowEvent);
        sceneMng->currentScene()->render();

        renderMng->render();
    }
}

void UnoOnline::release() {
    renderMng->release();
    delete renderMng; renderMng = nullptr;
    delete sceneMng; sceneMng = nullptr;
}