#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vec2.h>

class Sprite
{
public:
	Sprite();
	Sprite(std::string file);
	~Sprite();
	void open(std::string file);
	void setClip(int x,int y,int w,int h);
    void render();
    Vec2 getDimencao();
	int getWidth();
	int getHeight();
	bool isOpen();
    float angle;
    Vec2 pos;
    bool fix;

private:
	SDL_Texture *texture;
	int width;
	int height;
	SDL_Rect clipRect;
};

#endif // SPRITE_H
