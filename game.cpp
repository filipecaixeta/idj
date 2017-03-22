#include "game.h"

Game *Game::instance = nullptr;

Game::Game(std::string title, int width, int height)
{
    if (!instance)
    {
        instance = this;
    }
    else
    {
        std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
        std::cerr << "Tentativa de recriar instancia de Game" << std::endl;
    }

    // Inicializa a SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
    {
        std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
        std::cerr << "SDL_Init falhou: " <<  SDL_GetError() << std::endl;
    }
    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if( (IMG_Init(imgFlags)&imgFlags) != imgFlags )
    {
        std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
        std::cerr << "IMG_Init falhou: " <<  IMG_GetError() << std::endl;
    }
    window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                 width,height, SDL_WINDOW_OPENGL);
    if (!window)
    {
        std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
        std::cerr << "Nao foi possivel criar a janela " <<  SDL_GetError() << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
        std::cerr << "Nao foi possivel criar o renderer " <<  SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "renderer = "<<(int)renderer << std::endl;
    }
    init();
}

Game::~Game()
{
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
    if (!instance)
    {
        std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
        std::cerr << "Instancia de Game nao foi criada ainda" << std::endl;
    }
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
