#include "pch.h" 
#include "KeyMgr.h" 
#include "TimeMgr.h" 
#include "Object.h" 

void Object::Render(HDC _dc)
{
	Rectangle(_dc, int(pos.x - scale.x / 2.f), int(pos.y - scale.y / 2.f),
		int(pos.x + scale.x / 2.f), int(pos.y + scale.y / 2.f));
}

Object::Object()
	: pos{}, scale{} 
{}

Object::~Object()
{}
