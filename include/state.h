#ifndef STATE_H
#define STATE_H
#include <sprite.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <gameobject.h>
#include <tileset.h>
#include <tilemap.h>
#include <camera.h>
#include <alien.h>

class State
{
public:
	State();
	~State();
	bool quitRequested();
	void loadAssets();
	void update(float dt);
	void render();
    void addObject(GameObject* ptr);
private:
    std::vector<std::unique_ptr<GameObject>> objectArray;
    Sprite bg;
    bool quitRequested_;
    TileMap *tileMap;
    TileSet *tileSet;
    Alien *alien;

};

#endif // STATE_H
