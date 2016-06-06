#pragma once
#include  "..\\..\\[Device]\Define.h"
#include "..\\..\\[Device]\Resource.h"
#include "..\..\[Device]\[Input_Manager]\Input_Manager.h"
#include "Menu.h"

class Menu;

class Menu_Scene
{
private:
	//셀렉트 메뉴를 위아래로 움직여주기 위한 변수.
	int m_Select_X_pos, m_Select_Y_pos;

	//셀렉트 메뉴 이동을 위해서.
	Menu	*c_Menu;

	//텍스쳐 변수
	LPDIRECT3DTEXTURE9 m_tex_Menu;
	LPDIRECT3DTEXTURE9 m_tex_Slect;
	LPDIRECT3DTEXTURE9 m_tex_BackGround;

	//텍스쳐 버퍼 변수
	LPDIRECT3DVERTEXBUFFER9 m_pVB[3];

public:
	Menu_Scene(void);
	~Menu_Scene(void);

	struct CUSTOMVERTEX;

	//텍스쳐 등록해주는 함수.
	//너무 길어서 내가 1줄로 줄였다.
	void OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);
	
	//OnD3DCreateTexture 함수를 이 함수 하나에 몰아넣어주자.
	void Registed_Texture(IDirect3DDevice9* pd3dDevice);

	//정점 찍어서 사각형을 만든다.
	HRESULT Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, int i);
	
	//텍스쳐 변수를 세팅하고 사각형에 그려준다.
	void Set_Menu_Texture(LPDIRECT3DDEVICE9* pd3dDevice);
	
	//위에 정점 선언하는곳에서 좀 길이 줄이려고 만든 함수인데 가동이 안된다.
	//원인은 아는데 해결 방법을 모르겠다.
	//HRESULT Create_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, CUSTOMVERTEX *vertices);

	//텍스처 버퍼에 텍스쳐를 담아주고.
	void Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//마지막에 함수 순서에 맞춰서 이 함수에 담아주자.
	void Final_Menu_Scene(LPDIRECT3DDEVICE9* pd3dDevice);
};

