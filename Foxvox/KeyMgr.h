#pragma once 

// 1. ������ ����ȭ 
// ���� ������ ������ ���� Ű�� ����, ������ �̺�Ʈ�� ��������. 

// 2. Ű �Է� �̺�Ʈ ó�� 
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

