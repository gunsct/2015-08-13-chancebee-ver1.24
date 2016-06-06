#include "UI_Text.h"


//UI_Text::UI_Text(void)
//{
//	m_Font_Color = D3DCOLOR_XRGB(255, 255, 255);
//	m_Text_Out_Sec = 0;
//}
bool UI_Text :: InstanceFlag = false;
UI_Text *UI_Text :: Instance = NULL;

UI_Text *UI_Text::getInstance()
{
	if(!Instance)
	{
		Instance = new UI_Text();
		InstanceFlag = true;
	}
	return Instance;
}

UI_Text::~UI_Text(void)
{
	InstanceFlag = false;
}



void UI_Text::Init_Member(int size, int p_iPosX, int p_iPosY, int p_iWidth, int p_iHeight, char* p_sText, LPDIRECT3DDEVICE9 *g_pd3dDevice)
{
	D3DXCreateSprite(*g_pd3dDevice, &Sprite);

	m_Xpos = p_iPosX; 
	m_Ypos = p_iPosY; 
	m_Width = p_iWidth; 
	m_Height = p_iHeight;

	//m_Strlen = strlen(p_sText);
	m_S_Line = p_sText;
	//m_Strlen_Save = m_S_Line.length;

	m_Text_Rect.left = m_Xpos;
	m_Text_Rect.right = m_Ypos;
	m_Text_Rect.top = m_Xpos + m_Width;
	m_Text_Rect.bottom = m_Ypos + m_Height;

	m_Strlen = 1;

	D3DXCreateFont( (*g_pd3dDevice), size+size, size, FW_BOLD, 1, false, 
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, 
		TEXT("����ü"), &m_Font);
}

void UI_Text::SetColor(short R, short G, short B)
{
	m_Font_Color = D3DCOLOR_XRGB(R, G, B);
}


//�Ű�����1�� �ð���
void UI_Text::Draw_Text(float m_fSpeed)
{
	//timeGetTime()�� 1���̸� 60000�� return�ȴ�.
	static DWORD lastTime = timeGetTime();   //������ �ð�(temp����)

	DWORD curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.0001;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.

	//�ؽ�Ʈ�� �׷��ش�. ���ڸ� �ϳ��� ���ش�.
	//�ð��� ���������ִٰ�
	//�Ű����� 1���� �� Ŀ���� 1���ھ� �� ���ش�.
	if(m_S_Line.length() > m_Strlen)
	{

		if(m_fSpeed < m_Text_Out_Sec)
		{
			//������ ��ü ���̺��� ª����
			//if(m_S_Line.length() >= m_Strlen)
			m_Strlen++;

			m_Text_Out_Sec = 0;
		}

		else
			m_Text_Out_Sec += timeDelta;

		lastTime = curTime;
	}

	else if(m_S_Line.length() <= m_Strlen)
	{
		if(0.3f < m_Text_Out_Sec)
			Change_Text(m_Xpos, m_Ypos, " ");

		else
			m_Text_Out_Sec += timeDelta;

		lastTime = curTime;
	}

	m_Font->DrawText(Sprite, m_S_Line.c_str(), m_Strlen, &m_Text_Rect, DT_LEFT | DT_NOCLIP, m_Font_Color);
}

void UI_Text::Change_Text(int p_iPosX, int p_iPosY, char *p_sText)
{
	if(strcmp(m_S_Line.c_str(),p_sText))
	{
		m_Xpos = p_iPosX;
		m_Ypos = p_iPosY;

		m_Text_Rect.left = m_Xpos;
		m_Text_Rect.right = m_Xpos + m_Width;
		m_Text_Rect.top = m_Ypos + m_Height;
		m_Text_Rect.bottom = m_Ypos;

		m_Text_Out_Sec = 1;

		m_S_Line = p_sText;

		m_Strlen = 0;
	}

	else if(m_Xpos != p_iPosX || m_Ypos != p_iPosY)
	{
		m_Xpos = p_iPosX;
		m_Ypos = p_iPosY;

		m_Text_Rect.left = m_Xpos;
		m_Text_Rect.right = m_Ypos;
		m_Text_Rect.top = m_Xpos + m_Width;
		m_Text_Rect.bottom = m_Ypos + m_Height;
	}

}

void UI_Text::Final_UI_Text()
{
	Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	//Create_Font(g_pd3dDevice);
	Draw_Text(0.001);

	Sprite->End();
}