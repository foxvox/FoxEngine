#include "pch.h"
#include "Player.h" 
#include "TimeMgr.h" 
#include "KeyMgr.h" 
#include "SceneMgr.h" 
#include "Missile.h" 
#include "Scene.h" 

Player::Player()
{}

Player::~Player()
{} 

void Player::CreateMissile()
{
	Vector2 missilePos = pos;
	missilePos.y -= scale.y / 2.f; 

	Missile* missile = new Missile;
	missile->SetPos(missilePos);
	missile->SetScale(Vector2(4.f, 30.f));
	missile->SetDir(-1.f);
	missile->SetSpeed(700.f);
	
	Scene* curScene = SM->GetCurScene(); 
	curScene->AddObject(missile, GroupType::DEFAULT); 
}

void Player::Update()
{
	KeyState hold = KeyState::HOLD; 
	
	if (KM->GetKeyState(Key::W) == hold
		|| KM->GetKeyState(Key::UP) == hold)
	{
		pos.y -= 500.f * DT;
	}

	if (KM->GetKeyState(Key::S) == hold
		|| KM->GetKeyState(Key::DOWN) == hold)
	{
		pos.y += 500.f * DT;
	}

	if (KM->GetKeyState(Key::A) == hold
		|| KM->GetKeyState(Key::LEFT) == hold)
	{
		pos.x -= 500.f * DT;
	}

	if (KM->GetKeyState(Key::D) == hold
		|| KM->GetKeyState(Key::RIGHT) == hold)
	{
		pos.x += 500.f * DT;
	}

	if (KM->GetKeyState(Key::SPACE) == KeyState::TAP)
	{
		CreateMissile();
	}
}

