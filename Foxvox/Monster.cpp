#include "pch.h"
#include "Monster.h" 
#include "TimeMgr.h" 

Monster::Monster() 
	: genPos{}, speed(100.f), maxDis(25.f), dir(1) 
{}

Monster::~Monster()
{}

void Monster::Update()
{
	Vector2 curPos = pos;
	curPos.x += speed * DT * dir; 

	float dis = FoxMath::GetDistance(genPos, curPos); 
	float diff = dis - maxDis;

	if (diff > 0.f) 
	{
		dir *= -1; 
		diff += 1.f;  
		curPos.x += diff * dir;
	} 

	pos = curPos; 
}

