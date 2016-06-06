#pragma once
#include  "..\\..\\[Device]\Define.h"
#include "..\\..\\[Device]\Resource.h"
#include "Battle.h"


class Battle;

class Battle_Scene
{
private:

	//셀렉트 메뉴 이동을 위해서.
	Battle	*c_Battle;
	

	LPDIRECT3DTEXTURE9 B_enemy[3];
	LPDIRECT3DTEXTURE9 B_char_Test;
	LPDIRECT3DVERTEXBUFFER9 m_pVB[DRAW_CHAR_NUM];
	LPDIRECT3DVERTEXBUFFER9 m_Hp;
public:
	Battle_Scene(void);
	~Battle_Scene(void);

	struct CUSTOMVERTEX;

	void OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);
	void Registed_Texture(IDirect3DDevice9* pd3dDevice);

	HRESULT Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, int i);
	void Set_Battle_Texture(LPDIRECT3DDEVICE9* pd3dDevice);
	HRESULT Create_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, CUSTOMVERTEX *vertices);

	void Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Battle_Scene(LPDIRECT3DDEVICE9* pd3dDevice);
};