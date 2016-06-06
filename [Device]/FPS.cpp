#include "FPS.h"


FPS::FPS(void)
{
	fps = 0;
	Sprite = NULL;
}

FPS::~FPS(void)
{
}

void FPS::Create_Font(LPDIRECT3DDEVICE9 *g_pd3dDevice)
{
	D3DXCreateFont(*g_pd3dDevice, 25, 0, FW_BOLD, 1, false, 
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
		TEXT("굴림체"), &Font);

	D3DXCreateSprite(*g_pd3dDevice, &Sprite);
}

void FPS:: Update_FPS()
{
	static DWORD frameCount = 0;            //프레임 카운트수
	static float timeElapsed = 0.0f;            //흐른 시간
	static DWORD lastTime = timeGetTime();   //마지막 시간(temp변수)

	DWORD curTime = timeGetTime();      //현재 시간
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.

	timeElapsed += timeDelta; 
	frameCount++;

	if( timeElapsed >= 1.0f )         //흐른시간이 1초이상이면 내가 하고싶은것 처리
	{
		fps = (float)frameCount/timeElapsed;
		frameCount = 0;
		timeElapsed = 0.0f;
	}
	else
	{
		//흐른 시간이 1초가 안되면 생략함  
		//Sleep() 해도되고 안해도 되구~ 
	} 

	lastTime = curTime;
}


void FPS::Draw_FPS()
{
	Update_FPS();

	char str_temp2[3];
	itoa((int)fps, str_temp2, 10);
	string str_temp = str_temp2;


	Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	RECT rt = {590,50,100,100};
	Font->DrawText(Sprite, str_temp.c_str(), -1, &rt, DT_NOCLIP,D3DCOLOR_XRGB(0,0,0));	
	Sprite->End();
}