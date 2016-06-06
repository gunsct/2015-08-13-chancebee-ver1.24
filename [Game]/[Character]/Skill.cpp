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
	//뭐 스킬에서 스킬 이미지를 쓰면 여기서 버텍스버퍼를 릴리즈 해줘야겠지?
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