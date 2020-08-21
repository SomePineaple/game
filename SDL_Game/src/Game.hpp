#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#ifndef GAME_H_
#define GAME_H_


class Game {

public:
    Game();
    ~Game();

    void init (const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void evenHandler();
    void update();
    void render();
    void quit();

    int score;

    static SDL_Event event;

    bool running() {
        return isRunning;
    }

private:
    int count = 0;
    bool isRunning;

    SDL_Window *window;
    SDL_Renderer *renderer;


};


#endif /* GAME_H_ */
