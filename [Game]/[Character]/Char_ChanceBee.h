#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "..\..\[Device]\Camera.h"
#include "..\Collider.h"
#include "..\[UI]\UI_Text.h"
 
class Collider;

static float moving_cnt;//�ҷ����°� �ȵǼ� ���������� �ٲ�

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

	//������ ĳ���͸� ���ڰ� �ִ� �����ڷ� �޴´�.
	Char_ChanceBee(float _Char_Size_X, float _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y, int _Sprite_Size_X, int _Sprite_Size_Y);

	//��ġ �ʱ�ȭ.
	void Init_Pos();

	//�����϶�.
	void Movement();

	void Interaction();


	//ĳ���� ����� ������ �ؾ��Ҷ� ����Ѵ�.
	void Input_Char_Size(float _Char_Size_X, float _Char_Size_Y, int _Char_Img_Size_X, int _Char_Img_Size_Y,int _cntX, int _cntY);

	//��������Ʈ uv��ǥ ȣ��
	float get_Char_Sprite_X();
	float get_Char_Sprite_Y();

	float get_Char_Size_X();
	float get_Char_Size_Y();

	void Init_Get_Device(LPDIRECT3DDEVICE9 *pd3dDevice);
	void get_text();
};
