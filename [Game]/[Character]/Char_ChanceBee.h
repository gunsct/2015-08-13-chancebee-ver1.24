#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "..\..\[Device]\Camera.h"
#include "..\Collider.h"
#include "..\[UI]\UI_Text.h"
 
class Collider;

static float moving_cnt;//불러오는게 안되서 전역변수로 바꿈

class Char_ChanceBee : public Entity
{
private:
	float Char_Size_X;
	float Char_Size_Y;
	Collider *c_Collider;
	FileLoader *c_FileLoader;

	UI_Text *c_UI_Text;

	int Move_Dir_Chk;
public:
	Sprite *c_Sprite;

	Char_ChanceBee(void);
	~Char_ChanceBee(void);

	//찬스비 캐릭터를 인자가 있는 생성자로 받는다.
	Char_ChanceBee(float _Char_Size_X, float _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y, int _Sprite_Size_X, int _Sprite_Size_Y);

	//위치 초기화.
	void Init_Pos();

	//움직일때.
	void Movement();

	void Interaction();


	//캐릭터 사이즈를 재정의 해야할때 사용한다.
	void Input_Char_Size(float _Char_Size_X, float _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y,int _cntX, int _cntY);

	//스프라이트 uv좌표 호출
	float get_Char_Sprite_X();
	float get_Char_Sprite_Y();

	float get_Char_Size_X();
	float get_Char_Size_Y();

	void Init_Get_Device(LPDIRECT3DDEVICE9 *pd3dDevice);
	void get_text();
};
