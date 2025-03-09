#pragma once 

class Core
{
	SINGLETON(Core); 

private:
	HWND	hWnd;
	Vector2	wndSize;
	HDC		hDC;

public:
	HWND GetHwnd() const { return hWnd; }
	Vector2 GetWndSize() const { return wndSize; }
	int Init(HWND _hWnd, Vector2 _wndSize); 
	void Run(); 

private:
	void Render();	
	void Update(); 

	void CallCntCheck() const;  
	void ArrowKeyEx() const;
};

