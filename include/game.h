#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <state.h>
#include <resources.h>
#define TPF 33.333333

class Game
{
public:
	Game(std::string title, int width, int height);
	~Game();

	void run();
	SDL_Renderer *getRenderer();
	State &getState();
	static Game &getInstance();
	void init();
    float getDeltaTime();
    Vec2 getWindowDimensions();

private:
    void calculateDeltaTime();

    static Game *instance_;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    Uint32 nextTime_;
    Resources *resources_;
    int frameStart_;
    float dt_;
    Vec2 windowDim_;

    Uint32 timeLeft();
    State *state_;

};

#endif // GAME_H
