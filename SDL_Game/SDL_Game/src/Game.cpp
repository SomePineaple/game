#include "Game.hpp"
#include "entities/Player.hpp"
#include "entities/ObstacleManager.hpp"

Player *player;
ObstacleManager *obMan;

Game::Game () {}
Game::~Game () {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){

        std::cout << "Subsystems Initialized" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window){
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer){
            SDL_SetRenderDrawColor(renderer, 190, 190, 190, 255);
            std::cout << "Renderer successfully initialized" << std::endl;
        }

        isRunning = true;
    }else{
        isRunning = false;
    }

    player = new Player(width, height, renderer);
    obMan = new ObstacleManager(width, height, renderer);
}

void Game::evenHandler() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:

        	switch ( event.key.keysym.sym ){
        		case SDLK_RIGHT:
        			player->moveRight();
        			break;
        		case SDLK_LEFT:
        			player->moveLeft();
        			break;

        		default:
        			break;

        	}

        break;

        default:
            break;
    }
}

void Game::update() {
	player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);

    //Call player and obstacle render methods
    obMan->Update();
    player->render();

    SDL_RenderPresent(renderer);
}

void Game::quit() {
    SDL_Quit();
    std::cout << "Quit" << std::endl;
}
