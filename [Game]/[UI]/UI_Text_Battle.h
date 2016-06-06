#pragma once
#include <iostream>
#include <string>
#include "..\..\[Device]\Define.h"
#include <time.h>

using namespace std;

class UI_Text_Battle
{
private:
	//싱글톤
	UI_Text_Battle(void)
	{
		m_Font_Color = D3DCOLOR_XRGB(255, 255, 255);
		m_Text_Out_Sec = 0;
	};
	static bool InstanceFlag;
	static UI_Text_Battle *Instance;

	//폰트와 스프라이트 변수
	ID3DXFont *m_Font;
	ID3DXSprite *Sprite;

	//폰트에 관련된 것.
	int m_Font_Size;
	D3DCOLOR m_Font_Color;


	//사각형과 사각형 크기 조절
	RECT m_Text_Rect;
	int m_Xpos, m_Ypos, m_Width, m_Height;

	//대사가 나오는 시간
	float m_Text_Out_Sec;

	//텍스트 길이
	int m_Strlen;

	//대사를 넣을 변수
	string m_S_Line;



public:
	~UI_Text_Battle(void);
	static UI_Text_Battle *getInstance();
	void Singleson_Realese();

	void Init_Member(int size, int p_iPosX, int p_iPosY, int p_iWidth, int p_iHeight, char* p_sText, LPDIRECT3DDEVICE9 *g_pd3dDevice);


	// 텍스트 색 설정
	void SetColor(short R, short G, short B);

	//텍스트를 그려준다.
	//여기에서는 텍스트를 시간마다 하나씩 그려준다.
	void Draw_Text(float m_fSpeed);


	//텍스트를 바꾼다.
	void Change_Text(int p_iPosX, int p_iPosY, char *p_sText);

	void Final_UI_Text_Battle();
};

