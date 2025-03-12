#include "pch.h" 
#include "Core.h" 
#include "Object.h" 
#include "TimeMgr.h"
#include "KeyMgr.h" 
// ����! precompiled header file�� ù° �ٿ� include�Ǿ�� �մϴ�. 

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

	// ���⼭���� ���� �ʱ�ȭ �ڵ带 �ۼ��Ѵ�. 

	RECT rt = {0, 0, wndSize.x, wndSize.y}; 
	// �ػ󵵿� �°� ������ ũ�� ���� 
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, TRUE); 
	// ������ ������ ������� ������ �ػ��� â�� Ȯ���� �� �ִ�.  
	// rt�� ������ �������� â�� ����� �߰� ������ ����Ͽ� rt�� �����Ѵ�. 
	SetWindowPos(hWnd, NULL, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0); 	

	// Mgr �ʱ�ȭ 
	TimeMgr::GetInst()->Init(); 
	KeyMgr::GetInst()->Init();

	// ���⼭���� ���� ������Ʈ �ʱ�ȭ �ڵ带 �ۼ��Ѵ�.
	obj.SetPos(Vector2(wndSize.x / 2.f, wndSize.y / 2.f)); 
	obj.SetSize(Vector2(100, 100)); 
	
	return S_OK;
} 

void Core::ArrowKeyEx() const 
{
	Vector2 pos = obj.GetPos();
	float dt = TimeMgr::GetInst()->GetDT(); 
	// �������� ���� ������ �ݿ��ϴ� �Լ�  
	// GetAsyncKeyState() �Լ��� Ű������ ���¸� ��ȯ�ϴ� �Լ��̴�. 
	// 0X8000 �� SHORT �ֻ��� ��Ʈ�� 1�̸� ���� �����̴�. 
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000)
	{
		// foo * dt => �� ���ɿ� ������� 1�ʿ� foo pixel ������ �� �ִ�. 
		// ���� ������ �ð� ����ȭ�� �̷������. 
		pos.x -= 400.f * dt;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000)
	{
		pos.x += 400.f * dt;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState('W') & 0x8000)
	{
		pos.y -= 400.f * dt;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState('S') & 0x8000)
	{
		pos.y += 400.f * dt;
	}

	obj.SetPos(pos);
}

void Core::Update()
{	
	TimeMgr::GetInst()->Update(); 	

	ArrowKeyEx();
}

void Core::CallCntCheck() const 
{
	static int callCnt = 0;
	callCnt++; 

	static int prevTime = GetTickCount64();
	int		   curTime = GetTickCount64(); 
	float dt = (curTime - prevTime) / 1000.f; 

	if (dt >= 1.f)
	{
		// ������ Ÿ��Ʋ�� ������ �� ���
		wchar_t title[256]{};
		swprintf_s(title, L"Frame Count: %d", callCnt);
		SetWindowTextW(hWnd, title);

		callCnt = 0;
		prevTime = curTime;
	}
}

void Core::Render()
{
	Vector2 pos = obj.GetPos();
	Vector2 size = obj.GetSize(); 

	Rectangle(hDC, int(pos.x - size.x / 2.f), int(pos.y - size.y / 2.f),
					int(pos.x + size.x / 2.f), int(pos.y + size.y / 2.f));   

}

void Core::Run()
{	
	Update(); 
	Render(); 	
}
