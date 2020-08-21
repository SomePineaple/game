#ifndef ENTITIES_OBSTACLE_HPP_
#define ENTITIES_OBSTACLE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Obstacle {

public:

	Obstacle(int width, SDL_Renderer *ren);
	~Obstacle();

	int getX (){
		return xpos;
	}
	int getY (){
		return ypos;
	}

	void Update();
	void Render();

	void ResetPos();

private:

	int xpos;
	int ypos;

	int screenWidth;

	SDL_Rect srcRect, destRect;

	SDL_Texture *obTexture;

	SDL_Renderer *renderer;

};


#endif /* ENTITIES_OBSTACLE_HPP_ */
