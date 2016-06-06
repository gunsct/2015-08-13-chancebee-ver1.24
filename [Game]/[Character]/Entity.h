#pragma once
#include "..\..\[Device]\Define.h"

class Entity //기본적인 구성 요소를 가지고 있는 클래스
{
private:
	float	Rotation;				//회전
	int		m_SizeX,m_SizeY;

public:
	float	x_pos, y_pos;//캐릭좌표
	float	HP, TP;//피,시간 포인트
	bool Attack_Stat;

	Entity(void);
	~Entity(void);
	Entity(int p_Size_X,int p_Size_Y, float _rot);

	void Change_HP(int dg);//피다는거
	void Change_TP(int tp);//티피다는거
	void Repair_TP(float Plus);//티피 차는거

	void Init(float _xpot, float _ypos);

	int Get_Size_X();
	int Get_Size_Y();
	
	
};

//////캐릭터 클래스 구성///////

