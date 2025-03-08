#pragma once 

class Core
{
public:
	SINGLETON(Core);
private:
	Core();
	~Core();
public:
	int Init();
	void Run();
};

