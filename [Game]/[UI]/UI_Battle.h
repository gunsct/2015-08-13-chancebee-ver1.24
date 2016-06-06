#pragma once
#include "..\\[Character]\\B_Char_ChanceBee.h"
#include "..\\[Scene]\Battle.h"
#include "UI_Text_Battle.h"

class UI_Battle
{
private:
	float Char_Menu_x_pos, Char_Menu_y_pos;
	float Char_Sebu_Menu_x_pos, Char_Sebu_Menu_y_pos;

	LPD3DXSPRITE Chance_Bee_UI_Sprite;

	LPDIRECT3DTEXTURE9 Chance_Bee_Face;
	LPDIRECT3DTEXTURE9 Chance_Bee_HP_TP;
	LPDIRECT3DTEXTURE9 Chance_Bee_HP_Bar;
	LPDIRECT3DTEXTURE9 Chance_Bee_TP_Bar;
	LPDIRECT3DTEXTURE9 Chance_Bee_Battle_Menu;
	LPDIRECT3DTEXTURE9 Chance_Bee_Battle_Select_Bar;
	LPDIRECT3DTEXTURE9 Chance_Bee_Battle_Window;
	LPDIRECT3DTEXTURE9 Chance_Bee_Battle_Window_Attack;
	LPDIRECT3DTEXTURE9 Chance_Bee_Sebu_Select_Bar;

	LPDIRECT3DVERTEXBUFFER9 g_pVB;

	struct CUSTOMVERTEX;

	Battle *c_Battle;
	UI_Text_Battle *c_UI_Text_Battle;
public:
	UI_Battle(void);
	~UI_Battle(void);
	UI_Battle(IDirect3DDevice9* pd3dDevice);

	void Registed_Texture(IDirect3DDevice9* pd3dDevice);
	void OnD3DCreateTexture( IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex);

	void Select_Char(LPDIRECT3DDEVICE9* pd3dDevice);

	void Render_UI_Battle(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_UI_Battle(LPDIRECT3DDEVICE9* pd3dDevice);

	void Move_Menu_Pos();
	void Select_Sebu_Menu();
};

