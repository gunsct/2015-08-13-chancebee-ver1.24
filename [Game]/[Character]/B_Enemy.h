#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "..\..\[Device]\Camera.h"

class B_Enemy : public Entity
{
private:
	int Enemy_Size_X;
	int Enemy_Size_Y;

	bool b_Play;
public :
	Sprite *e_Sprite;

	B_Enemy(void);
	~B_Enemy(void);

	B_Enemy(float _xpos, float _ypos, int _Enemy_Size_X, int _Enemy_Size_Y, int _Enemy_Img_Size_X,
		int _Enemy_Img_Size_Y, int _Sprite_Size_X, int _Sprite_Size_Y);

	//��ġ �ʱ�ȭ.
	void Init_Pos();


	//�����϶�.
	void Movement();

	bool b_Play_();

	//ĳ���� ����� ������ �ؾ��Ҷ� ����Ѵ�.
	void Input_Enemy_Size(int _Enemy_Size_X, int _Enemy_Size_Y, int _Enemy_Img_Size_X, int _Enemy_Img_Size_Y, int _cntX, int _cntY);

	//��������Ʈ uv��ǥ ȣ��
	float get_Enemy_Sprite_X();
	float get_Enemy_Sprite_Y();

	float get_Enemy_Size_X();
	float get_Enemy_Size_Y();
};

	

