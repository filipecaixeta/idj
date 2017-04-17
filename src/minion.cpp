#include <minion.h>
#include <inputmanager.h>
#include <iostream>
#include <game.h>
#include <bullet.h>

Minion::Minion(GameObject *parent, float arcOffset):
    sp_("img/minion.png"),
    arc_(arcOffset),
    parent_(parent),
    radius_(150,0)
{
    sp_.pos = parent_->getCenter()+radius_.rotacionado(arc_)-sp_.getDimencao()/2;
    sp_.fix = false;
    sp_.angle = arc_;
    float scale = (rand()%500)/1000.0 + 1.0;
    sp_.setScaleXY(Vec2(scale,scale));
}

Minion::~Minion()
{
}

void Minion::update(float dt)
{
    arc_ += dt*0.5;
    sp_.pos = parent_->getCenter()+radius_.rotacionado(arc_)-sp_.getDimencao()/2;
    box.setXY(sp_.pos);
    sp_.angle -= dt*0.5;
}

void Minion::render()
{
    sp_.render();
}

bool Minion::isDead()
{
    return false;
}

void Minion::shoot(Vec2 pos)
{
    Game::getInstance().getState().addObject(new Bullet(sp_.pos, (pos-sp_.pos).normalizado()*300.0,1000.0,"img/minionbullet1.png"));
}

void Minion::rotaciona(float angle)
{

}
