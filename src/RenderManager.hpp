#pragma once


#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class RenderManager
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    RenderManager();
    ~RenderManager();

    bool init();

    SDL_Texture* loadImage(const char* filename);

    void clear();

    void renderImage(SDL_Texture* texture, SDL_Rect* destRect = nullptr, SDL_Rect* srcRect = nullptr);

    void render();

    void deleteTexture(SDL_Texture* texture);

    void release();
};