#include "Game.hpp"

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
            SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
            std::cout << "Renderer successfully initialized" << std::endl;
        }
        
        isRunning = true;
    }else{
        isRunning = false;
    }
    
}

void Game::evenHandler() {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::update() {
    count++;
    
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    //Call player and obstacle render methods
    
    SDL_RenderPresent(renderer);
}

void Game::quit() {
    SDL_Quit();
    std::cout << "Quit" << std::endl;
}
