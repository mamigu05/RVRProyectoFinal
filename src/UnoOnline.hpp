#pragma once

class SceneManager;
class RenderManager;

class UnoOnline {
private:
    SceneManager* sceneMng;
    RenderManager* renderMng;
public:
    UnoOnline();
    ~UnoOnline();
    bool init();
    void run();
    void release();
};