#ifndef Game_hpp
#define Game_hpp

#include "/Library/Frameworks/SDL2.framework/Headers/SDL.h"
#include "/Library/Frameworks/SDL2_image.framework/Headers/SDL_image.h"
#include <iostream>

#include "Player.hpp"

class Game {

public:
    Game();
    ~Game();
    
    void init (const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void evenHandler();
    void update();
    void render();
    void quit();
    
    bool running() {
        return isRunning;
    }
    
private:
    int count = 0;
    bool isRunning;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    
};

#endif /* Game_hpp */
