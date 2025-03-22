#pragma once
#include "Object.h"

class Missile : public Object
{
private: 
	float  dir;
	float	 speed;	

public:	
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

	void SetDir(float _dir) { dir = _dir; }
	void SetSpeed(float _speed) { speed = _speed; }	

	Missile();
	virtual ~Missile();
};

