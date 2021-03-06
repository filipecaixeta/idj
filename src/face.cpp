#include <face.h>
#include <camera.h>

Face::Face(float x, float y):
    hitpoints(30),
    sp(new Sprite("img/penguinface.png"))
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
    sp->pos=Vec2(box.x,box.y);
    sp->render();
}

bool Face::isDead()
{
    return (hitpoints<=0);
}

void Face::rotaciona(float angle)
{
    sp->angle = angle;
}
