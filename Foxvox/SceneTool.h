#pragma once
#include "Scene.h"
class SceneTool : public Scene
{ 
public:
	virtual void Enter();
	virtual void Exit(); 

	SceneTool();
	~SceneTool();
};

