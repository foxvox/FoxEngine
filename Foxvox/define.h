#pragma once 

// 주의! 매크로 정의에서 줄 바꿈을 할 때는 백슬래시(\) 뒤에 공백이 없어야 합니다. 

#define SINGLETON(type) public: \
							static type* GetInstance() \
							{ \
								static type instance; \
								return &instance; \
							} \
						private: \
							type(); \
							~type();

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; } 