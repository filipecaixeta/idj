#ifndef BULLET_H
#define BULLET_H
#include <gameobject.h>
#include <sprite.h>

class Bullet : public GameObject
{
public:
    Bullet(float x,float y, float angle, float speed, float maxDistance, string sprite);
    Bullet(Vec2 pos, Vec2 speed, float maxDistance, string sprite);
    ~Bullet();
    void update(float dt);
    void render();
    bool isDead();
    void rotaciona(float angle);

private:
    Sprite sp_;
    Vec2 speed_;
    float distanceLeft_;
};

#endif // BULLET_H
