#pragma once

#include <stack>

class Scene;

class SceneManager {
private:
    std::stack<Scene*> mng;
    std::stack<Scene*> scenesToDelete;

public:
    SceneManager();
    ~SceneManager();
    void addScene(Scene* newScene);
    void changeScene(Scene* newScene);
    void popScene();
    Scene* currentScene();
    void deleteScenes();
};