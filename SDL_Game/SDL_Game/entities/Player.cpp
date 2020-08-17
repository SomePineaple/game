#include "Player.hpp"
 
Player::Player (int width, int height, SDL_Renderer *ren){
    renderer = ren;
    
    xpos = width / 2;
    ypos = height - 70;
    
    srcRect.y = ypos;
    srcRect.x = xpos;
    srcRect.h = 50;
    srcRect.w = 50;
    
    screenWidth = width;
    screenHeight = height;
    
    SDL_Surface *tmpSurface = IMG_Load("Player.png");
    texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Player::Update(){
    
    
    srcRect.x = xpos;
}

void Player::Render(){
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
