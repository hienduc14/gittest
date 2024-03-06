#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include "basFn.h"
#include "obj.h"

int main(int argc, char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDLHandle* sdlHandle = new SDLHandle();
    sdlHandle->initSDL(window, renderer);
//    std::string x = "bg2.png";

    SDL_Texture* backGr = sdlHandle->Load_Image("bg2.png", renderer);

    Obj* ball = new Obj();
    ball->setPortrait("ball.png", renderer);
    int x = 0, y = 0; int ok = 5;
    while ( true ){
        SDL_RenderCopy( renderer, backGr, NULL, NULL );
        SDL_RenderPresent( renderer );

        x += ok;
        ball->x = x; ball->y = y;
        if( x >= SCREEN_WIDTH || x <= 0 ) ok*= -1;

        ball->drawPortrait(renderer);
        SDL_Delay(50);
    }

    sdlHandle->quitSDL(window, renderer);
    SDL_DestroyTexture(backGr);
    delete(sdlHandle);
    return 0;
}
