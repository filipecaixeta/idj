#ifndef MINION_H
#define MINION_H
#include <gameobject.h>
#include <sprite.h>
#include <vector>
#include <queue>
#include <vec2.h>

class Minion : public GameObject
{
public:
    Minion(GameObject *parent, float arcOffset);
    ~Minion();

    void update(float dt);
    void render();
    bool isDead();
    void shoot(Vec2 pos);
    void rotaciona(float angle);

private:
    Sprite sp_;
    float arc_;
    GameObject *parent_;
    Vec2 radius_;
};

#endif // MINION_H
