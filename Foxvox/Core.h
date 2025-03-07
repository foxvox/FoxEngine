#pragma once
class Core
{
private:
	Core();
	~Core();
public:
	static Core* GetInstance()
	{
		static Core instance;

		return &instance;
	}

	void Run();
};

