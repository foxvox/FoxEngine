#include "pch.h" 
#include "KeyMgr.h" 
#include "Core.h" 

// 내가 만든 열거형클래스 Key의 값과 실제 가상키 값을 매치시키는 배열 
int arrVK[(int)Key::KEYMAX] =
{
	VK_LEFT,	//LEFT, 
	VK_RIGHT,	//RIGHT, 
	VK_UP,		//UP, 
	VK_DOWN,	//DOWN,

	'Q', 
	'W', 
	'E', 
	'R', 
	'T', 
	'Y', 
	'U', 
	'I', 
	'O', 
	'P',
	'A', 
	'S', 
	'D', 
	'F', 
	'G', 
	'H', 
	'J', 
	'K', 
	'L',
	'Z', 
	'X', 
	'C', 
	'V', 
	'B', 
	'N', 
	'M',

	VK_CONTROL,		//CTRL, 
	VK_MENU,		//ALT, 
	VK_LSHIFT,		//LSHIFT, 
	VK_SPACE,		//SPACE, 
	VK_RETURN,		//ENTER, 
	VK_ESCAPE,		//ESC,	
}; 

KeyMgr::KeyMgr()
{}

KeyMgr::~KeyMgr()
{}

void KeyMgr::Init()
{
	for (int i = 0; i < (int)Key::KEYMAX; i++)
	{
		keybox.push_back(KeyInfo{ false, KeyState::NONE });
	}
}

void KeyMgr::Update()
{
	// 윈도우 포커싱 알아내기 	
	HWND fwnd = GetFocus(); 

	// 포커싱 상태의 윈도우가 하나라도 있으면 
	if (fwnd != nullptr) 
	{
		for (int i = 0; i < (int)Key::KEYMAX; i++)
		{
			KeyState s = keybox[i].state; 
			bool pp = keybox[i].prevPressed; 

			// GetAsyncKeyState() 함수는 키보드의 상태를 반환하는 함수이다. 인자로 WinUser.h에 정의된 가상키 값이 들어가야 한다.  
			// 0X8000 즉 SHORT 최상위 비트가 1이면 눌린 상태이다.

			// 현재 프레임에서 키가 눌린 경우  
			if (GetAsyncKeyState(arrVK[i]) & 0x8000)
			{
				// 이전 프레임에서 키가 눌리고 현재 프레임에서도 눌린 경우  
				if (pp)
				{
					s = KeyState::HOLD;
				}
				// 이전 프레임에서 키가 안 눌리고 현재 프레임에서 눌린 경우 
				else
				{
					s = KeyState::TAP;
				}

				pp = true;
			}
			// 현재 프레임에서 키가 안 눌린 경우 
			else
			{
				// 이전 프레임에서 키가 눌렸다가 현재 프레임에서 안 눌린 경우  
				if (pp)
				{
					s = KeyState::OFF;
				}
				// 이전 프레임에서 키가 안 눌렸다가 현재 프레임에서도 안 눌린 경우 
				else
				{
					s = KeyState::NONE;
				}

				pp = false;
			}

			keybox[i].prevPressed = pp;
			keybox[i].state = s; 			 
		} // for (int i = 0; i < (int)Key::KEYMAX; i++) 
	} // if (wnd != NULL)  
	// 포커싱 상태가 아니면 
	else
	{
		// 포커싱 상태가 아니면 모든 키를 단계적으로 NONE상태로 바꿔서 키입력을 안 받게 만든다. 
		for (int i = 0; i < (int)Key::KEYMAX; i++)
		{
			keybox[i].prevPressed = false;

			KeyState s = keybox[i].state;			
						
			if (KeyState::HOLD == s || KeyState::TAP == s) 
			{ 
				s = KeyState::OFF; 
			}
			else 
			{ 
				s = KeyState::NONE; 
			} 

			keybox[i].state = s; 
		}
	}
}
