#include "ObstacleManager.hpp"

ObstacleManager::ObstacleManager(int width, int height, SDL_Renderer *ren){
	renderer = ren;

	screenWidth = width;
	screenHeight = height;

	Obstacle *ob1 = new Obstacle(width, renderer);
	obList.insert(obList.begin(), ob1);
}

void ObstacleManager::Update(){
	if(obList.size() < 10){
			Obstacle *ob = new Obstacle(screenWidth, renderer);
			obList.insert(obList.end(), ob);
	}

	for (auto const& i : obList){
		i->Render();
		i->Update();
		if(i->getY() > screenHeight){
			i->ResetPos();
		}
	}
}
