#pragma once
#include "Object.h"
class Monster : public Object
{
private:
	Vector2 genPos;
	float	speed; 	
	float	maxDis; 
	int		dir;	// -1: ¿ÞÂÊ, 1: ¿À¸¥ÂÊ 
public: 
	float	GetSpeed() const { return speed; } 
	void	SetSpeed(float _speed) { speed = _speed; } 
	Vector2 GetGenPos() const { return genPos; } 
	void	SetGenPos(const Vector2& _genPos) { genPos = _genPos; } 
	float	GetMaxDis() const { return maxDis; }
	void	SetMaxDis(float _maxDis) { maxDis = _maxDis; } 
	int		GetDir() const { return dir; }
	void	SetDir(int _dir) { dir = _dir; } 

	virtual void Update() override;

			Monster();
	virtual ~Monster();

};

