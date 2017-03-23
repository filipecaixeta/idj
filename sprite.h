#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Sprite
{
public:
	Sprite();
	Sprite(std::string file);
	~Sprite();
	void open(std::string file);
	void setClip(int x,int y,int w,int h);
	void render(int x,int y);
	int getWidth();
	int getHeight();
	bool isOpen();
private:
	SDL_Texture *texture;
	int width;
	int height;
	SDL_Rect clipRect;
};

#endif // SPRITE_H
