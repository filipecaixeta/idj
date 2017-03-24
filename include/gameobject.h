#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "rect.h"

class GameObject
{
public:
    GameObject(){}
    virtual ~GameObject(){}
    virtual void update(float dt)=0;
    virtual void render()=0;
    virtual bool isDead()=0;
    virtual void rotaciona(float angle)=0;

    Rect box;
};

#endif // GAMEOBJECT_H
