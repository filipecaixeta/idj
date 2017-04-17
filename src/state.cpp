#include <state.h>
#include <algorithm>
#include <face.h>
#include <inputmanager.h>

State::State():
    quitRequested_(false)
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
    return quitRequested_;
}

void State::loadAssets()
{
    bg.open("img/ocean.jpg");
    bg.fix = true;
    tileSet = new TileSet(64,64,"img/tileset.png");
    tileMap = new TileMap("map/tileMap.txt",tileSet);
    alien = new Alien(512,300,7);
}

void State::update(float dt)
{
    quitRequested_ =    InputManager::getInstance().quitRequested() ||
                        InputManager::getInstance().keyPress(SDLK_ESCAPE);

    if (InputManager::getInstance().keyPress(' '))
    {
        Vec2 worldPos = InputManager::getInstance().getWorldMouseXY();

//        addObject(worldPos.x,worldPos.y);
    }
    if (InputManager::getInstance().mousePress(SDL_BUTTON_LEFT))
    {
        Vec2 worldPos = InputManager::getInstance().getWorldMouseXY();

//        for(int i = objectArray.size() - 1; i >= 0; --i)
//        {
//            Face* face = (Face*) objectArray[i].get();
//            if(face->box.isInside(worldPos.x, worldPos.y))
//            {
//                face->damage(rand() % 10 + 10);
//                break;
//            }
//        }
    }

    Camera::getInstance().update(dt);

    alien->update(dt);

    for(auto &i:objectArray) i->update(dt);

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
        bg.render();
    else
        throw std::string("bg nao existe");

    tileMap->render(0,0);
    alien->render();

    for(auto &i:objectArray) i->render();
}

void State::addObject(GameObject *ptr_)
{
    std::unique_ptr<GameObject> ptr(ptr_);
    objectArray.push_back(std::move(ptr));
}
