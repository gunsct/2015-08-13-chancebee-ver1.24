#include "Input_Manager.h"



Input_Manager::Input_Manager(void)
{
}


Input_Manager::~Input_Manager(void)
{
}


void Input_Manager :: Menu_Control(float &x_pos, float &y_pos)
{

}


void Input_Manager::Character_Control(Char_ChanceBee &m_Char_ChanceBee)
{
	//ĳ���� ������, ��ƼƼ�³��߿�.. ĳ���ͺ��� ���� �޾Ƽ� ���� 
	if (KEY_DOWN(VK_UP)) //if(� ĳ���Ͱ� true�϶�)
		m_Char_ChanceBee.Movement(MOVE_UP);

	if (KEY_DOWN(VK_DOWN))
		m_Char_ChanceBee.Movement(MOVE_DOWN);

	if (KEY_DOWN(VK_LEFT))
		m_Char_ChanceBee.Movement(MOVE_LEFT);

	if (KEY_DOWN(VK_RIGHT))
		m_Char_ChanceBee.Movement(MOVE_RIGHT);

	//Camera().Move_XY_Position();
}

int Input_Manager::Key_Board_Input(int Input, e_Key_Input Key_Input)
{
	if(KEY_DOWN_ONE_CLICK(VK_SPACE))
		return SPACE;

	if(KEY_DOWN_ONE_CLICK(VK_ESCAPE))
		return ESC;

	if(KEY_DOWN_ONE_CLICK('1'))
		return NUM1;

	if(KEY_DOWN_ONE_CLICK('1'))
		return NUM2;

	if(KEY_DOWN_ONE_CLICK('1'))
		return NUM3;

	if(KEY_DOWN_ONE_CLICK('1'))
		return NUM4;

}

