#include "Entity.h"
#include <windows.h>//타이머쓸려고

Entity::Entity(void)
{
}


Entity::~Entity(void)
{
}

Entity::Entity(int p_Size_X,int p_Size_Y, float _rot)
{
	m_SizeX = p_Size_X;
	m_SizeY = p_Size_Y;

	Rotation = _rot;
}
	

void Entity::Change_HP(int dg)
{
	HP -= dg;
}

void Entity::Change_TP(int tp)
{
	TP -= tp;
}

void Entity::Repair_TP(float Plus)
{
	if(TP < 100)
		TP += Plus;
}

void Entity::Init(float _xpos, float _ypos)
{
	//hp는 임시
	HP = 100;

	TP = 0;
	x_pos = _xpos;
	y_pos = _ypos;
	Attack_Stat = false;
}

int Entity::Get_Size_X()
{
	return m_SizeX;
}

int Entity::Get_Size_Y()
{
	return m_SizeY;
}

//void CALLBACK Entity::Repair_TP(HWND hWnd, UINT nID, UINT nEl, DWORD time)
//{
//	if (TP<=95)
//	TP += 5;
//}