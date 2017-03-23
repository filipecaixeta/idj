#ifndef STATE_H
#define STATE_H
#include <sprite.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class State
{
public:
	State();
	~State();
	bool quitRequested();
	void loadAssets();
	void update(float dt);
	void render();
private:
    Sprite *bg;
	bool _quitRequested;

};

#endif // STATE_H
