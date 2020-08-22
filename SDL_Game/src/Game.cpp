#include "Game.hpp"
#include "entities/Player.hpp"
#include "entities/ObstacleManager.hpp"

Player *player;
ObstacleManager *obMan;

Game::Game () {}
Game::~Game () {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;

    score = 0;

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

    if(TTF_Init() == -1)
    	std::cout << "init font thing\n";
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
        		case SDLK_ESCAPE:
        			isRunning = false;
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

	if(obMan->CollisionChecker(player->xpos, player->ypos)){
		isRunning = false;
	}
}

void Game::render() {
    SDL_RenderClear(renderer);

    obMan->Update();
    player->render();
    Game::renderScore();
    score = obMan->addToObstacles;

    SDL_RenderPresent(renderer);
}

void Game::quit() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderClear(renderer);

	TTF_Font *font;
	font = TTF_OpenFont("/home/Abby/eclipse-workspace/SDL_Game/src/assets/Roboto/Roboto-Thin.ttf", 150);

	std::string finalText = std::to_string(score);

	finalText = "Your final score was: " + finalText;

	const char *finalChar = finalText.c_str();

	SDL_Color gray = {50, 50, 50};

	SDL_Surface *finalMessageSurface = TTF_RenderText_Solid(font, finalChar, gray);

	SDL_Texture *finalMessage = SDL_CreateTextureFromSurface(renderer, finalMessageSurface);

	SDL_Rect messageRect;

	messageRect.x = 0;
	messageRect.y = 768 / 2 - 150;
	messageRect.h = 300;
	messageRect.w = 1366;

	SDL_RenderCopy(renderer, finalMessage, NULL, &messageRect);

	SDL_RenderPresent(renderer);

	SDL_Delay(5000);

    SDL_Quit();
    std::cout << "Quit" << std::endl;
    std::cout << "Your final score was: " << score << std::endl;
}
void Game::renderScore(){

	TTF_Font *font;
	font = TTF_OpenFont("/home/Abby/eclipse-workspace/SDL_Game/src/assets/Roboto/Roboto-Thin.ttf", 150);

	std::string scoreTxt = std::to_string(score);

	scoreTxt = "Your score is: " + scoreTxt;

	const char *txt = scoreTxt.c_str();

	SDL_Color white = {255, 255, 255};

	SDL_Surface *messageSurface = TTF_RenderText_Solid(font, txt, white);

	SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, messageSurface);

	SDL_Rect messageRect;
	messageRect.x = 20;
	messageRect.y = 20;
	messageRect.h = 75;
	if (score < 10){
		messageRect.w = 300 + 25 * 2;
	}

	else if (score >= 10 && score < 100){
		messageRect.w = 300 + 50 * 2;
	}

	else if (score >+ 100){
		messageRect.w = 300 + 75 * 2;
	}

	SDL_RenderCopy(renderer, message, NULL, &messageRect);

	SDL_FreeSurface(messageSurface);
	SDL_DestroyTexture(message);
}
