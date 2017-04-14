#include "inputmanager.h"
#include <algorithm>
#include <iostream>
#include <camera.h>

InputManager::InputManager():
    mouse_(6, std::make_pair(false, 0)),
    key_(416, std::make_pair(false, 0)),
    quitrequested_(false),
    updateCounter_(0),
    mouseX_(0),
    mouseY_(0)
{

}

InputManager::~InputManager()
{

}

void InputManager::update()
{
    SDL_Event event;
    quitrequested_ = false;
    updateCounter_ += 1;
    SDL_GetMouseState(&mouseX_, &mouseY_);

    while (SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
            quitrequested_ = true;

        if(event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
        {
            int button = (int)event.button.button;
            mouse_[button].first = (event.button.state==SDL_PRESSED?true:false);
            mouse_[button].second = updateCounter_;
        }
        if( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
        {
            if (event.key.repeat!=0)
                continue;
            int key = (int)event.key.keysym.sym;
            key = key&(1<<30)?key-0x3FFFFF81:key; // Ajuste das teclas depois de (1<<30)
            key_[key].first = (event.key.state==SDL_PRESSED?true:false);
            key_[key].second = updateCounter_;
        }
    }
}

bool InputManager::keyPress(int key)
{
    key = key&(1<<30)?key-0x3FFFFF81:key;
    return (key_[key].second==updateCounter_)&&key_[key].first;
}

bool InputManager::keyPress(char key)
{
    return keyPress((int)key);
}

bool InputManager::keyRelease(int key)
{
    return !keyPress(key);
}

bool InputManager::keyRelease(char key)
{
    return keyRelease((int)key);
}

bool InputManager::isKeyDown(int key)
{
    key = key&(1<<30)?key-0x3FFFFF81:key;
    return key_[key].first;
}

bool InputManager::isKeyDown(char key)
{
    return isKeyDown((int)key);
}

bool InputManager::mousePress(int button)
{
    return ((mouse_[button].second==updateCounter_)&&mouse_[button].first);
}

bool InputManager::mouseRelease(int button)
{
    return !mousePress(button);
}

bool InputManager::isMouseDown(int button)
{
    return mouse_[button].first;
}

int InputManager::getMouseX()
{
    return mouseX_;
}

int InputManager::getMouseY()
{
    return mouseY_;
}

Vec2 InputManager::getMouseXY()
{
    return Vec2((float)mouseX_,(float)mouseY_);
}

Vec2 InputManager::getWorldMouseXY()
{
    return Camera::getInstance().window2world(getMouseXY());
}

bool InputManager::quitRequested()
{
    return quitrequested_;
}
