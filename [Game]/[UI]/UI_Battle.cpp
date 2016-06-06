#include "UI_Battle.h"


UI_Battle::UI_Battle(void)
{
}


UI_Battle::~UI_Battle(void)
{
}

UI_Battle::UI_Battle(IDirect3DDevice9* pd3dDevice)
{
	c_Battle = Battle::getInstance();
	c_UI_Text_Battle = UI_Text_Battle::getInstance();

	c_UI_Text_Battle->Init_Member(7, 0, 0, 0, 0, " ", &pd3dDevice);

	Registed_Texture(pd3dDevice);

	g_pVB = NULL;
	Char_Menu_x_pos = Char_Menu_y_pos = 0;
	//Char_Sebu_Menu_x_pos = Char_Sebu_Menu_y_pos = 1;
}

struct UI_Battle::CUSTOMVERTEX
{
	float x, y, z;		
	DWORD color;    
	FLOAT tu,tv;
};

void UI_Battle::Registed_Texture(IDirect3DDevice9* pd3dDevice)
{
	D3DXCreateSprite(pd3dDevice, &Chance_Bee_UI_Sprite);

	OnD3DCreateTexture(pd3dDevice, "[Image]\\HP.jpg", 100, 100, &Chance_Bee_HP_Bar);
	OnD3DCreateTexture(pd3dDevice, "[Image]\\TP.jpg", 100, 100, &Chance_Bee_TP_Bar);

	OnD3DCreateTexture(pd3dDevice, BATTLE_CHAR_SELECT_SEBU_MENU_WINDOW, 200, 200, &Chance_Bee_Battle_Window);
	OnD3DCreateTexture(pd3dDevice, "[Image]\\Attack_UI.png", 200, 200, &Chance_Bee_Battle_Window_Attack);
	OnD3DCreateTexture(pd3dDevice, MENU_SELECT, 180, 30, &Chance_Bee_Sebu_Select_Bar);

	OnD3DCreateTexture(pd3dDevice, BATTLE_CHAR_SELECT_MENU, 100, 100, &Chance_Bee_Battle_Menu);
	OnD3DCreateTexture(pd3dDevice, MENU_SELECT, 115, 36, &Chance_Bee_Battle_Select_Bar);

}

void UI_Battle:: OnD3DCreateTexture( IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex)
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

void UI_Battle::Select_Char(LPDIRECT3DDEVICE9* pd3dDevice)
{
	Move_Menu_Pos();
	if(c_Battle->get_Selected_Char() == true)
	{
		VOID* pVertices;

		{
			CUSTOMVERTEX vertices[] =
			{
				{ c_Battle->get_ChanceBee().x_pos-2, c_Battle->get_ChanceBee().y_pos+2, 0, 0xffffffff, 0, 0 },		/// v1
				{ c_Battle->get_ChanceBee().x_pos-2, c_Battle->get_ChanceBee().y_pos-2, 0, 0xffffffff, 0, 1 },		/// v3	
				{ c_Battle->get_ChanceBee().x_pos+2, c_Battle->get_ChanceBee().y_pos+2, 0, 0xffffffff, 1, 0 },		/// v0
				{ c_Battle->get_ChanceBee().x_pos+2, c_Battle->get_ChanceBee().y_pos-2 ,0, 0xffffffff, 1, 1},		/// v2
			};


			if(g_pVB == NULL)
			{
				(*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
					0, D3DFVF_CUSTOMVERTEX,
					D3DPOOL_DEFAULT, &g_pVB, NULL );
			}

			if(g_pVB != NULL)
			{
				g_pVB->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 );
				memcpy( pVertices, vertices, sizeof( vertices ) );
				g_pVB->Unlock();

				(*pd3dDevice)->SetTexture(0, Chance_Bee_Battle_Menu);
				(*pd3dDevice)->SetStreamSource(0, g_pVB, 0, sizeof( CUSTOMVERTEX ) );
				(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
				(*pd3dDevice)->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
			}
		}
	}

	if(c_Battle->get_Selected_Char() == true)
	{
		VOID* pVertices;

		{
			CUSTOMVERTEX vertices[] =
			{
				{ c_Battle->get_ChanceBee().x_pos-1.0f+Char_Menu_x_pos, c_Battle->get_ChanceBee().y_pos+1.0f+Char_Menu_y_pos, 0, 0xffffffff, 0, 0 },		/// v1
				{ c_Battle->get_ChanceBee().x_pos-1.0f+Char_Menu_x_pos, c_Battle->get_ChanceBee().y_pos-1.0f+Char_Menu_y_pos, 0, 0xffffffff, 0, 1 },		/// v3	
				{ c_Battle->get_ChanceBee().x_pos+1.0f+Char_Menu_x_pos, c_Battle->get_ChanceBee().y_pos+1.0f+Char_Menu_y_pos, 0, 0xffffffff, 1, 0 },		/// v0
				{ c_Battle->get_ChanceBee().x_pos+1.0f+Char_Menu_x_pos, c_Battle->get_ChanceBee().y_pos-1.0f+Char_Menu_y_pos , 0, 0xffffffff, 1, 1},		/// v2
			};


			if(g_pVB == NULL)
			{
				(*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
					0, D3DFVF_CUSTOMVERTEX,
					D3DPOOL_DEFAULT, &g_pVB, NULL );
			}

			if(g_pVB != NULL)
			{
				g_pVB->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 );
				memcpy( pVertices, vertices, sizeof( vertices ) );
				g_pVB->Unlock();

				(*pd3dDevice)->SetTexture(0, Chance_Bee_Battle_Select_Bar);
				(*pd3dDevice)->SetStreamSource(0, g_pVB, 0, sizeof( CUSTOMVERTEX ) );
				(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
				(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);
			}
		}
	}
}


