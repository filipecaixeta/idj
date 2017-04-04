#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Resources
{
public:
    Resources();
    SDL_Texture *getImage(std::string file);
    void clearImages();
    static Resources &getInstance();
    ~Resources();
private:
    std::unordered_map<std::string,SDL_Texture*> imageTable;
    static Resources *instance;
};

#endif // RESOURCES_H
