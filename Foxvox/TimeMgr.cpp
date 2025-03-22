#include "pch.h"
#include "TimeMgr.h"
#include "Core.h" 

TimeMgr::TimeMgr() 
	:curCnt{}, prevCnt{}, freq{}, callCnt(0), fps(0), dt(0.f), acct(0.f), isFirst(true)
{}

TimeMgr::~TimeMgr()
{}

void TimeMgr::Init()
{
	// 이전 cnt
	QueryPerformanceCounter(&prevCnt);
	// 초당 cnt : 천만 
	QueryPerformanceFrequency(&freq);  
}

void TimeMgr::Update()
{
	CheckFPS(); 
}

void TimeMgr::CheckFPS()
{
	// 2번째 부터 curCnt 적용 
	if (!isFirst)   
	{
		
		QueryPerformanceCounter(&curCnt);
		dt = static_cast<float>(curCnt.QuadPart - prevCnt.QuadPart) / static_cast<float>(freq.QuadPart); 
		prevCnt = curCnt;
	}

	callCnt++;
	acct += dt;

	if (acct > 1.f)
	{
		fps = callCnt;

		// 윈도우 타이틀에 프레임 수 기록
		wchar_t title[256]{};
		swprintf_s(title, L"fps: %d, dt: %f", fps, dt);
		SetWindowTextW(CORE->GetMainWnd(), title);

		callCnt = 0;
		acct = 0.f;
	}

	isFirst = false;
}
