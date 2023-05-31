#include "RenderManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

RenderManager::RenderManager() : window(nullptr), renderer(nullptr)
{

}

RenderManager::~RenderManager(){}

bool RenderManager::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            fprintf(stderr, "SDL could not initialize\n");
            return false;
        }

        window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_SIZE_X, SCREEN_SIZE_Y, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if (!window)
        {
            fprintf(stderr, "Error creating window.\n");
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (!renderer) {
            fprintf(stderr, "Error creating renderer.\n");
            return false;
        }

        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
            fprintf(stderr, "Error initializing SDL_image.\n");
            return false;
        }

        return true;
}

SDL_Texture* RenderManager::loadImage(const char* filename)
{
    SDL_Surface* imageSurface = IMG_Load(filename);
    if (!imageSurface) {
            fprintf(stderr, "Error loading image.\n");
            return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    return texture;    
}

void RenderManager::clear()
{
    SDL_RenderClear(renderer);
}

void RenderManager::renderImage(SDL_Texture* texture, SDL_Rect* destRect, SDL_Rect* srcRect)
{
    SDL_RenderCopy(renderer, texture, srcRect, destRect);
}

void RenderManager::render()
{
    SDL_RenderPresent(renderer);
}

void RenderManager::deleteTexture(SDL_Texture* texture)
{
    if(texture)
        SDL_DestroyTexture(texture);
}

void RenderManager::release()
{
    if(renderer)
        SDL_DestroyRenderer(renderer);
    if(window)
        SDL_DestroyWindow(window);
    SDL_Quit();       
}