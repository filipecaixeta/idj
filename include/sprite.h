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
    Vec2 getCenter();
    void setScaleX(float scale);
    void setScaleY(float scale);
    void setScaleXY(Vec2 scale);
	bool isOpen();
    float angle;
    Vec2 pos;
    bool fix;

private:
	SDL_Texture *texture;
	int width;
	int height;
    float scaleX_;
    float scaleY_;
	SDL_Rect clipRect;
};

#endif // SPRITE_H
