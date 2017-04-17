#ifndef RECT_H
#define RECT_H
#include <iostream>
#include <cmath>
#include <vector>
#include <vec2.h>

using namespace std;

class Rect
{
public:
        Rect(){x=0;y=0;w=0;h=0;}
        Rect(float x, float y,float w, float h){this->x=x;this->y=y;this->w=w;this->h=h;}
        Rect(Vec2 v1,Vec2 v2){x=v1.x;y=v1.y;w=v2.x;h=v2.y;}
        Rect(Vec2 v1,float w, float h){x=v1.x;y=v1.y;this->w=w;this->h=h;}
        Rect(float x, float y,Vec2 v2){this->x=x;this->y=y;w=v2.x;h=v2.y;}
        Rect(vector<float> v){this->x=v[0];this->y=v[1];this->w=v[2];this->h=v[3];}
	~Rect(){}
	float x,y,w,h;
    void setXY(Vec2 v)
    {
        x=v.x;
        y=v.y;
    }
    Vec2 getXY()
    {
        return Vec2(x,y);
    }
    void setWH(Vec2 v)
    {
        w=v.x;
        h=v.y;
    }
    Vec2 getWH()
    {
        return Vec2(w,h);
    }
	Rect operator+(const Vec2& v1) 
	{
		return Rect(x+v1.x,y+v1.y,w+v1.x,h+v1.y);
    }
	Rect operator-(const Vec2& v1) 
	{
		return Rect(x-v1.x,y-v1.y,w-v1.x,h-v1.y);
    }
	Vec2 centro()
	{
        return Vec2(x-w/2,y-h/2);
    }
//    float distancia(const Rect& r)
//    {
//        return sqrt(r.centro().distancia(centro()));
//    }
    bool isInside(Vec2 v)
    {
        return (v.x>=x)&&(v.x<=(x+w))&&(v.y>=y)&&(v.y<=(y+h));
    }
    bool isInside(float x,float y)
    {
        return isInside(Vec2(x,y));
    }
	friend bool operator==(const Rect &r1, const Rect &r2)
	{
		return (r1.x==r2.x)&&(r1.y==r2.y)&&(r1.w==r2.w)&&(r1.h==r2.h);
	}
    friend bool operator!=(const Rect &r1, const Rect &r2)
    {
    	return !(r1==r2);
    }
    friend ostream& operator<<(ostream& os, const Rect& v)
	{
	    os <<'('<< v.x <<','<< v.y <<','<< v.w <<','<< v.h <<')';
		return os;
	}
};

#endif // GAME_H
