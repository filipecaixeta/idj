#include "state.h"

State::State():
	_quitRequested(false)
{
}

State::~State()
{
    delete bg;
}

bool State::quitRequested()
{
	return _quitRequested;
}

void State::loadAssets()
{
    bg = new Sprite("recursos/img/ocean.jpg");
}

void State::update(float dt)
{
	_quitRequested = SDL_QuitRequested()==SDL_TRUE?true:false;
}

void State::render()
{
    if (bg->isOpen())
        bg->render(0,0);
	else
		throw std::string("bg nao existe");
}
