#include "Skill.h"

Skill::Skill(int sn, int dg, int tp)
{
	Skill_Num = sn;
	Damage = dg;
	TimePoint = tp;
	/*S_Xpos = _xpos;
	S_Ypos = _ypos;*/
}

Skill::~Skill()
{
	//�� ��ų���� ��ų �̹����� ���� ���⼭ ���ؽ����۸� ������ ����߰���?
}

int Skill::Return_Skill_Num()
{
	return Skill_Num;
}
int Skill::Return_Damage()
{
	return Damage;
}
int Skill::Return_TimePoint()
{
	return TimePoint;
}