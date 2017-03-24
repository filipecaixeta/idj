#include "face.h"

Face::Face(float x, float y):
    sp(new Sprite("img/penguinface.png")),hitpoints(30)
{
    box=Rect(x,y,sp->getDimencao());
    box.setXY(box.centro());
}

Face::~Face()
{
    delete sp;
}

void Face::damage(int _damage)
{
    hitpoints -= _damage;
}

void Face::update(float dt)
{

}

void Face::render()
{
    sp->render(box.x,box.y);
}

bool Face::isDead()
{
    return (hitpoints<=0);
}

void Face::rotaciona(float angle)
{
    sp->angle = angle;
}
