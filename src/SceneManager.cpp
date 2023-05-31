#include "SceneManager.hpp"
#include "Scene.hpp"

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {
    deleteScenes();
    
    while(!mng.empty()){
        Scene* s = mng.top();
        delete s; s = nullptr;
        mng.pop();
    }
}

void SceneManager::addScene(Scene* newScene){
    mng.push(newScene);
}

void SceneManager::changeScene(Scene* newScene){
    popScene();
    addScene(newScene);
}

void SceneManager::popScene(){
    if(!mng.empty()) {
        scenesToDelete.push(mng.top());
        mng.pop();
    }
}

Scene* SceneManager::currentScene(){
    return mng.top();
}

void SceneManager::deleteScenes() {
    while(!scenesToDelete.empty()){
        Scene* s = scenesToDelete.top();
        delete s; s = nullptr;
        scenesToDelete.pop();
    }
}