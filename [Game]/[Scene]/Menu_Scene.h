#pragma once
#include  "..\\..\\[Device]\Define.h"
#include "..\\..\\[Device]\Resource.h"
#include "..\..\[Device]\[Input_Manager]\Input_Manager.h"
#include "Menu.h"

class Menu;

class Menu_Scene
{
private:
	//����Ʈ �޴��� ���Ʒ��� �������ֱ� ���� ����.
	int m_Select_X_pos, m_Select_Y_pos;

	//����Ʈ �޴� �̵��� ���ؼ�.
	Menu	*c_Menu;

	//�ؽ��� ����
	LPDIRECT3DTEXTURE9 m_tex_Menu;
	LPDIRECT3DTEXTURE9 m_tex_Slect;
	LPDIRECT3DTEXTURE9 m_tex_BackGround;

	//�ؽ��� ���� ����
	LPDIRECT3DVERTEXBUFFER9 m_pVB[3];

public:
	Menu_Scene(void);
	~Menu_Scene(void);

	struct CUSTOMVERTEX;

	//�ؽ��� ������ִ� �Լ�.
	//�ʹ� �� ���� 1�ٷ� �ٿ���.
	void OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);
	
	//OnD3DCreateTexture �Լ��� �� �Լ� �ϳ��� ���Ƴ־�����.
	void Registed_Texture(IDirect3DDevice9* pd3dDevice);

	//���� �� �簢���� �����.
	HRESULT Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, int i);
	
	//�ؽ��� ������ �����ϰ� �簢���� �׷��ش�.
	void Set_Menu_Texture(LPDIRECT3DDEVICE9* pd3dDevice);
	
	//���� ���� �����ϴ°����� �� ���� ���̷��� ���� �Լ��ε� ������ �ȵȴ�.
	//������ �ƴµ� �ذ� ����� �𸣰ڴ�.
	//HRESULT Create_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, CUSTOMVERTEX *vertices);

	//�ؽ�ó ���ۿ� �ؽ��ĸ� ����ְ�.
	void Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//�������� �Լ� ������ ���缭 �� �Լ��� �������.
	void Final_Menu_Scene(LPDIRECT3DDEVICE9* pd3dDevice);
};

