#pragma once 

// 장점: 헤더끼리 상호참조를 막기 위해서 전방선언을 사용, 컴파일시 부하를 줄인다.   
// 단점: 구체적인 정보는 갖지 못함 
class Object; 

class Scene
{
protected:  	 
	vector<Object*> objGroups[(UINT)GroupType::MAX]; 	
	wstring name; 

public: 
	void AddObject(Object* _obj, GroupType _group) { objGroups[(UINT)_group].push_back(_obj); }

public: 
	wstring GetName() const { return name; }
	void SetName(const wstring& _name) { name = _name; } 

	void Update();
	void Render(HDC _dc);

	virtual void Enter() = 0; 
	virtual void Exit() = 0; 

	Scene(); 
	virtual ~Scene(); 
};

