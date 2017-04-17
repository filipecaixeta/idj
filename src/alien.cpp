#include <alien.h>
#include <inputmanager.h>
#include <iostream>
#include <math.h>

Alien::Alien(float x,float y, int nMinions):
    sp_("img/alien.png")
{
    box=Rect(x,y,sp_.getDimencao());
    box.setXY(box.centro());
    sp_.pos=Vec2(x,y);
    sp_.fix=false;

    for(int i=0; i<nMinions; i++)
    {
        float ang = 2*M_PI/nMinions*i;
        minionArray_.push_back(Minion(this,ang));
    }
}

Alien::~Alien()
{
    minionArray_.clear();
}

void Alien::update(float dt)
{
    Vec2 mousePos = InputManager::getInstance().getWorldMouseXY();

    if (InputManager::getInstance().mousePress(SDL_BUTTON_LEFT))
    {
        taskQueue_.push(Action(Action::SHOOT,mousePos));
    }
    else if (InputManager::getInstance().mousePress(SDL_BUTTON_RIGHT))
    {
        taskQueue_.push(Action(Action::MOVE,mousePos));
    }

    for(;!taskQueue_.empty();taskQueue_.pop())
    {
        Action act = taskQueue_.front();
        if (act.type==Action::MOVE)
        {
            speed_ = Vec2(act.pos-sp_.getCenter()).normalizado()*150;
            targetPos_ = act.pos;
        }
        if (act.type==Action::SHOOT)
        {
            Vec2 minDist(99999,99999);
            Minion *minMin;
            for(Minion &minion: minionArray_)
            {
                mousePos;
                Vec2 dist = minion.getCenter()-mousePos;
                if (dist.abs()<minDist.abs())
                {
                    minDist = dist;
                    minMin = &minion;
                }
            }
            minMin->shoot(mousePos);
        }
    }
    Vec2 ds = speed_*dt;
    if (ds.abs()>targetPos_.distancia(sp_.getCenter()+ds))
        speed_ = Vec2(0.0f,0.0f);
    sp_.pos = sp_.pos+speed_*dt;
    box.setXY(sp_.pos);
    sp_.angle += dt*M_PI_2;

    for(Minion &minion: minionArray_)
    {
        minion.update(dt);
    }
}

Vec2 Alien::getCenter()
{
    return sp_.getCenter();
}

void Alien::render()
{
    sp_.render();
    for(Minion &minion: minionArray_)
    {
        minion.render();
    }
}

bool Alien::isDead()
{
    return (hp_<=0);
}

void Alien::setPosition(Vec2 pos)
{
    sp_.pos = pos;
}

void Alien::rotaciona(float angle)
{

}

Alien::Action::Action(Alien::Action::ActionType type_, float x, float y):
    type(type_),pos(x,y)
{

}

Alien::Action::Action(Alien::Action::ActionType type_, Vec2 pos_):
    type(type_),pos(pos_)
{

}
