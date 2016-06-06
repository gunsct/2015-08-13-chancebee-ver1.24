#pragma once
#include "..\..\[Device]\Define.h"
#include "..\Camera.h"
#include "..\..\[Game]\[Character]\Char_ChanceBee.h"

class Input_Manager
{
private:
		
	/*friend class Entity;
		Entity m_Entity;*/
public:
	Input_Manager(void);
	~Input_Manager(void);

	

	//int Key_Board_Input(int Input, e_Situation Situation);
	void Menu_Control(float &x_pos, float &y_pos);
//	void Character_Control(Char_ChanceBee &m_Char_ChanceBee);
	int Key_Board_Input(int Input, e_Key_Input Key_Input);
};

