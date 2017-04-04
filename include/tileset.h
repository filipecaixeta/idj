#ifndef TILESET_H
#define TILESET_H
#include <string>
#include <sprite.h>

class TileSet
{
public:
    TileSet(int _tileWidth, int _tileHeight, std::string file);
    ~TileSet();
    void render(unsigned index, float x, float y);
    int getTileWidth();
    int getTileHeight();

private:
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;
};

#endif // TILESET_H
