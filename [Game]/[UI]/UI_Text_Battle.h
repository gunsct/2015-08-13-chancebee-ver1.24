#pragma once
#include <iostream>
#include <string>
#include "..\..\[Device]\Define.h"
#include <time.h>

using namespace std;

class UI_Text_Battle
{
private:
	//�̱���
	UI_Text_Battle(void)
	{
		m_Font_Color = D3DCOLOR_XRGB(255, 255, 255);
		m_Text_Out_Sec = 0;
	};
	static bool InstanceFlag;
	static UI_Text_Battle *Instance;

	//��Ʈ�� ��������Ʈ ����
	ID3DXFont *m_Font;
	ID3DXSprite *Sprite;

	//��Ʈ�� ���õ� ��.
	int m_Font_Size;
	D3DCOLOR m_Font_Color;


	//�簢���� �簢�� ũ�� ����
	RECT m_Text_Rect;
	int m_Xpos, m_Ypos, m_Width, m_Height;

	//��簡 ������ �ð�
	float m_Text_Out_Sec;

	//�ؽ�Ʈ ����
	int m_Strlen;

	//��縦 ���� ����
	string m_S_Line;



public:
	~UI_Text_Battle(void);
	static UI_Text_Battle *getInstance();
	void Singleson_Realese();

	void Init_Member(int size, int p_iPosX, int p_iPosY, int p_iWidth, int p_iHeight, char* p_sText, LPDIRECT3DDEVICE9 *g_pd3dDevice);


	// �ؽ�Ʈ �� ����
	void SetColor(short R, short G, short B);

	//�ؽ�Ʈ�� �׷��ش�.
	//���⿡���� �ؽ�Ʈ�� �ð����� �ϳ��� �׷��ش�.
	void Draw_Text(float m_fSpeed);


	//�ؽ�Ʈ�� �ٲ۴�.
	void Change_Text(int p_iPosX, int p_iPosY, char *p_sText);

	void Final_UI_Text_Battle();
};

