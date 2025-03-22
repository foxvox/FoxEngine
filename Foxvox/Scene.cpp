#include "pch.h" 
#include "Scene.h" 
#include "Object.h" 

void Scene::Update()
{	
	for (int i = 0; i < (int)GroupType::MAX; i++)
	{
		for (int j = 0; j < objGroups[i].size(); j++)
		{
			objGroups[i][j]->Update();			
		}
	}
}

void Scene::Render(HDC _dc)
{	
	for (int i = 0; i < (int)GroupType::MAX; i++)
	{
		for (int j = 0; j < objGroups[i].size(); j++)
		{
			objGroups[i][j]->Render(_dc); 			
		}
	}
}

Scene::Scene()
	: name(L"") 
{
}

Scene::~Scene()
{	
	for (int i = 0; i < (int)GroupType::MAX; i++)
	{
		for (int j = 0; j < objGroups[i].size(); j++)
		{			
			SAFE_DELETE(objGroups[i][j]); 
		}
	}
}
