#pragma once 

class Scene; 

class SceneMgr
{ 
	SINGLETON(SceneMgr); 

private:
	Scene* scenes[(UINT)SceneType::MAX]; 
	Scene* curScene; 

public: 
	void Init();
	void Update(); 
	void Render(HDC _memdc); 

	Scene* GetCurScene() const { return curScene; } 
};

