#include "state.h"

State::State():
    _quitRequested(false)
{

}

bool State::quitRequested()
{
    return _quitRequested;
}

void State::loadAssets()
{
    bg = Sprite("recursos\\img\\ocean.png");
}

void State::update(float dt)
{
    _quitRequested = SDL_QuitRequested()==SDL_TRUE?true:false;
}

void State::render()
{
    bg.render(0,0);
//    if (bg.isOpen())
//    else
//        {
//            std::cerr << "Erro em " <<  __FILE__ << " linha " << __LINE__ << std::endl;
//            std::cerr << "bg nao existe" << std::endl;
//        }
}
