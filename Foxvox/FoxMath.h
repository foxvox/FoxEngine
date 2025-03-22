#pragma once 

struct Vector2
{
	float x;
	float y; 

	Vector2() : x(0.f), y(0.f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {} 
	Vector2(const Vector2& _v) : x(_v.x), y(_v.y) {} 
	Vector2(int _x, int _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) {} 

	Vector2& operator=(const Vector2& _v) 
	{
		x = _v.x;
		y = _v.y;
		return *this;
	} 	
}; 

class FoxMath 
{
public:
	static float GetDistance(const Vector2& _v1, const Vector2& _v2)
	{
		float x = _v1.x - _v2.x;
		float y = _v1.y - _v2.y;
		return sqrtf(x * x + y * y);
	} 
}; 