#pragma once 

class Core
{
	SINGLETON(Core); 

private:
	HWND		wnd;
	HDC			dc;
	Vector2		wndScale;

	HBITMAP		bitmap;
	HDC			memdc; 

public:
	HWND	GetMainWnd() const { return wnd; }
	HDC		GetMainDC() const { return dc; } 	
	Vector2	GetWndScale() const { return wndScale; }
	HBITMAP GetBitmap() const { return bitmap; }
	HDC		GetMemDC() const { return memdc; } 

	int		Init(HWND _hWnd, Vector2 _wndScale); 
	void	Run(); 

private:
	void Render();	
	void Update(); 
};

