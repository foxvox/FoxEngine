#pragma once 

#define SINGLETON(classname) static classname* GetInstance() \
							{ \
								static classname instance; \
								return &instance; \
							}


