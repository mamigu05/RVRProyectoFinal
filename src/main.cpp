// std
#include <stdio.h>

// opengl
#include <GL/glew.h>

// sdl
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderManager.hpp"



int main (int argc, char* argv[])
{
   RenderManager renderManager;
   if(renderManager.init())
   {
        SDL_Rect destinationRect;
        destinationRect.x = 0;
        destinationRect.y = 0;
        destinationRect.w = 200;
        destinationRect.h = 350;

        
        SDL_Texture* texture = renderManager.loadImage("assets/+4.png");

        // ----- Game loop
        bool quit = false;
        while (quit == false)
        {
            SDL_Event windowEvent;
            while (SDL_PollEvent(&windowEvent))
            {
                if (windowEvent.type == SDL_QUIT)
                {
                    quit = true;
                    break;
                }
            }

            /*
                do drawing here
            */

            renderManager.clear();
            renderManager.renderImage(texture, &destinationRect);
            renderManager.render();

        }
        renderManager.deleteTexture(texture);
        renderManager.release();
   }
    return 0;
}