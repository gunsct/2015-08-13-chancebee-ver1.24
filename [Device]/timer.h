#pragma once
#include  "..\\..\\[Device]\Define.h"
#pragma comment(lib, "winmm.lib")
#include <stdlib.h>

class Timer{
public:
	Timer();
	~Timer();
	bool Timer_Set(float _sec);
};
