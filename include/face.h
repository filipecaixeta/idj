#ifndef FACE_H
#define FACE_H
#include "gameobject.h"
#include <sprite.h>

class Face : public GameObject
{
public:
    Face(float x,float y);
    ~Face();
    void damage(int _damage);
    void update(float dt);
    void render();
    bool isDead();
    void rotaciona(float angle);

private:
    int hitpoints;
    Sprite *sp;
};

#endif // FACE_H
