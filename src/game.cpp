#include "game.h"
#include <cstdlib>
#include <tilemap.h>
#include <inputmanager.h>

Game *Game::instance_ = nullptr;

Game::Game(std::string title, int width, int height):
    nextTime_(0),
    frameStart_(0),
    dt_(0.0f),
    windowDim_(width,height)
{
    if (instance_==nullptr)
    {
        instance_ = this;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
    {
        throw std::string("SDL_Init falhou: ") + SDL_GetError();
    }

	int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	if((IMG_Init(imgFlags)&imgFlags) != imgFlags)
    {
		throw std::string("IMG_Init falhou: ") + IMG_GetError();
    }

    int flags = SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI;// | SDL_WINDOW_FULLSCREEN_DESKTOP
    window_ = SDL_CreateWindow(	title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                width,height, flags);
    if (window_==nullptr)
    {
        throw std::string("Nao foi possivel criar a janela: ") + SDL_GetError();
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_WINDOW_OPENGL);
    if (renderer_==nullptr)
    {
        throw std::string("Nao foi possivel criar o renderer: ") + SDL_GetError();
    }

    //Futuramente da pra configurar resolucoes maiores
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer_, width, height);
	
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);

    std::srand(SDL_GetTicks());

    resources_ = new Resources();

	init();
}

Game::~Game()
{
    delete state_;
	IMG_Quit();
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
	SDL_Quit();
}

void Game::run()
{
    nextTime_ = SDL_GetTicks() + TPF;
    while (!state_->quitRequested())
	{
        calculateDeltaTime();
        InputManager::getInstance().update();

        state_->update(getDeltaTime());
        state_->render();

        SDL_RenderPresent( renderer_ );

//        std::cout << "Mouse: "<< Camera::getInstance().window2world(InputManager::getInstance().getMouseXY())<<std::endl;

        SDL_Delay(timeLeft());
        nextTime_ += TPF;
	}
    resources_->clearImages();
}

SDL_Renderer *Game::getRenderer()
{
    return renderer_;
}

State &Game::getState()
{
    return *state_;
}

Game &Game::getInstance()
{
    if (instance_==nullptr)
		throw std::string("Instancia de Game eh um nullptr");
	else
        return *instance_;
}

Uint32 Game::timeLeft()
{
	Uint32 now;
	now = SDL_GetTicks();
    if(nextTime_ <= now)
		return 0;
	else
        return nextTime_ - now;
}

void Game::init()
{
    state_ = new State();
    state_->loadAssets();
}

float Game::getDeltaTime()
{
    return dt_;
}

Vec2 Game::getWindowDimensions()
{
    return windowDim_;
}

void Game::calculateDeltaTime()
{
    int temp = SDL_GetTicks();
    dt_ = (float)(temp-frameStart_)/1000.0f;
    frameStart_ = temp;
}
