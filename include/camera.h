#ifndef CAMERA_H
#define CAMERA_H
#include <gameobject.h>
#include <vec2.h>

class Camera
{
public:
    static Camera& getInstance()
    {
      static Camera camera;
      return camera;
    }
    void follow(GameObject *newFocus);
    void unfollow();
    void update(float dt);
    Vec2 window2world(Vec2 windowPos);
    Vec2 world2window(Vec2 worldPos);

    Vec2 pos;
    Vec2 speed;

private:
    Camera();
    Camera(Camera const&);
    Camera& operator=(Camera const&);
    ~Camera();

    GameObject *focus_;
};

#endif // CAMERA_H
