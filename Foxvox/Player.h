#pragma once
#include "Object.h"
class Player : public Object
{
public:
	void CreateMissile();
	virtual void Update() override;

	Player();
	~Player(); 	
};

