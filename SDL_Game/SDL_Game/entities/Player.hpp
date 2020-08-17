#ifndef Player_hpp
#define Player_hpp

#include "Game.hpp"

class Player {
public:
    Player(int width, int height, SDL_Renderer *ren);
    ~Player();
    
    void Update();
    void Render();
    
private:
    int xpos;
    int ypos;
    int screenWidth;
    int screenHeight;
    
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
};

#endif /* Player_hpp */
