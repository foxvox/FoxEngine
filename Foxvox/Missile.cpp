#include "pch.h"
#include "Missile.h" 
#include "TimeMgr.h" 

Missile::Missile() 
	: speed(700.f), dir(0.f) 
{ 
	scale = { 4.f, 30.f }; 
}

Missile::~Missile()
{
}

void Missile::Update()
{	
	pos.y += speed * DT * dir; 
}

void Missile::Render(HDC _dc)
{
	Ellipse(_dc, int(pos.x - scale.x / 2.f), int(pos.y - scale.y / 2.f), 
		int(pos.x + scale.x / 2.f), int(pos.y + scale.y / 2.f)); 
}


