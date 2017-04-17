#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <rect.h>
#include <vec2.h>

class GameObject
{
public:
    GameObject(){}
    virtual ~GameObject(){}
    virtual void update(float dt)=0;
    virtual void render()=0;
    virtual bool isDead()=0;
    virtual void rotaciona(float angle)=0;
    Vec2 getCenter(){return box.getXY()+box.getWH()/2;}

    Rect box;
};

#endif // GAMEOBJECT_H
