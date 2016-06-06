#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "B_Enemy.h"

class B_Char_ChanceBee : public Entity
{
private :
	int Char_Size_X;
	int Char_Size_Y;

	bool b_Play;
public:

	Sprite *c_Sprite;

	B_Char_ChanceBee(void);
	~B_Char_ChanceBee(void);

	B_Char_ChanceBee(int _Char_Size_X, int _Char_Size_Y, int _Char_Img_Size_X, 
					   int _Char_Img_Size_Y, int _Sprite_Size_X, int _Sprite_Size_Y);

	//위치 초기화.
	void Init_Pos();


	//움직일때.
	void Movement();
	void Attack(B_Enemy *m_B_Enemy);

	void b_Play_(bool a);
	bool b_Play_();
	//캐릭터 사이즈를 재정의 해야할때 사용한다.
	void Input_Char_Size(int _Char_Size_X, int _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y,int _cntX, int _cntY);

	//스프라이트 uv좌표 호출
	float get_Char_Sprite_X();
	float get_Char_Sprite_Y();

	float get_Char_Size_X();
	float get_Char_Size_Y();
};

