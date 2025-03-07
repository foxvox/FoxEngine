#pragma once
class Core
{
private:
	static Core* instance; 
private:
	Core();
	~Core();
public:
	static Core* GetInstance()
	{
		if (instance == nullptr)
			instance = new Core();

		return instance;
	}

	static void DestroyInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
	void Run();
};

