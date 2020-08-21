#ifndef ENTITIES_OBSTACLEMANAGER_HPP_
#define ENTITIES_OBSTACLEMANAGER_HPP_

#include "Obstacle.hpp"
#include <list>

class ObstacleManager{

public:
	std::list<Obstacle*> obList;
	ObstacleManager(int width, int height, SDL_Renderer *ren);
	~ObstacleManager();
	void Update();

	int addToObstacles;

	bool CollisionChecker(int px, int py);

private:
	SDL_Renderer *renderer;
	int screenWidth;
	int screenHeight;
	int numObstacles;
};

#endif /* ENTITIES_OBSTACLEMANAGER_HPP_ */
