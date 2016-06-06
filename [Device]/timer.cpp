#include "timer.h"

Timer::Timer(){};

Timer::~Timer(){}

bool Timer::Timer_Set(float _sec)
{
	static DWORD frameCount = 0;            //프레임 카운트수
	static float timeElapsed = 0.0f;            //흐른 시간
	static DWORD lastTime = timeGetTime();   //마지막 시간(temp변수) 스태틱으로 전역변수취급해줌

	DWORD curTime = timeGetTime();      //현재 시간
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.
	timeElapsed += timeDelta; //흐른시간 누적 아마 초단위로 누적할거임

	if(timeElapsed >= _sec)//원하는 시간 되면 트루 반환
	{
		timeElapsed =0.0f;
		lastTime = curTime;
		return true;
	}

	lastTime = curTime; //마지막시간을 처음시간으로 초기화해줌
	return false;
}