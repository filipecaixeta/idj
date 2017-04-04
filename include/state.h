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
    void input();
    void addObject(float mouseX,float mouseY);
    std::vector<std::unique_ptr<GameObject>> objectArray;
    Sprite bg;
	bool _quitRequested;
    TileMap *tileMap;
    TileSet *tileSet;

};

#endif // STATE_H
