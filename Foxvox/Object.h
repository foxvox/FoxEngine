#pragma once

class Object 
{
protected:
	Vector2		 pos; 
	Vector2		 scale; 

public:	
	Vector2		 GetPos() const { return pos; }
	void		 SetPos(const Vector2& _pos) { pos = _pos; } 
	Vector2		 GetScale() const { return scale; }
	void		 SetScale(const Vector2& _scale) { scale = _scale; }

	virtual void Update() = 0; 
	virtual void Render(HDC _dc); 

				 Object();
	virtual		~Object();
};

