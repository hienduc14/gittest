#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class SDLHandle{
public:
    void initSDL(SDL_Window *&window, SDL_Renderer *&renderer);
    void quitSDL(SDL_Window *&window, SDL_Renderer *&renderer);
    void waitUntilKeyPressed();
    SDL_Texture* Load_Image( std::string filePath, SDL_Renderer *&renderer );

};