void UI_Battle::Render_UI_Battle(LPDIRECT3DDEVICE9* pd3dDevice)
{
	//캐릭터  배틀 UI
	Select_Char(pd3dDevice);

	Chance_Bee_UI_Sprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT m_Rect_Hp_Bar;
	D3DXVECTOR3 Back_center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	SetRect(&m_Rect_Hp_Bar, 0, 0, c_Battle->get_ChanceBee().HP, 10);
	D3DXVECTOR3 HP_bar_position(100.0f, 550.0f, 0.0f);    // position at 50, 50 with no depth
	Chance_Bee_UI_Sprite->Draw(Chance_Bee_HP_Bar, &m_Rect_Hp_Bar, &Back_center, &HP_bar_position, 
		D3DCOLOR_ARGB(255, 0, 255, 0));

	RECT m_Rect_Tp_Bar;
	//D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	SetRect(&m_Rect_Tp_Bar,0,0,c_Battle->get_ChanceBee().TP,10);
	D3DXVECTOR3 TP_bar_position(100.0f, 580.0f, 0.0f);    // position at 50, 50 with no depth
	Chance_Bee_UI_Sprite->Draw(Chance_Bee_TP_Bar, &m_Rect_Tp_Bar, &Back_center, &TP_bar_position, 
		D3DCOLOR_ARGB(255, 0, 0, 255));

	Select_Sebu_Menu();

	Chance_Bee_UI_Sprite->End();
}

void UI_Battle::Final_UI_Battle(LPDIRECT3DDEVICE9* pd3dDevice)
{
	Render_UI_Battle(pd3dDevice);
	c_UI_Text_Battle->Final_UI_Text_Battle();
}



