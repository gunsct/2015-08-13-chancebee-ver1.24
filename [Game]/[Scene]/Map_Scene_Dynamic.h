#pragma once
#include  "..\\..\\[Device]\Define.h"
#include "..\\..\\[Device]\Resource.h"
#include "Scene_Manager.h"
#include "..\\..\\[Device]\FileLoader.h"
#include "..\[Character]\Char_ChanceBee.h"
#include "..\..\[Device]\Camera.h"


class Map_Scene_Dynamic
{
private:
	LPDIRECT3DTEXTURE9 m_tex_Chance_Mi_Jung;
	LPDIRECT3DTEXTURE9 m_tex_Golem;

	LPDIRECT3DTEXTURE9 m_img_Char[DRAW_CHAR_NUM];
	LPDIRECT3DVERTEXBUFFER9 *mm_pVB;

	Char_ChanceBee *c_ChanceBee;
	Camera *c_Camera;

	FileLoader *c_FileLoader;

	int img_cnt;

public :
	Map_Scene_Dynamic();
	~Map_Scene_Dynamic();

	

	struct CUSTOMVERTEX;

	void OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);
	void Registed_Texture(IDirect3DDevice9* pd3dDevice);

	HRESULT Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice);
	void Set_Char_Texture(LPDIRECT3DDEVICE9* pd3dDevice);
	HRESULT Create_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, CUSTOMVERTEX *vertices);

	void Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Dynamic_Map_Scene(LPDIRECT3DDEVICE9* pd3dDevice);
};