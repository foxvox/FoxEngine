#include "pch.h"
#include "SceneMgr.h"
#include "SceneStart.h" 
#include "SceneTool.h" 

SceneMgr::SceneMgr() 
	: scenes{}, curScene(nullptr)
{
	SCENE_TOOL = nullptr;
	SCENE_START = nullptr;	
}

SceneMgr::~SceneMgr()
{
	for (int i = 0; i < (int)SceneType::MAX; i++)
	{
		SAFE_DELETE(scenes[i]);
	} 
}

void SceneMgr::Init()
{
	SCENE_START = new SceneStart;
	SCENE_START->SetName(L"Scene Start"); 

	// SCENE_TOOL = new SceneTool;
	// SCENE_TOOL->SetName(L"Scene Tool");

	// 현재 씬을 SCENE_START로 설정하고 Enter() 함수를 호출한다. 
	curScene = SCENE_START; 
	curScene->Enter(); 
}

void SceneMgr::Update()
{
	curScene->Update();
}

void SceneMgr::Render(HDC _dc)
{
	curScene->Render(_dc);
} 
