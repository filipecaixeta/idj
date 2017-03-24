#include "game.h"
#include <cstdlib>

Game *Game::instance = nullptr;

Game::Game(std::string title, int width, int height)
{
	if (instance==nullptr)
		instance = this;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
        throw std::string("SDL_Init falhou: ") + SDL_GetError();

	int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	if((IMG_Init(imgFlags)&imgFlags) != imgFlags)
		throw std::string("IMG_Init falhou: ") + IMG_GetError();

	window = SDL_CreateWindow(	title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
								width,height, SDL_WINDOW_OPENGL);
	if (window==nullptr)
		throw std::string("Nao foi possivel criar a janela: ") + SDL_GetError();
	
	renderer = SDL_CreateRenderer(window, -1, SDL_WINDOW_OPENGL);
	if (renderer==nullptr)
		throw std::string("Nao foi possivel criar o renderer: ") + SDL_GetError();
	
    std::srand(SDL_GetTicks());

	init();
}

Game::~Game()
{
	delete state;
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run()
{
	nextTime = SDL_GetTicks() + TPF;
	while (!state->quitRequested())
	{
        state->update(0);
        state->render();

        SDL_RenderPresent( renderer );

        SDL_Delay(timeLeft());
		nextTime += TPF;
	}
}

SDL_Renderer *Game::getRenderer()
{
	return renderer;
}

State &Game::getState()
{

}

Game &Game::getInstance()
{
	if (instance==nullptr)
		throw std::string("Instancia de Game eh um nullptr");
	else
		return *instance;
}

Uint32 Game::timeLeft()
{
	Uint32 now;
	now = SDL_GetTicks();
	if(nextTime <= now)
		return 0;
	else
		return nextTime - now;
}

void Game::init()
{
	state = new State();
	state->loadAssets();
}
