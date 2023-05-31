#pragma once

#include "Scene.hpp"

class UnoGame : public Scene {
private:

public:
    UnoGame();
    ~UnoGame();
    void init();
    void update();
    void render();
};