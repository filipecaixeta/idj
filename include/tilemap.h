#ifndef TILEMAP_H
#define TILEMAP_H
#include <tileset.h>
#include <vector>
#include <string>

class TileMap
{
public:
    TileMap(std::string file,TileSet *_tileSet);
    ~TileMap();
    void load(std::string file);
    void setTileSet(TileSet *_tileSet);
    int &at(int x, int y, int z);
    void render(int cameraX,int cameraY);
    void renderLayer(int layer, int cameraX, int cameraY);
    int getWidth();
    int getHeight();
    int getDepth();
    void criarBuffTexture();
private:
    std::vector<int> tileMatrix;
    TileSet *tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;
    SDL_Texture *buffTexture;
};

#endif // TILEMAP_H
