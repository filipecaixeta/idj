#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <game.h>

int main (int argc, char** argv) {

    Game game("Filipe A. Caixeta 10/0129706",1024,600);
    game.run();
    return 0;
}
