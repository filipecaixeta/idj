#include "resources.h"
#include <iostream>
#include <game.h>

Resources *Resources::instance = nullptr;

Resources::Resources()
{
    if (instance==nullptr)
        instance = this;
}

SDL_Texture *Resources::getImage(std::string file)
{
    std::unordered_map<std::string,SDL_Texture*>::const_iterator textureIt = imageTable.find(file);

    if (textureIt!=imageTable.end())
        return textureIt->second;

    SDL_Texture* texture;

    SDL_Renderer *renderer = Game::getInstance().getRenderer();
    if (renderer==nullptr)
        throw std::string("Renderer nao existe");

    texture = IMG_LoadTexture(renderer,file.c_str());
    if (texture==nullptr)
        throw std::string("IMG_LoadTexture falhou: ")+SDL_GetError();

    imageTable.emplace(file,texture);

    std::string filename = file.substr(file.find_last_of("/") + 1);
    std::cout << "Sprite " << filename << " carregada com sucesso" << std::endl;

    return texture;
}

void Resources::clearImages()
{
    for(auto tex: imageTable)
        SDL_DestroyTexture(tex.second);
    imageTable.clear();
}

Resources &Resources::getInstance()
{
    if (instance==nullptr)
        throw std::string("Instancia de Resources eh um nullptr");
    else
        return *instance;
}

Resources::~Resources()
{
    clearImages();
}
