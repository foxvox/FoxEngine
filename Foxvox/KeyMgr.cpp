#include "pch.h" 
#include "KeyMgr.h" 
#include "Core.h" 

// ���� ���� ������Ŭ���� Key�� ���� ���� ����Ű ���� ��ġ��Ű�� �迭 
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
	// ������ ��Ŀ�� �˾Ƴ��� 	
	HWND fwnd = GetFocus(); 

	// ��Ŀ�� ������ �����찡 �ϳ��� ������ 
	if (fwnd != nullptr) 
	{
		for (int i = 0; i < (int)Key::KEYMAX; i++)
		{
			KeyState s = keybox[i].state; 
			bool pp = keybox[i].prevPressed; 

			// GetAsyncKeyState() �Լ��� Ű������ ���¸� ��ȯ�ϴ� �Լ��̴�. ���ڷ� WinUser.h�� ���ǵ� ����Ű ���� ���� �Ѵ�.  
			// 0X8000 �� SHORT �ֻ��� ��Ʈ�� 1�̸� ���� �����̴�.

			// ���� �����ӿ��� Ű�� ���� ���  
			if (GetAsyncKeyState(arrVK[i]) & 0x8000)
			{
				// ���� �����ӿ��� Ű�� ������ ���� �����ӿ����� ���� ���  
				if (pp)
				{
					s = KeyState::HOLD;
				}
				// ���� �����ӿ��� Ű�� �� ������ ���� �����ӿ��� ���� ��� 
				else
				{
					s = KeyState::TAP;
				}

				pp = true;
			}
			// ���� �����ӿ��� Ű�� �� ���� ��� 
			else
			{
				// ���� �����ӿ��� Ű�� ���ȴٰ� ���� �����ӿ��� �� ���� ���  
				if (pp)
				{
					s = KeyState::OFF;
				}
				// ���� �����ӿ��� Ű�� �� ���ȴٰ� ���� �����ӿ����� �� ���� ��� 
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
	// ��Ŀ�� ���°� �ƴϸ� 
	else
	{
		// ��Ŀ�� ���°� �ƴϸ� ��� Ű�� �ܰ������� NONE���·� �ٲ㼭 Ű�Է��� �� �ް� �����. 
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
