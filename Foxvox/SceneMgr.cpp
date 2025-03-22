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

	// ���� ���� SCENE_START�� �����ϰ� Enter() �Լ��� ȣ���Ѵ�. 
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
