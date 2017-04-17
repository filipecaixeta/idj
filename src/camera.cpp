#include <camera.h>
#include <inputmanager.h>
#include <iostream>
#include <game.h>

Camera::Camera():
    pos(0,0),
    speed(0,0),
    focus_(nullptr)
{

}

Camera::~Camera()
{

}

void Camera::follow(GameObject *newFocus)
{
    focus_ = newFocus;
}

void Camera::unfollow()
{
    focus_ = nullptr;
}

void Camera::update(float dt)
{
    const Vec2 maxSpeed(300.0f,300.0f);

    if (focus_ == nullptr)
    {
        if (InputManager::getInstance().isKeyDown(SDLK_LEFT) || InputManager::getInstance().isKeyDown(SDLK_RIGHT))
        {
            if (InputManager::getInstance().isKeyDown(SDLK_LEFT))
                speed.x = -maxSpeed.x;
            else if (InputManager::getInstance().isKeyDown(SDLK_RIGHT))
                speed.x = maxSpeed.x;
        }
        else
            speed.x = 0.0f;
        if (InputManager::getInstance().isKeyDown(SDLK_UP) || InputManager::getInstance().isKeyDown(SDLK_DOWN))
        {
            if (InputManager::getInstance().isKeyDown(SDLK_UP))
                speed.y = maxSpeed.y;
            else if (InputManager::getInstance().isKeyDown(SDLK_DOWN))
                speed.y = -maxSpeed.y;
        }
        else
            speed.y = 0.0f;
    }
    pos = pos+speed*dt;

}

Vec2 Camera::window2world(Vec2 windowPos)
{
    return Vec2(windowPos.x+pos.x,Game::getInstance().getWindowDimensions().y-(windowPos.y-pos.y));
}

Vec2 Camera::world2window(Vec2 worldPos)
{
    return Vec2(worldPos.x-pos.x,Game::getInstance().getWindowDimensions().y-(worldPos.y-pos.y));
}
