#pragma once
#include  "..\\..\\[Device]\Define.h"
#include "Scene_Manager.h"
#include "..\\..\\[Device]\FileLoader.h"

#include <iostream>
#include <string>

using namespace std;
class Intro
{
private:
	LPDIRECT3DTEXTURE9 m_img_Map_Object[DRAW_MAP_NUM];
	LPDIRECT3DVERTEXBUFFER9 *mm_pVB;
	FileLoader *c_FileLoader;
	int img_cnt;

public:
	Intro(void);
	~Intro(void);

	struct CUSTOMVERTEX;

	void OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);
	void Registed_Texture(IDirect3DDevice9* pd3dDevice);

	HRESULT Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice);
	void Set_Map_Texture(LPDIRECT3DDEVICE9* pd3dDevice);
	HRESULT Create_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, CUSTOMVERTEX *vertices);

	void Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Intro(LPDIRECT3DDEVICE9* pd3dDevice);
};