#include "pch.h" 

// 주의! precompiled header file은 첫째 줄에 include되어야 합니다. 

#include "Core.h" 
#include "TimeMgr.h" 
#include "KeyMgr.h" 
#include "SceneMgr.h" 
#include "Object.h" 

Core::Core() 
	: wnd(0), wndScale{}, dc(0),
	bitmap(0), memdc(0) 
{}

Core::~Core()
{
	// MSDN Reference 지침을 따른 삭제 함수 호출 
	ReleaseDC(wnd, dc);
	DeleteDC(memdc);
	DeleteObject(bitmap);
} 

int Core::Init(HWND _wnd, Vector2 _wndScale)
{
	// 멤버 변수 초기화 
	wnd = _wnd;
	wndScale = _wndScale; 
	dc = GetDC(_wnd); 

	// 여기서부터 게임 초기화 코드를 작성한다.
	RECT rt = {0, 0, LONG(wndScale.x), LONG(wndScale.y)};  
	// 해상도에 맞게 윈도우 크기 조정 
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, TRUE); 
	// 윈도우 버전에 관계없이 지정된 해상도의 창을 확보할 수 있다.  
	// rt에 윈도우 버전별로 창에 적용된 추가 영역을 계산하여 rt에 저장한다. 
	SetWindowPos(wnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); 	

	// 이중 버퍼링 용도의 비트맵과 DC를 만든다. 
	bitmap = CreateCompatibleBitmap(dc, int(wndScale.x), int(wndScale.y));  
	memdc = CreateCompatibleDC(dc); 

	HBITMAP hOldBit = (HBITMAP)SelectObject(memdc, bitmap);
	// 기존 1 pixel을 다루는 HBITMAP 변수는 새로운 hBit를 사용하면서 바로 삭제한다. 
	DeleteObject(hOldBit); 

	// Mgr 초기화 
	TM->Init(); 
	KM->Init();
	SM->Init();  
	
	return S_OK;
} 

void Core::Update()
{	
	TM->Update(); 
	KM->Update(); 
	SM->Update(); 	
}

void Core::Render()
{	
	Rectangle(memdc, -1, -1, wndScale.x + 1, wndScale.y + 1); 

	// 여기가 게임 렌더링의 도입부이다. 
	SM->Render(memdc); 

	BitBlt(dc, 0, 0, wndScale.x, wndScale.y, memdc, 0, 0, SRCCOPY); 
}

void Core::Run()
{	
	Update(); 
	Render();  	
}
