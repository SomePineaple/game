#include "/Library/Frameworks/SDL2.framework/Headers/SDL.h"
#include "Game.hpp"

Game *game = nullptr;

int width = 900;
int height = 700;
bool isFullscreen = false;

int main(int argc, const char * argv[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    game->init("Pineaple C++ game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, isFullscreen);
    
    while (game->running()) {
        frameStart = SDL_GetTicks();
        
        game->evenHandler();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->quit();
    
    return 0;
}
