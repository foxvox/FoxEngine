#pragma once

class Object
{
private:
	Vector2 pos; 
	Vector2 size; 

public:
	Object();
	~Object(); 

	// pos 프로퍼티의 getter와 setter
	Vector2 GetPos() const { return pos; }
	void SetPos(const Vector2& _pos) { pos = _pos; }

	// size 프로퍼티의 getter와 setter
	Vector2 GetSize() const { return size; }
	void SetSize(const Vector2& _size) { size = _size; }
};

