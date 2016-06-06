#pragma once
#include "..\..\[Device]\Define.h"
#include "..\..\[Device]\Resource.h"
#include "UI_File_Loader.h"

class UI_Map
{
	private:
	//����Ʈ �޴��� ���Ʒ��� �������ֱ� ���� ����.
	int m_Select_X_pos, m_Select_Y_pos;


	//�ؽ��� ����
	LPDIRECT3DTEXTURE9 m_tex_UI_Cake;
	LPDIRECT3DTEXTURE9 m_tex_UI_Cake2;
	
	//�ؽ��� ���� ����
	LPD3DXSPRITE d3dspt;
	UI_File_Loader *c_UI_File_Loader;

public:
	UI_Map(void);
	~UI_Map(void);

	UI_Map(IDirect3DDevice9* pd3dDevice);

	struct CUSTOMVERTEX;

	//�ؽ��� ������ִ� �Լ�.
	//�ʹ� �� ���� 1�ٷ� �ٿ���.
	void OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);
	
	//OnD3DCreateTexture �Լ��� �� �Լ� �ϳ��� ���Ƴ־�����.
	void Registed_Texture(IDirect3DDevice9* pd3dDevice);

	//�ؽ��� ������ �����ϰ� �簢���� �׷��ش�.
	void Set_Menu_Texture(LPDIRECT3DDEVICE9* pd3dDevice);


	//�ؽ�ó ���ۿ� �ؽ��ĸ� ����ְ�.
	void Init_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//�������� �Լ� ������ ���缭 �� �Լ��� �������.
	void Final_UI_Map(LPDIRECT3DDEVICE9* pd3dDevice);
};

