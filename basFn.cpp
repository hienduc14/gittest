#include "basFn.h"

void SDLHandle::initSDL(SDL_Window *&window, SDL_Renderer *&renderer )
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1 ) SDL_Quit();

    window = SDL_CreateWindow("GAME",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (!window) SDL_Quit();

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) SDL_Quit();
}


void SDLHandle::quitSDL(SDL_Window *&window, SDL_Renderer *&renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLHandle::waitUntilKeyPressed()
{
    SDL_Event e;
    while( true )
    {
        if ( SDL_WaitEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

SDL_Texture* SDLHandle::Load_Image( std::string filePath, SDL_Renderer *&renderer ){
    SDL_Surface* load_image = nullptr;
    SDL_Texture* screen = nullptr;

    load_image = IMG_Load(filePath.c_str());

    if (load_image != NULL)
	{
	    screen = SDL_CreateTextureFromSurface(renderer, load_image);
		SDL_FreeSurface(load_image);
	}
	return screen;

};
