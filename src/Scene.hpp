#pragma once

class Scene {
protected:
    Scene() {}

public:
    virtual ~Scene() {}
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};