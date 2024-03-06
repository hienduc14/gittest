#pragma once
#include <iostream>
#include <SDL.h>
#include "basFn.h"

using namespace std;

class Obj{
    public:
        int x, y;
        SDL_Texture* Portrait = nullptr;
        void setPortrait( std::string filePath, SDL_Renderer *&renderer );
        void drawPortrait( SDL_Renderer *&renderer );
};
