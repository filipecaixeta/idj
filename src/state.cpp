#include "state.h"
#include <algorithm>
#include <face.h>

State::State():
	_quitRequested(false)
{
}

State::~State()
{
    objectArray.clear();
    delete tileMap;
    delete tileSet;
}

bool State::quitRequested()
{
	return _quitRequested;
}

void State::loadAssets()
{
    bg.open("img/ocean.jpg");
    tileSet = new TileSet(64,64,"img/tileset.png");
    tileMap = new TileMap("map/tileMap.txt",tileSet);
}

void State::update(float dt)
{
    input();
    for (auto it=objectArray.begin(); it!=objectArray.end();)
    {
        if ((*it)->isDead())
            it=objectArray.erase(it);
        else
            it++;
    }
}

void State::render()
{
    if (bg.isOpen())
        bg.render(0,0);
    else
        throw std::string("bg nao existe");

    tileMap->render(0,0);

    for(auto &i:objectArray) i->render();
}

void State::addObject(float mouseX, float mouseY)
{
    Vec2 pos(200,0);
    pos=pos.rotacionado(std::rand()%360);
    std::unique_ptr<GameObject> ptr(new Face(mouseX+pos.x,mouseY+pos.y));
    ptr->rotaciona(std::rand()%360);
    objectArray.push_back(std::move(ptr));
}

void State::input()
{
    SDL_Event event;
    int mouseX, mouseY;

    SDL_GetMouseState(&mouseX, &mouseY);

    while (SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
            _quitRequested = true;

        if(event.type == SDL_MOUSEBUTTONDOWN) {
            for(int i = objectArray.size() - 1; i >= 0; --i)
            {
                Face* face = (Face*) objectArray[i].get();
                if(face->box.isInside((float)mouseX, (float)mouseY))
                {
                    face->damage(rand() % 10 + 10);
                    break;
                }
            }
        }
        if( event.type == SDL_KEYDOWN )
        {
            if( event.key.keysym.sym == SDLK_ESCAPE )
            {
                _quitRequested = true;
            }
            else
            {
                addObject((float)mouseX, (float)mouseY);
            }
        }
    }
}
