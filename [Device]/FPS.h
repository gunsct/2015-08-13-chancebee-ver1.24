#pragma once
#include "Define.h"
#include <iostream>
#include <string.h>
using namespace std;

class FPS
{
private:
	float fps;
	ID3DXFont *Font;
	ID3DXSprite *Sprite;


public:
	FPS(void);
	~FPS(void);

	//FPS�� ȭ�� ���� ����� �Ϸ��� �߾�����....
	//�װ� ������� �ϴ��� �ܼ�â�� ������� �������� ����ϰ� �ִ�.
	void Create_Font(LPDIRECT3DDEVICE9 *g_pd3dDevice);
	void Draw_FPS();
	void Update_FPS();
};

