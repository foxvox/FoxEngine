#include "pch.h" 
#include "Core.h" 
#include "Object.h" 
#include "TimeMgr.h"
#include "KeyMgr.h" 
// 주의! precompiled header file은 첫째 줄에 include되어야 합니다. 

Object obj; 

Core::Core() 
	: hWnd(NULL), wndSize{}, hDC(NULL)
{}

Core::~Core()
{
	if (hDC)
	{
		ReleaseDC(hWnd, hDC);
		hDC = NULL;
	} 
} 

int Core::Init(HWND _hWnd, Vector2 _wndSize)
{
	hWnd = _hWnd;
	wndSize = _wndSize; 
	hDC = GetDC(hWnd); 

	// 여기서부터 게임 초기화 코드를 작성한다. 

	RECT rt = {0, 0, wndSize.x, wndSize.y}; 
	// 해상도에 맞게 윈도우 크기 조정 
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, TRUE); 
	// 윈도우 버전에 관계없이 지정된 해상도의 창을 확보할 수 있다.  
	// rt에 윈도우 버전별로 창에 적용된 추가 영역을 계산하여 rt에 저장한다. 
	SetWindowPos(hWnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); 	

	// Mgr 초기화 
	TimeMgr::GetInstance()->Init(); 

	// 여기서부터 게임 오브젝트 초기화 코드를 작성한다.
	obj.SetPos(Vector2(wndSize.x / 2.f, wndSize.y / 2.f)); 
	obj.SetSize(Vector2(100, 100)); 
	
	return S_OK;
} 

void Core::ArrowKeyEx() const 
{
	Vector2 tmpPos = obj.GetPos();
	// 물리적인 변경 사항을 반영하는 함수  
	// GetAsyncKeyState() 함수는 키보드의 상태를 반환하는 함수이다. 
	// 0X8000 즉 SHORT 최상위 비트가 1이면 눌린 상태이다. 
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000)
	{
		tmpPos.x -= 1;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000)
	{
		tmpPos.x += 1;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState('W') & 0x8000)
	{
		tmpPos.y -= 1;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState('S') & 0x8000)
	{
		tmpPos.y += 1;
	}

	obj.SetPos(tmpPos);
}

void Core::Update()
{
	ArrowKeyEx(); 
}

void Core::CallCntCheck() const 
{
	static int callCnt = 0;
	callCnt++; 

	static int prevTime = GetTickCount64();
	int			curTime = GetTickCount64(); 
	float dt = (curTime - prevTime) / 1000.f; 

	if (dt > 1)
	{
		// 윈도우 타이틀에 프레임 수 기록
		wchar_t title[256]{};
		swprintf_s(title, L"Frame Count: %d", callCnt);
		SetWindowText(hWnd, title);

		callCnt = 0;
		prevTime = curTime;
	}
}

void Core::Render()
{
	Vector2 tmpPos = obj.GetPos();
	Vector2 tmpSize = obj.GetSize(); 

	Rectangle(hDC, int(tmpPos.x - tmpSize.x / 2.f), int(tmpPos.y - tmpSize.y / 2.f),
					int(tmpPos.x + tmpSize.x / 2.f), int(tmpPos.y + tmpSize.y / 2.f));   

}

void Core::Run()
{
	CallCntCheck();

	Update(); 
	Render(); 	
}
