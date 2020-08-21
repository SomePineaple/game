#ifndef Player_hpp
#define Player_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Player {
public:
    Player(int width, int height, SDL_Renderer *ren);
    ~Player();

    void update();
    void render();

    void moveLeft();
    void moveRight();

    int xpos;
    int ypos;

private:

    int screenWidth;
    int screenHeight;

    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
};

#endif /* Player_hpp */
