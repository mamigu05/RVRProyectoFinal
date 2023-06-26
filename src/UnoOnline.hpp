#pragma once

class SceneManager;
class RenderManager;
class NetManager;

class UnoOnline {
private:
    SceneManager* sceneMng;
    RenderManager* renderMng;
    NetManager* netMng;
public:
    UnoOnline();
    ~UnoOnline();
    bool init(NetManager* nM);
    void run();
    void release();
};