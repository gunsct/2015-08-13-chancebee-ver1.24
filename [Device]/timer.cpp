#include "timer.h"

Timer::Timer(){};

Timer::~Timer(){}

bool Timer::Timer_Set(float _sec)
{
	static DWORD frameCount = 0;            //������ ī��Ʈ��
	static float timeElapsed = 0.0f;            //�帥 �ð�
	static DWORD lastTime = timeGetTime();   //������ �ð�(temp����) ����ƽ���� ���������������

	DWORD curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.
	timeElapsed += timeDelta; //�帥�ð� ���� �Ƹ� �ʴ����� �����Ұ���

	if(timeElapsed >= _sec)//���ϴ� �ð� �Ǹ� Ʈ�� ��ȯ
	{
		timeElapsed =0.0f;
		lastTime = curTime;
		return true;
	}

	lastTime = curTime; //�������ð��� ó���ð����� �ʱ�ȭ����
	return false;
}