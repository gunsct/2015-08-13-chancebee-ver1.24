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
		TEXT("����ü"), &Font);

	D3DXCreateSprite(*g_pd3dDevice, &Sprite);
}

void FPS:: Update_FPS()
{
	static DWORD frameCount = 0;            //������ ī��Ʈ��
	static float timeElapsed = 0.0f;            //�帥 �ð�
	static DWORD lastTime = timeGetTime();   //������ �ð�(temp����)

	DWORD curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.

	timeElapsed += timeDelta; 
	frameCount++;

	if( timeElapsed >= 1.0f )         //�帥�ð��� 1���̻��̸� ���� �ϰ������ ó��
	{
		fps = (float)frameCount/timeElapsed;
		frameCount = 0;
		timeElapsed = 0.0f;
	}
	else
	{
		//�帥 �ð��� 1�ʰ� �ȵǸ� ������  
		//Sleep() �ص��ǰ� ���ص� �Ǳ�~ 
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