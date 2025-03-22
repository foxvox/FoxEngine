#include "pch.h" 

// ����! precompiled header file�� ù° �ٿ� include�Ǿ�� �մϴ�. 

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
	// MSDN Reference ��ħ�� ���� ���� �Լ� ȣ�� 
	ReleaseDC(wnd, dc);
	DeleteDC(memdc);
	DeleteObject(bitmap);
} 

int Core::Init(HWND _wnd, Vector2 _wndScale)
{
	// ��� ���� �ʱ�ȭ 
	wnd = _wnd;
	wndScale = _wndScale; 
	dc = GetDC(_wnd); 

	// ���⼭���� ���� �ʱ�ȭ �ڵ带 �ۼ��Ѵ�.
	RECT rt = {0, 0, LONG(wndScale.x), LONG(wndScale.y)};  
	// �ػ󵵿� �°� ������ ũ�� ���� 
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, TRUE); 
	// ������ ������ ������� ������ �ػ��� â�� Ȯ���� �� �ִ�.  
	// rt�� ������ �������� â�� ����� �߰� ������ ����Ͽ� rt�� �����Ѵ�. 
	SetWindowPos(wnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); 	

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����. 
	bitmap = CreateCompatibleBitmap(dc, int(wndScale.x), int(wndScale.y));  
	memdc = CreateCompatibleDC(dc); 

	HBITMAP hOldBit = (HBITMAP)SelectObject(memdc, bitmap);
	// ���� 1 pixel�� �ٷ�� HBITMAP ������ ���ο� hBit�� ����ϸ鼭 �ٷ� �����Ѵ�. 
	DeleteObject(hOldBit); 

	// Mgr �ʱ�ȭ 
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

	// ���Ⱑ ���� �������� ���Ժ��̴�. 
	SM->Render(memdc); 

	BitBlt(dc, 0, 0, wndScale.x, wndScale.y, memdc, 0, 0, SRCCOPY); 
}

void Core::Run()
{	
	Update(); 
	Render();  	
}
