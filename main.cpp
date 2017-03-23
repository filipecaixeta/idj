#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <game.h>

int main (int argc, char** argv) {

	try
	{
		Game game("Filipe A. Caixeta 10/0129706",1024,600);
		game.run();
	}
	catch(std::string &s)
	{
		std::cerr << s << std::endl;
	}
	return 0;
}
