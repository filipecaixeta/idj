#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <unordered_map>
#include <vector>
#include <SDL2/SDL.h>
#include <vec2.h>

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager
{
public:
    static InputManager& getInstance()
    {
      static InputManager inputManager;
      return inputManager;
    }
    void update();
    bool keyPress(int key);
    bool keyRelease(int key);
    bool isKeyDown(int key);
    bool keyPress(char key);
    bool keyRelease(char key);
    bool isKeyDown(char key);

    bool mousePress(int button);
    bool mouseRelease(int button);
    bool isMouseDown(int button);

    int getMouseX();
    int getMouseY();
    Vec2 getMouseXY();
    Vec2 getWorldMouseXY();

    bool quitRequested();
private:
    InputManager();
    InputManager(InputManager const&);
    InputManager& operator=(InputManager const&);
    ~InputManager();

    std::vector<std::pair<bool,int> > mouse_;
    std::vector<std::pair<bool,int> > key_;
    bool quitrequested_;
    int updateCounter_;
    int mouseX_;
    int mouseY_;
};

#endif // INPUTMANAGER_H