void UI_Battle::Move_Menu_Pos()
{
	switch(c_Battle->get_Slected_Char_Menu())
	{
	case S_M_UP:

		if(c_Battle->b_Select_Battle_Menu_Attack != true && c_Battle->b_Select_Battle_Menu_ECT != true  && c_Battle->b_Select_Battle_Menu_Item != true )
		{
			Char_Menu_x_pos = 0;
			Char_Menu_y_pos = 1.5f;
		}
		if(KEY_DOWN_ONE_CLICK(VK_RETURN))
		{
			c_Battle->b_Select_Battle_Menu_Attack = true;
			c_Battle->b_Select_Battle_Menu_ECT = false;
			c_Battle->b_Select_Battle_Menu_Item = false;
		}
		break;

	case S_M_DOWN:
		if(c_Battle->b_Select_Battle_Menu_Attack != true && c_Battle->b_Select_Battle_Menu_ECT != true  && c_Battle->b_Select_Battle_Menu_Item != true )
		{
			Char_Menu_x_pos = 0;
			Char_Menu_y_pos = -1.5f;
		}
		break;

	case S_M_LEFT:
		if(c_Battle->b_Select_Battle_Menu_Attack != true && c_Battle->b_Select_Battle_Menu_ECT != true  && c_Battle->b_Select_Battle_Menu_Item != true )
		{
			Char_Menu_x_pos = -1.5f;
			Char_Menu_y_pos = 0;
		}

		if(KEY_DOWN_ONE_CLICK(VK_RETURN))
		{
			c_Battle->b_Select_Battle_Menu_Attack = false;
			c_Battle->b_Select_Battle_Menu_ECT = true;
			c_Battle->b_Select_Battle_Menu_Item = false;
		}
		break;

	case S_M_RIGHT:
		if(c_Battle->b_Select_Battle_Menu_Attack != true && c_Battle->b_Select_Battle_Menu_ECT != true  && c_Battle->b_Select_Battle_Menu_Item != true )
		{
			Char_Menu_x_pos = 1.5f;
			Char_Menu_y_pos = 0;
		}

		if(KEY_DOWN_ONE_CLICK(VK_RETURN))
		{
			c_Battle->b_Select_Battle_Menu_Attack = false;
			c_Battle->b_Select_Battle_Menu_ECT = false;
			c_Battle->b_Select_Battle_Menu_Item = true;
		}
		break;

	case S_M_NOTHING:

		Char_Menu_x_pos = 0;
		Char_Menu_y_pos = 0;

		c_Battle->b_Select_Battle_Menu_Attack = false;
		c_Battle->b_Select_Battle_Menu_ECT = false;
		c_Battle->b_Select_Battle_Menu_Item = false;
		c_UI_Text_Battle->Change_Text(0, 0, "");
		break;
	}
}

void UI_Battle::Select_Sebu_Menu()
{

	if(c_Battle->b_Select_Battle_Menu_Attack == true)
	{
		RECT m_Rect_Window;
		D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);   	
		D3DXVECTOR3 Window_position;   

		SetRect(&m_Rect_Window, 0, 0, 200, 200);
		Window_position = D3DXVECTOR3(20.0f, 20.0f, 0.0f);    // position at 50, 50 with no depth
		Chance_Bee_UI_Sprite->Draw(Chance_Bee_Battle_Window, &m_Rect_Window, &center, &Window_position, 
			D3DCOLOR_ARGB(255, 255, 255, 255));

		Chance_Bee_UI_Sprite->Draw(Chance_Bee_Battle_Window_Attack, &m_Rect_Window, &center, &Window_position, 
			D3DCOLOR_ARGB(255, 255, 255, 255));

		SetRect(&m_Rect_Window, 0, 0, 180, 30);
		//Char_Sebu_Menu_y_pos *= c_Battle->Battle_Sebu_Menu();
		Window_position = D3DXVECTOR3(30.0f, 60.0f + c_Battle->Battle_Sebu_Menu(), 0.0f);    // position at 50, 50 with no depth
		Chance_Bee_UI_Sprite->Draw(Chance_Bee_Sebu_Select_Bar, &m_Rect_Window, &center, &Window_position, 
			D3DCOLOR_ARGB(255, 255, 255, 255));
	}


	else if(c_Battle->b_Select_Battle_Menu_Item == true)
	{
		RECT m_Rect_Window;
		D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);   	
		D3DXVECTOR3 Window_position;   

		SetRect(&m_Rect_Window, 0, 0, 200, 200);
		Window_position = D3DXVECTOR3(20.0f, 20.0f, 0.0f);    // position at 50, 50 with no depth
		Chance_Bee_UI_Sprite->Draw(Chance_Bee_Battle_Window, &m_Rect_Window, &center, &Window_position, 
			D3DCOLOR_ARGB(255, 255, 0, 0));

		c_UI_Text_Battle->Change_Text(40, 30, "아이템");
	}

	else if(c_Battle->b_Select_Battle_Menu_ECT == true)
	{
		RECT m_Rect_Window;
		D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);	
		D3DXVECTOR3 Window_position;   

		SetRect(&m_Rect_Window, 0, 0, 200, 200);
		Window_position = D3DXVECTOR3(20.0f, 20.0f, 0.0f);    // position at 50, 50 with no depth
		Chance_Bee_UI_Sprite->Draw(Chance_Bee_Battle_Window, &m_Rect_Window, &center, &Window_position, 
			D3DCOLOR_ARGB(255, 255, 0, 0));

		c_UI_Text_Battle->Change_Text(40, 30, "기타");
	}


}