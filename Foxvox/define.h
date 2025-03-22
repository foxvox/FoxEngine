#pragma once 

// ����! ��ũ�� ���ǿ��� �� �ٲ��� �� ���� �齽����(\) �ڿ� ������ ����� �մϴ�. 

#define SINGLETON(type) public: \
							static type* GetInst() \
							{ \
								static type inst; \
								return &inst; \
							} \
						private: \
							type(); \
							~type();

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; } 

enum class GroupType
{
	DEFAULT, PLAYER, MONSTER, BULLET, MISSLE,
	MAX = 16,
};

enum class SceneType
{
	TOOL, START, STAGE01, STAGE02, MAX = 8,
};

#define CORE Core::GetInst()  

#define DT TimeMgr::GetInst()->GetDT() 

#define SM SceneMgr::GetInst()  
#define TM TimeMgr::GetInst() 
#define KM KeyMgr::GetInst() 

#define SCENE_TOOL scenes[(UINT)SceneType::TOOL] 
#define SCENE_START scenes[(UINT)SceneType::START] 

#define OBJ_DEFAULT objGroups[(UINT)GroupType::DEFAULT] 


