#include "Player.hpp"

Player::Player(int width, int height, SDL_Renderer *ren){
	renderer = ren;
	screenHeight = height;
	screenWidth = width;
	xpos = (screenWidth / 2) - 25;
	ypos = screenHeight - 70;
	SDL_Surface *tmpSurface = IMG_Load("src/assets/Player.png");
	texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Player::update(){

	srcRect.h = 50;
	srcRect.w = 50;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	if(xpos < 0 || xpos > screenWidth - 50){
		xpos = screenWidth / 2 - 25;
	}
}

void Player::render(){

	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);

}

void Player::moveLeft(){
	xpos -= 50;
}

void Player::moveRight(){
	xpos += 50;
}
