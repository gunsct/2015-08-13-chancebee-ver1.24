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

	//위치 초기화.
	void Init_Pos();


	//움직일때.
	void Movement();

	bool b_Play_();

	//캐릭터 사이즈를 재정의 해야할때 사용한다.
	void Input_Enemy_Size(int _Enemy_Size_X, int _Enemy_Size_Y, int _Enemy_Img_Size_X, int _Enemy_Img_Size_Y, int _cntX, int _cntY);

	//스프라이트 uv좌표 호출
	float get_Enemy_Sprite_X();
	float get_Enemy_Sprite_Y();

	float get_Enemy_Size_X();
	float get_Enemy_Size_Y();
};

	

