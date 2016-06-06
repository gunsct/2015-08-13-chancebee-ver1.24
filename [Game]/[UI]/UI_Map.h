#pragma once
#include "..\..\[Device]\Define.h"
#include "..\..\[Device]\Resource.h"
#include "UI_File_Loader.h"

class UI_Map
{
	private:
	//셀렉트 메뉴를 위아래로 움직여주기 위한 변수.
	int m_Select_X_pos, m_Select_Y_pos;


	//텍스쳐 변수
	LPDIRECT3DTEXTURE9 m_tex_UI_Cake;
	LPDIRECT3DTEXTURE9 m_tex_UI_Cake2;
	
	//텍스쳐 버퍼 변수
	LPD3DXSPRITE d3dspt;
	UI_File_Loader *c_UI_File_Loader;

public:
	UI_Map(void);
	~UI_Map(void);

	UI_Map(IDirect3DDevice9* pd3dDevice);

	struct CUSTOMVERTEX;

	//텍스쳐 등록해주는 함수.
	//너무 길어서 내가 1줄로 줄였다.
	void OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);
	
	//OnD3DCreateTexture 함수를 이 함수 하나에 몰아넣어주자.
	void Registed_Texture(IDirect3DDevice9* pd3dDevice);

	//텍스쳐 변수를 세팅하고 사각형에 그려준다.
	void Set_Menu_Texture(LPDIRECT3DDEVICE9* pd3dDevice);


	//텍스처 버퍼에 텍스쳐를 담아주고.
	void Init_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//마지막에 함수 순서에 맞춰서 이 함수에 담아주자.
	void Final_UI_Map(LPDIRECT3DDEVICE9* pd3dDevice);
};

