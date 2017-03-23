#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <state.h>
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

private:
	static Game *instance;
	SDL_Window *window;
	SDL_Renderer *renderer;
	Uint32 nextTime;

	Uint32 timeLeft();
	State *state;

};

#endif // GAME_H
