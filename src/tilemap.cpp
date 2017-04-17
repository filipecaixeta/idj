#include <tilemap.h>
#include <iostream>
#include <fstream>
#include <game.h>

TileMap::TileMap(std::string file, TileSet *_tileSet)
{
    tileSet = _tileSet;
    load(file);
}

TileMap::~TileMap()
{

}

void TileMap::load(std::string file)
{
    ifstream f;
    f.open(file);
    if (!f.is_open())
        throw std::string("Nao foi possivel abrir o tileMap");
    std::string line;
    char sep;
    f >> mapWidth >> sep >> mapHeight >> sep >> mapDepth;
    std::getline(f,line);
    tileMatrix.reserve(mapWidth*mapHeight*mapDepth);
    int index=0;
    for(int k=0; k<mapDepth; k++)
    {
        std::getline(f,line);
        for(int j=0; j<mapHeight; j++)
        {
            for(int i=0; i<mapWidth; i++,index++)
            {
                int temp;
                f >> temp >> sep;
                tileMatrix[index] = temp-1;
            }
            std::getline(f,line);
        }
    }
}

void TileMap::setTileSet(TileSet *_tileSet)
{
    tileSet = _tileSet;
}

inline int &TileMap::at(int x, int y, int z)
{
    return tileMatrix[z*mapHeight*mapWidth+y*mapWidth+x];
}

void TileMap::render(int x, int y)
{
    for(int k=0; k<mapDepth; k++)
    {
        renderLayer(k,x,y);
    }
}

void TileMap::render(Vec2 pos)
{
    render(pos.x,pos.y);
}

void TileMap::renderLayer(int layer, int x, int y)
{
    for (int j=0,posY=y; j<mapHeight; j++,posY+=tileSet->getTileHeight())
    {
        for(int i=0,posX=x; i<mapWidth; i++,posX+=tileSet->getTileWidth())
        {
            tileSet->render(at(i,mapHeight-1-j,layer),posX,posY);
        }
    }
}

int TileMap::getWidth()
{
    return mapWidth;
}

int TileMap::getHeight()
{
    return mapHeight;
}

int TileMap::getDepth()
{
    return mapDepth;
}
