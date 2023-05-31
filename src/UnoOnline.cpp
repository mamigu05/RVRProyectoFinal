#include "UnoOnline.hpp"
#include "SceneManager.hpp"
#include "UnoGame.hpp"

UnoOnline::UnoOnline() : sceneMng(nullptr) {}

UnoOnline::~UnoOnline() {

}

void UnoOnline::init() {
    sceneMng = new SceneManager();
    sceneMng->addScene(new UnoGame());
}

void UnoOnline::run() {
    sceneMng->currentScene()->update();
    sceneMng->currentScene()->render();
}

void UnoOnline::release() {

}