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
	// ���� cnt
	QueryPerformanceCounter(&prevCnt);
	// �ʴ� cnt : õ�� 
	QueryPerformanceFrequency(&freq);  
}

void TimeMgr::Update()
{
	CheckFPS(); 
}

void TimeMgr::CheckFPS()
{
	// 2��° ���� curCnt ���� 
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

		// ������ Ÿ��Ʋ�� ������ �� ���
		wchar_t title[256]{};
		swprintf_s(title, L"fps: %d, dt: %f", fps, dt);
		SetWindowTextW(CORE->GetMainWnd(), title);

		callCnt = 0;
		acct = 0.f;
	}

	isFirst = false;
}
