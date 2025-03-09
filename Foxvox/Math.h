#pragma once 

struct Vector2
{
	float x;
	float y; 

	Vector2() : x(0.f), y(0.f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {} 
	Vector2(const Vector2& _v) : x(_v.x), y(_v.y) {} 
	Vector2& operator=(const Vector2& _v)
	{
		x = _v.x;
		y = _v.y;
		return *this;
	}
	Vector2(int _x, int _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) {} 
}; 
