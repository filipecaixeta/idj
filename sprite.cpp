#include "sprite.h"
#include "game.h"

Sprite::Sprite()
{

}

Sprite::Sprite(std::string file):
	texture(nullptr)
{
	open(file);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

void Sprite::open(std::string file)
{
	if (texture!=nullptr)
		SDL_DestroyTexture(texture);

	SDL_Renderer *renderer = Game::getInstance().getRenderer();
	if (renderer==nullptr)
		throw std::string("Renderer nao existe");

	texture = IMG_LoadTexture(renderer,file.c_str());
	if (texture==nullptr)
		throw std::string("IMG_LoadTexture falhou: ")+SDL_GetError();

	if (SDL_QueryTexture(texture,NULL,NULL,&width,&height)!=0)
		throw std::string("SDL_QueryTexture falhou: ")+SDL_GetError();
	
	setClip(0,0,width,height);
	std::string filename = file.substr(file.find_last_of("/") + 1); // So pra unix
	std::cout << "Sprite " << filename << " carregada com sucesso" << std::endl;
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
	SDL_RenderCopy(renderer,texture,NULL,NULL);
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
