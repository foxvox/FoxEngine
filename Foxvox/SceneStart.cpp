#include "pch.h"
#include "SceneStart.h" 
#include "Core.h" 
#include "Object.h" 
#include "Player.h" 
#include "Monster.h" 

void SceneStart::Enter()
{
	Vector2 wndScale = CORE->GetWndScale();

	// Player 추가   
	Object* obj = new Player; 
	obj->SetPos(Vector2(wndScale.x / 2.f, wndScale.y / 2.f));
	obj->SetScale(Vector2(50.f, 50.f));
	AddObject(obj, GroupType::DEFAULT); 

	// Monster 배치 
	int monCnt = 10;
	float monGap = wndScale.x / float(monCnt);
	Vector2 monScale{ 40.f, 40.f }; 

	Monster* monster = nullptr; 
	// Monster 추가 
	for (int i = 0; i < monCnt; i++)
	{
		monster = new Monster;
		monster->SetPos(Vector2(monGap / 2.f + i * monGap, 100.f));
		monster->SetGenPos(monster->GetPos());
		monster->SetScale(monScale); 
		AddObject(monster, GroupType::DEFAULT);
	}	
}

void SceneStart::Exit()
{
}

SceneStart::SceneStart()
{
}

SceneStart::~SceneStart()
{
}
