#pragma once 

class Core
{
	SINGLETON(Core); 

private:
	HWND		hWnd;
	HDC			hDC;
	Vector2		wndSize;

	HBITMAP		hBit;
	HDC			memDC;

public:
	HWND	GetMyWnd() const { return hWnd; }
	HDC		GetMyDC() const { return hDC; } 
	Vector2	GetWndSize() const { return wndSize; }
	int		Init(HWND _hWnd, Vector2 _wndSize); 
	void	Run(); 

private:
	void Render();	
	void Update(); 

	void CallCntCheck() const;  
	void ArrowKeyEx() const;
};

