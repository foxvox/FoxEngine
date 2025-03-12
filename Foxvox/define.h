#pragma once 

// ����! ��ũ�� ���ǿ��� �� �ٲ��� �� ���� �齽����(\) �ڿ� ������ ����� �մϴ�. 

#define SINGLETON(type) public: \
							static type* GetInst() \
							{ \
								static type inst; \
								return &inst; \
							} \
						private: \
							type(); \
							~type();

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; } 