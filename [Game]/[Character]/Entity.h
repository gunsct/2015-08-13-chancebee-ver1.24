#pragma once
#include "..\..\[Device]\Define.h"

class Entity //�⺻���� ���� ��Ҹ� ������ �ִ� Ŭ����
{
private:
	float	Rotation;				//ȸ��
	int		m_SizeX,m_SizeY;

public:
	float	x_pos, y_pos;//ĳ����ǥ
	float	HP, TP;//��,�ð� ����Ʈ
	bool Attack_Stat;

	Entity(void);
	~Entity(void);
	Entity(int p_Size_X,int p_Size_Y, float _rot);

	void Change_HP(int dg);//�Ǵٴ°�
	void Change_TP(int tp);//Ƽ�Ǵٴ°�
	void Repair_TP(float Plus);//Ƽ�� ���°�

	void Init(float _xpot, float _ypos);

	int Get_Size_X();
	int Get_Size_Y();
	
	
};

//////ĳ���� Ŭ���� ����///////

