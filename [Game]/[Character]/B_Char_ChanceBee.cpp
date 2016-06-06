#include "B_Char_ChanceBee.h"


B_Char_ChanceBee::B_Char_ChanceBee(void)
{
	c_Sprite = new Sprite();

	Char_Size_X = 1;
	Char_Size_Y = 1;

	x_pos = -7;
	y_pos = 0;

	HP = 100;
	TP = 0;

	b_Play = false;
}


B_Char_ChanceBee::~B_Char_ChanceBee(void)
{
}

B_Char_ChanceBee::B_Char_ChanceBee(int _Char_Size_X, int _Char_Size_Y, int _Char_Img_Size_X, 
							   int _Char_Img_Size_Y, int _Sprite_Size_X, int _Sprite_Size_Y)
{
	c_Sprite = new Sprite(_Char_Img_Size_X, _Char_Img_Size_Y, _Sprite_Size_X, _Sprite_Size_Y);

	Char_Size_X = _Char_Size_X;
	Char_Size_Y = _Char_Size_Y;

	x_pos = -7;
	y_pos = 0;

	HP = 100;
	TP = 0;

	b_Play = false;
};


void B_Char_ChanceBee::Init_Pos()
{
	x_pos = -1;
	y_pos = -1;
};

void B_Char_ChanceBee::Movement()
{
	static bool ref = true;

	if(b_Play_() == false)
	{

	}

	else if(b_Play_() == true)
	{
		switch(ref)  
		{
		case true:
			x_pos += 0.3;
			c_Sprite->m_NextFrame(true, 0.5);
			if(x_pos >= 1)
				{
 				ref=false;
			}
			break;

		case false:
			x_pos -= 0.3;
			c_Sprite->m_NextFrame(true, 0.5);
			if(x_pos <= -7)
			{
				ref=true;
				b_Play = false;
			}
			break;
		}
	}
};

void B_Char_ChanceBee :: Attack(B_Enemy *m_B_Enemy)
{
	if(sqrt( pow( (x_pos - m_B_Enemy->x_pos), 2) + pow( (y_pos - m_B_Enemy->y_pos), 2) ) <= 3.0f)
	{
		//어택 애니메이션을 넣고
		//적 에너미의 hp의 값을 내려준다.
 		m_B_Enemy->HP -= 10;

	}
}

void B_Char_ChanceBee :: b_Play_(bool a)
{
	b_Play = a;
	//return b_Play;
}

bool B_Char_ChanceBee :: b_Play_()
{
	return b_Play;
}


void B_Char_ChanceBee::Input_Char_Size(int _Char_Size_X, int _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y, int _cntX, int _cntY)
{
	Char_Size_X = _Char_Size_X;
	Char_Size_Y = _Char_Size_Y;

	c_Sprite->m_SetImage(_Char_Img_Size_X, _Char_Img_Size_Y, _cntX, _cntY);
}


float B_Char_ChanceBee :: get_Char_Sprite_X()
{

	return c_Sprite->get_Now_Sprite_Pos_X();
}

float B_Char_ChanceBee :: get_Char_Sprite_Y()
{
	return c_Sprite->get_Now_Sprite_Pos_Y();
}







float B_Char_ChanceBee :: get_Char_Size_X()
{
	return Char_Size_X;
}

float B_Char_ChanceBee :: get_Char_Size_Y()
{
	return Char_Size_Y;
}

