#pragma once

class TimeMgr
{
	SINGLETON(TimeMgr); 

private:
	LARGE_INTEGER	curCnt; 
	LARGE_INTEGER	prevCnt;
	LARGE_INTEGER	freq; 
		
	int				callCnt;	// �Լ� ȣ�� Ƚ�� 
	int				fps;		// �ʴ� ������ ��  
	float			dt;			// delta time  
	float			acct;		// ���� �ð�
	bool			isFirst;	

public: 
	void		 Init();
	void		 Update();

	int			 GetFPS() const { return fps; } 	
	float		 GetDT() const { return dt; } 

private:
	void		 CheckFPS(); 
};

