#pragma once

class SceneManager;

class UnoOnline {
private:
    SceneManager* sceneMng;
public:
    UnoOnline();
    ~UnoOnline();
    void init();
    void run();
    void release();
};