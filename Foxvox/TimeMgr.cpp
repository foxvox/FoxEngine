#include "pch.h"
#include "TimeMgr.h"

TimeMgr::TimeMgr() 
	:curCnt{}, frequency{} 
{}

TimeMgr::~TimeMgr()
{}

void TimeMgr::Init()
{
	QueryPerformanceCounter(&curCnt); 
	QueryPerformanceFrequency(&frequency);  
}
