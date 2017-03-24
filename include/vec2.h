#ifndef VEC2_H
#define VEC2_H
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Vec2
{
public:
    Vec2(){x=0;y=0;}
    Vec2(float x,float y){this->x=x;this->y=y;}
    Vec2(vector<float> v){this->x=v[0];this->y=v[1];}
	~Vec2(){}
	float x;
	float y;

	Vec2 operator+(const Vec2& v1) 
	{
		return Vec2(x+v1.x,y+v1.y);
    }
	Vec2 operator-(const Vec2& v1) 
	{
		return Vec2(x-v1.x,y-v1.y);
    }
	Vec2 operator*(const Vec2& v1) 
	{
		return Vec2(x*v1.x,y*v1.y);
    }
	Vec2 operator*(const float v) 
	{
		return Vec2(x*v,y*v);
    }
	Vec2 operator/(const float v) 
	{
		return Vec2(x/v,y/v);
    }
	float dot(const Vec2& v1) 
	{
		return (x*v1.x+y*v1.y);
    }
	float abs()
	{
		return sqrt(x*x+y*y);
    }
	float norm()
	{
		return this->abs();
	}
	Vec2 normalizado()
	{
		float norm = abs();
		return Vec2(x/norm,y=y/norm);
	}
	float distancia(const Vec2& v1)
	{
		return (*this-v1).abs();
	}
	float angulo()
	{
		return atan2(y,x);
	}
	float inclinacao(const Vec2& v1)
	{
		return (v1.y-y)/(v1.x-x);
	}
	Vec2 rotacionado(float ang)
	{
		return Vec2(x*cos(ang)-y*sin(ang),y*cos(ang)+x*sin(ang));
	}
	friend bool operator==(const Vec2 &v1, const Vec2 &v2)
	{
		return (v1.x==v2.x)&&(v1.y==v2.y);
	}
    friend bool operator!=(const Vec2 &v1, const Vec2 &v2)
    {
    	return !(v1==v2);
    }
	friend ostream& operator<<(ostream& os, const Vec2& v) 
	{
	    os <<'('<< v.x <<','<< v.y <<')';
		return os;
	}
};

#endif // GAME_H
