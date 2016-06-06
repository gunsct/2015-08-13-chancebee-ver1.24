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

	//FPS를 화면 내에 출력을 하려고 했었으나....
	//그게 어려워서 일단은 콘솔창에 띄워놓고 프레임을 출력하고 있다.
	void Create_Font(LPDIRECT3DDEVICE9 *g_pd3dDevice);
	void Draw_FPS();
	void Update_FPS();
};

