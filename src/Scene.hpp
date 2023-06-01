#pragma once
#include <SDL2/SDL.h>

class Scene {
protected:
    Scene() {}

public:
    virtual ~Scene() {}
    virtual void update(SDL_Event& event) = 0;
    virtual void render() = 0;
};