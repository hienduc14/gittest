#include "obj.h"

void Obj::setPortrait( std::string filePath, SDL_Renderer *&renderer ){
    SDL_Surface* load_image = nullptr;

    load_image = IMG_Load(filePath);

    if (load_image != NULL)
    {
        Portrait = SDL_CreateTextureFromSurface(renderer, load_image);
        SDL_FreeSurface(load_image);
    }
    return;
}

void Obj::drawPortrait( SDL_Renderer *&renderer ){
    // Khai báo destination rectangle với tọa độ (x, y) và kích thước là kích thước của texture
    SDL_Rect dstRect = {x, y, 100, 100};
    // Vẽ texture lên renderer tại tọa độ (x, y)
    SDL_RenderCopy(renderer, Portrait, NULL, &dstRect);
    SDL_RenderPresent( renderer );
}
