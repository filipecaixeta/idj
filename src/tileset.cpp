#include <tileset.h>
#include <vec2.h>

TileSet::TileSet(int _tileWidth, int _tileHeight, std::string file):tileSet(file)
{
    tileHeight=_tileWidth;
    tileWidth=_tileWidth;
    columns = tileSet.getWidth()/_tileWidth;
    rows = tileSet.getHeight()/_tileHeight;
    tileSet.fix=false;
}

TileSet::~TileSet()
{

}

void TileSet::render(unsigned index, float x, float y)
{
    if (index<(unsigned)columns*rows)
    {
        int j=index/columns;
        int i=index%columns;
        tileSet.setClip(i*tileWidth,j*tileHeight,tileWidth,tileHeight);
        tileSet.pos = Vec2(x,y);
        tileSet.render();
    }
}

int TileSet::getTileWidth()
{
    return tileWidth;
}

int TileSet::getTileHeight()
{
    return tileHeight;
}
