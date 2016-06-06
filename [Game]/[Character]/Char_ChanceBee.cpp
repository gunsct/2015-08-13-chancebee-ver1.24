#include "Char_ChanceBee.h"


////////////////////////////
Char_ChanceBee::Char_ChanceBee(void)
{
	c_Sprite = new Sprite();
	c_Collider = new Collider();
	c_UI_Text->getInstance();

	Char_Size_X = 1;
	Char_Size_Y = 1;

	c_FileLoader = FileLoader::getInstance();
	c_FileLoader->It_CHRECTER =  c_FileLoader->L_CHRECTER->begin();

	x_pos = (*c_FileLoader->It_CHRECTER)->Return_Img_Xpos();
	y_pos = (*c_FileLoader->It_CHRECTER)->Return_Img_Ypos();

	HP = 100;
	TP = 100;
};

Char_ChanceBee::~Char_ChanceBee(void)
{
	//SAFE_DELETE(c_Sprite);
};

Char_ChanceBee::Char_ChanceBee(float _Char_Size_X, float _Char_Size_Y, int _Char_Img_Size_X, 
							   int _Char_Img_Size_Y, int _Sprite_Size_X, int _Sprite_Size_Y)
{
	c_Sprite = new Sprite(_Char_Img_Size_X, _Char_Img_Size_Y, _Sprite_Size_X, _Sprite_Size_Y);
	c_Collider = new Collider();
	c_UI_Text = UI_Text ::getInstance();

	Char_Size_X = _Char_Size_X;
	Char_Size_Y = _Char_Size_Y;

	c_FileLoader = FileLoader::getInstance();
	c_FileLoader->It_CHRECTER =  c_FileLoader->L_CHRECTER->begin();
	x_pos = (*c_FileLoader->It_CHRECTER)->Return_Img_Xpos();
	y_pos = (*c_FileLoader->It_CHRECTER)->Return_Img_Ypos();

	HP = 100;
	TP = 100;

	moving_cnt = 0;
};

void Char_ChanceBee :: Init_Get_Device(LPDIRECT3DDEVICE9 *pd3dDevice)
{
	c_UI_Text->Init_Member(20, 10, 300, 300, 50, " ", pd3dDevice);
}

void Char_ChanceBee::Init_Pos()
{
	x_pos = 0;
	y_pos = 0;
};

void Char_ChanceBee::Movement()
{
	static bool Move_Chk[4] = {false};

	if(KEY_DOWN(VK_UP))
	{
		y_pos += 0.1;
		moving_cnt += 0.1;
		//충돌하면
		if((c_Collider->Section_Check_And_Collider(x_pos, y_pos, x_pos-Char_Size_X, x_pos+Char_Size_X, y_pos+Char_Size_Y, y_pos-Char_Size_Y)) == false)
		{
			y_pos -= 0.1;
		}


		if(Move_Chk[0] == false)
		{
			c_Sprite->m_Set_Another_Frame(4, 8);
			Move_Chk[0] = true;
			Move_Chk[1] = Move_Chk[2] = Move_Chk[3] = false;
		}

		c_Sprite->m_NextFrame(true, 0.25);

	}

	else if(KEY_DOWN(VK_DOWN))
	{	
		y_pos -= 0.1;
		moving_cnt += 0.1;
		if((c_Collider->Section_Check_And_Collider(x_pos, y_pos, x_pos-Char_Size_X, x_pos+Char_Size_X, y_pos+Char_Size_Y, y_pos-Char_Size_Y)) == false)
		{
			y_pos += 0.1;
		}

		if(Move_Chk[1] == false)
		{
			c_Sprite->m_Set_Another_Frame(0, 4);
			Move_Chk[1] = true;
			Move_Chk[0] = Move_Chk[2] = Move_Chk[3] = false;
		}

		c_Sprite->m_NextFrame(true, 0.25);
	}

	else if(KEY_DOWN(VK_LEFT))
	{
		x_pos -= 0.1;
		moving_cnt += 0.1;
		if((c_Collider->Section_Check_And_Collider(x_pos, y_pos, x_pos-Char_Size_X, x_pos+Char_Size_X, y_pos+Char_Size_Y, y_pos-Char_Size_Y)) == false)
		{
			x_pos += 0.1;
		}

		if(Move_Chk[2] == false)
		{
			c_Sprite->m_Set_Another_Frame(12, 16);
			Move_Chk[2] = true;
			Move_Chk[0] = Move_Chk[1] = Move_Chk[3] = false;
		}

		c_Sprite->m_NextFrame(true, 0.25);	
	}

	else if(KEY_DOWN(VK_RIGHT))
	{
		x_pos += 0.1;
		moving_cnt += 0.1;
		if((c_Collider->Section_Check_And_Collider(x_pos, y_pos, x_pos-Char_Size_X, x_pos+Char_Size_X, y_pos+Char_Size_Y, y_pos-Char_Size_Y)) == false)
		{
			x_pos -= 0.1;
		}

		if(Move_Chk[3] == false)
		{
			c_Sprite->m_Set_Another_Frame(8, 12);
			Move_Chk[3] = true;
			Move_Chk[0] = Move_Chk[1] = Move_Chk[2] = false;
		}

		c_Sprite->m_NextFrame(true, 0.25);
	}

};


void Char_ChanceBee::Interaction()
{
	double temp_kyori;

	for(c_FileLoader->It_MAP_OBJ = c_FileLoader->L_MAP_OBJ->begin(); c_FileLoader->It_MAP_OBJ != c_FileLoader->L_MAP_OBJ->end(); c_FileLoader->It_MAP_OBJ++)
	{
		temp_kyori = sqrt(pow((x_pos - (*c_FileLoader->It_MAP_OBJ)->Return_Img_Xpos()), 2) + pow((y_pos - (*c_FileLoader->It_MAP_OBJ)->Return_Img_Ypos()), 2)); 
		if(temp_kyori < 3.2f)
		{
			if(KEY_DOWN(VK_SPACE))
			{
				c_UI_Text->Change_Text(20, 500, "보물상자를 열어보았다");
			}
		}
	}
}


void Char_ChanceBee::Input_Char_Size(float _Char_Size_X, float _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y, int _cntX, int _cntY)
{
	Char_Size_X = _Char_Size_X;
	Char_Size_Y = _Char_Size_Y;

	c_Sprite->m_SetImage(_Char_Img_Size_X, _Char_Img_Size_Y, _cntX, _cntY);
}


float Char_ChanceBee :: get_Char_Sprite_X()
{

	return c_Sprite->get_Now_Sprite_Pos_X();
}

float Char_ChanceBee :: get_Char_Sprite_Y()
{
	return c_Sprite->get_Now_Sprite_Pos_Y();
}

float Char_ChanceBee :: get_Char_Size_X()
{
	return Char_Size_X;
}

float Char_ChanceBee :: get_Char_Size_Y()
{
	return Char_Size_Y;
}

void Char_ChanceBee :: get_text()
{
	c_UI_Text->Final_UI_Text();
}