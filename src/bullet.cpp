#include <bullet.h>
#include <camera.h>

Bullet::Bullet(float x, float y, float angle, float speed, float maxDistance, string sprite):
    sp_(sprite),
    speed_(speed,0.0f),
    distanceLeft_(maxDistance)
{
    box=Rect(x,y,sp_.getDimencao());
    box.setXY(box.centro());
    speed_ = speed_.rotacionado(angle);
    sp_.angle = angle;
}

Bullet::Bullet(Vec2 pos, Vec2 speed, float maxDistance, string sprite):
    sp_(sprite),
    speed_(speed),
    distanceLeft_(maxDistance)
{
    box=Rect(pos.x,pos.y,sp_.getDimencao());
    sp_.angle = speed.angulo();
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
    distanceLeft_ -= (speed_*dt).abs();
    box.setXY(box.getXY()+speed_*dt);
    sp_.pos = box.getXY();
}

void Bullet::render()
{
    sp_.render();
}

bool Bullet::isDead()
{
    return distanceLeft_<=0;
}

void Bullet::rotaciona(float angle)
{
    sp_.angle = angle;
}
