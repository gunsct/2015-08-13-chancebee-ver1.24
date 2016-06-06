#include "B_Enemy.h"

B_Enemy::B_Enemy()
{
	e_Sprite = new Sprite();
	
	Enemy_Size_X = 1;
	Enemy_Size_Y = 1;

	x_pos = 3;
	y_pos = 0;

	HP = 100;
	TP = 100;

	b_Play = false;
}

B_Enemy::~B_Enemy()
{
}
B_Enemy::B_Enemy(float _xpos, float _ypos, int _Enemy_Size_X, int _Enemy_Size_Y, int _Enemy_Img_Size_X,
		int _Enemy_Img_Size_Y, int _Sprite_Size_X, int _Sprite_Size_Y)
{
	e_Sprite = new Sprite();
	
	Enemy_Size_X = _Enemy_Size_X;
	Enemy_Size_Y = _Enemy_Size_Y;

	x_pos = _xpos;
	y_pos = _ypos;

	HP = 100;
	TP = 100;

	b_Play = false;
}
void B_Enemy::Init_Pos()
{
	x_pos = 0;
	y_pos = 0;

	HP = 100;
	TP = 100;
};

void B_Enemy::Movement()
{
	static bool ref = true;

	if(b_Play_() == false)
	{
		if(KEY_DOWN(VK_SPACE))
		{
			b_Play = true;
		}
	}

	else if(b_Play_() == true)
	{
		switch(ref)  
		{
		case true:
			x_pos -= 0.3;
			e_Sprite->m_NextFrame(true, 0.5);
			if(x_pos <= 0)
				{
 				ref=false;
			}
			break;

		case false:
			x_pos += 0.3;
			e_Sprite->m_NextFrame(true, 0.5);
			if(x_pos >= 4)
			{
				ref=true;
				b_Play = false;
			}
			break;
		}
	}
};

bool B_Enemy :: b_Play_()
{
	return b_Play;
}

void B_Enemy::Input_Enemy_Size(int _Enemy_Size_X, int _Enemy_Size_Y, int _Enemy_Img_Size_X, int _Enemy_Img_Size_Y, int _cntX, int _cntY)
{
	Enemy_Size_X = _Enemy_Size_X;
	Enemy_Size_Y = _Enemy_Size_Y;

	e_Sprite->m_SetImage(_Enemy_Img_Size_X, _Enemy_Img_Size_Y, _cntX, _cntY);
}


float B_Enemy :: get_Enemy_Sprite_X()
{

	return e_Sprite->get_Now_Sprite_Pos_X();
}

float B_Enemy :: get_Enemy_Sprite_Y()
{
	return e_Sprite->get_Now_Sprite_Pos_Y();
}

float B_Enemy :: get_Enemy_Size_X()
{
	return Enemy_Size_X;
}

float B_Enemy :: get_Enemy_Size_Y()
{
	return Enemy_Size_Y;
}