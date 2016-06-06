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

	//��ġ �ʱ�ȭ.
	void Init_Pos();


	//�����϶�.
	void Movement();
	void Attack(B_Enemy *m_B_Enemy);

	void b_Play_(bool a);
	bool b_Play_();
	//ĳ���� ����� ������ �ؾ��Ҷ� ����Ѵ�.
	void Input_Char_Size(int _Char_Size_X, int _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y,int _cntX, int _cntY);

	//��������Ʈ uv��ǥ ȣ��
	float get_Char_Sprite_X();
	float get_Char_Sprite_Y();

	float get_Char_Size_X();
	float get_Char_Size_Y();
};

