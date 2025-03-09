#pragma once

class TimeMgr
{
	SINGLETON(TimeMgr); 

private:
	LARGE_INTEGER curCnt; 
	LARGE_INTEGER frequency; 
public: 
	void Init(); 
	//QueryPerformanceCounter();
};

