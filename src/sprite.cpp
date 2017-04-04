#include "sprite.h"
#include "game.h"
#include <resources.h>

Sprite::Sprite():
    angle(0),
    texture(nullptr)
{

}

Sprite::Sprite(std::string file):
    angle(0),
    texture(nullptr)
{
	open(file);
}

Sprite::~Sprite()
{

}

void Sprite::open(std::string file)
{
	if (texture!=nullptr)
		SDL_DestroyTexture(texture);

	SDL_Renderer *renderer = Game::getInstance().getRenderer();
	if (renderer==nullptr)
		throw std::string("Renderer nao existe");

    texture = Resources::getInstance().getImage(file);

	if (SDL_QueryTexture(texture,NULL,NULL,&width,&height)!=0)
		throw std::string("SDL_QueryTexture falhou: ")+SDL_GetError();
	
	setClip(0,0,width,height);
}

void Sprite::setClip(int x,int y,int w,int h)
{
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::render(int x,int y)
{
	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;

	SDL_Renderer *renderer = Game::getInstance().getRenderer();

	if (renderer==nullptr)
		throw std::string("Renderer nao existe");
    if (!isOpen())
        throw std::string("Sprite nao existe");

    SDL_RenderCopyEx(renderer,texture,&clipRect,&dstrect,
                     angle,NULL,SDL_FLIP_NONE);

}

Vec2 Sprite::getDimencao()
{
    return Vec2(this->getWidth(),this->getHeight());
}

int Sprite::getWidth()
{
	return width;
}

int Sprite::getHeight()
{
	return height;
}

bool Sprite::isOpen()
{
	return (texture!=nullptr);
}
