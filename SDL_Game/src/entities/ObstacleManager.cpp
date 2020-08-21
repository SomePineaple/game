#include "ObstacleManager.hpp"
#include <cmath>

ObstacleManager::ObstacleManager(int width, int height, SDL_Renderer *ren){
	renderer = ren;

	screenWidth = width;
	screenHeight = height;

	addToObstacles = 0;

	numObstacles = 1;

	Obstacle *ob1 = new Obstacle(width, renderer);
	obList.insert(obList.begin(), ob1);
}

void ObstacleManager::Update(){
	numObstacles = 1 + floor(addToObstacles / 10);
	if(int(obList.size()) < numObstacles){
			Obstacle *ob = new Obstacle(screenWidth, renderer);
			obList.insert(obList.end(), ob);
	}

	for (auto const& i : obList){
		i->Render();
		i->Update();
		if(i->getY() > screenHeight){
			i->ResetPos();
			addToObstacles++;
		}
	}
}

bool ObstacleManager::CollisionChecker(int px, int py){
	for (auto const& i : obList){
		if(i->getX() >= px && i->getX() < px + 50 && i->getY() >= py && py < i->getY()){
			return true;
		}
		if(px >= i->getX() && px < i->getX() + 50 && py >= i->getY() and py < i->getY() + 50){
			return true;
		}
	}
	return false;
}
