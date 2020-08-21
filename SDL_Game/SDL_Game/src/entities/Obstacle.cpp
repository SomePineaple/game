#include "Obstacle.hpp"

Obstacle::Obstacle(int width, SDL_Renderer *ren){
	ypos = 0;
	xpos = rand() % (width - 50);

	screenWidth = width;

	renderer = ren;

	SDL_Surface *tmpSurface = IMG_Load ("../assets/Obstacle.png");
	if(tmpSurface == NULL){
		std::cout << "Failed to load image" << std::endl;
	}
	obTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	std::cout << "Created obstacle" << std::endl;
}

void Obstacle::Update(){
	ypos += 5;

	srcRect.w = 50;
	srcRect.h = 50;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = xpos;
	destRect.y = ypos;
}

void Obstacle::Render(){

	SDL_RenderCopy(renderer, obTexture, &srcRect, &destRect);

}

void Obstacle::ResetPos(){
	ypos = 0;
	xpos = rand() % screenWidth;
}
