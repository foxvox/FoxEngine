#pragma once
#include "Scene.h"
class SceneStart : public Scene
{
public:
	// 명시적으로 가상함수를 재정의하는 것을 권장한다. 
	virtual void Enter(); 
	virtual void Exit(); 

	SceneStart();
	~SceneStart();
};

