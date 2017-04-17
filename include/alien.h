#ifndef ALIEN_H
#define ALIEN_H
#include <gameobject.h>
#include <sprite.h>
#include <vector>
#include <queue>
#include <vec2.h>
#include <minion.h>

class Alien : public GameObject
{
public:
    Alien(float x,float y, int nMinions);
    ~Alien();

    void update(float dt);
    Vec2 getCenter();
    void render();
    bool isDead();
    void setPosition(Vec2 pos);
    void rotaciona(float angle);

private:
    class Action
    {
    public:
        enum ActionType{MOVE,SHOOT};
        Action(ActionType type_, float x, float y);
        Action(ActionType type_, Vec2 pos_);
        ActionType type;
        Vec2 pos;
    };

    Sprite sp_;
    Vec2 speed_;
    Vec2 targetPos_;
    int hp_;

    std::queue<Action> taskQueue_;
    std::vector<Minion> minionArray_;
};

#endif // ALIEN_H
