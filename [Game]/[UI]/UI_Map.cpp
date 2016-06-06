#include "UI_Map.h"


UI_Map::UI_Map(void)
{
	c_UI_File_Loader = UI_File_Loader::getInstance();
}

UI_Map::UI_Map(IDirect3DDevice9* pd3dDevice)
{
	c_UI_File_Loader = UI_File_Loader::getInstance();
	Registed_Texture(pd3dDevice);
}

UI_Map::~UI_Map(void)
{
	m_tex_UI_Cake->Release();
	m_tex_UI_Cake2->Release();
}

struct UI_Map::CUSTOMVERTEX
{
	//D3DXVECTOR3 position; // The transformed position for the vertex
	float x, y, z;		
	DWORD color;        // The vertex color
	FLOAT tu,tv;
};

void UI_Map::OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex)
{
	D3DXCreateTextureFromFileExA(pd3dDevice,    // the device pointer
		_name,    // the file name
		sizeX,    // default width
		sizeY,    // default height
		D3DX_DEFAULT,    // no mip mapping
		NULL,    // regular usage
		D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
		D3DPOOL_MANAGED,    // typical memory handling
		D3DX_DEFAULT,    // no filtering
		D3DX_DEFAULT,    // no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),    // the hot-pink color key
		NULL,    // no image info struct
		NULL,    // not using 256 colors
		tex);    // load to sprite
}


void UI_Map::Registed_Texture(IDirect3DDevice9* pd3dDevice)
{
	D3DXCreateSprite(pd3dDevice, &d3dspt);

	OnD3DCreateTexture(pd3dDevice,WOAN_HWA,1024, 683, &m_tex_UI_Cake);
	OnD3DCreateTexture(pd3dDevice,CAKE2,79, 99, &m_tex_UI_Cake2);
}


void UI_Map::Set_Menu_Texture(LPDIRECT3DDEVICE9* pd3dDevice)
{
	d3dspt->Begin(D3DXSPRITE_ALPHABLEND);    // // begin sprite drawing with transparency

	RECT Back_Part;
	D3DXVECTOR3 Back_center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	SetRect(&Back_Part,0,0,1024,683);
	D3DXVECTOR3 Back_position(3.0f, 3.0f, 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(m_tex_UI_Cake, &Back_Part, &Back_center, &Back_position, D3DCOLOR_ARGB(255, 255, 255, 255));
	
	d3dspt->End();
}

void UI_Map::Init_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{

}


void UI_Map::Final_UI_Map(LPDIRECT3DDEVICE9* pd3dDevice)
{
	//Init_Render(pd3dDevice);
	Set_Menu_Texture(pd3dDevice);

}