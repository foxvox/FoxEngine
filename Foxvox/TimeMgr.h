#pragma once

class TimeMgr
{
	SINGLETON(TimeMgr); 

private:
	LARGE_INTEGER	curCnt; 
	LARGE_INTEGER	prevCnt;
	LARGE_INTEGER	freq; 
		
	int				callCnt;	// 함수 호출 횟수 
	int				fps;		// 초당 프레임 수  
	float			dt;			// delta time  
	float			acct;		// 누적 시간
	bool			isFirst;	

public: 
	void		 Init();
	void		 Update();

	int			 GetFPS() const { return fps; } 	
	float		 GetDT() const { return dt; } 

private:
	void		 CheckFPS(); 
};

