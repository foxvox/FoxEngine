#pragma once 

// 1. 프레임 동기화 
// 동일 프레임 내에서 같은 키에 대해, 동일한 이벤트를 가져간다. 

// 2. 키 입력 이벤트 처리 
// tap, hold, off 

enum class KeyState 
{
	NONE, TAP, HOLD, OFF,  
};

enum class Key 
{
	LEFT, RIGHT, UP, DOWN, 
	Q, W, E, R, T, Y, U, I, O, P, 
	A, S, D, F, G, H, J, K, L, 
	Z, X, C, V, B, N, M, 
	CTRL, ALT, LSHIFT, SPACE, ENTER, ESC, 
	KEYMAX, 
}; 

struct KeyInfo
{
	bool		prevPressed;
	KeyState	state;	
}; 


class KeyMgr
{
	SINGLETON(KeyMgr);
private: 
	vector<KeyInfo> keybox; 
public:
	void Init(); 
	void Update(); 
	KeyState GetKeyState(Key key) { return keybox[(int)key].state; } 
};

