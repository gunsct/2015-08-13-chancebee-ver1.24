#include "Battle_Scene.h"


Battle_Scene::Battle_Scene(void)
{


	for(int i = 0; i<DRAW_CHAR_NUM; i++)
	{
		m_pVB[i] = NULL;
	}
}


Battle_Scene::~Battle_Scene(void)
{
	for(int i = 0; i<DRAW_CHAR_NUM; i++)
	{
		if( m_pVB[i] != NULL )
			m_pVB[i]->Release();
	}
	SAFE_DELETE(c_Battle);
}

struct Battle_Scene::CUSTOMVERTEX
{
	//D3DXVECTOR3 position; // The transformed position for the vertex
	float x, y, z;		
	DWORD color;        // The vertex color
	FLOAT tu,tv;
};

void Battle_Scene::OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex)
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


void Battle_Scene::Registed_Texture(IDirect3DDevice9* pd3dDevice)
{
	c_Battle = Battle::getInstance();

	OnD3DCreateTexture(pd3dDevice, MAP_EEVEE, 1095, 1955, &B_enemy[0]);
	OnD3DCreateTexture(pd3dDevice, MAP_EEVEE, 1095, 1955, &B_enemy[1]);
	OnD3DCreateTexture(pd3dDevice, MAP_GOLEM, 1095, 1955, &B_enemy[2]);

	OnD3DCreateTexture(pd3dDevice, MAP_CHANCE_MIJUNG_ANI, 944, 2288, &B_char_Test);
}


HRESULT Battle_Scene::Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, int i)
{
	VOID* pVertices;
	switch(i)
	{
	case 0:
		{
			CUSTOMVERTEX vertices[] =
			{
				{ c_Battle->get_Enemy(0).x_pos - c_Battle->get_Enemy(0).get_Enemy_Size_X(), c_Battle->get_Enemy(0).y_pos + c_Battle->get_Enemy(0).get_Enemy_Size_Y(), 0, 0x00ffffff, 0,0 },		/// v1
				{ c_Battle->get_Enemy(0).x_pos - c_Battle->get_Enemy(0).get_Enemy_Size_X(), c_Battle->get_Enemy(0).y_pos - c_Battle->get_Enemy(0).get_Enemy_Size_Y(), 0, 0x00ffffff, 0,1 },		/// v3
				{ c_Battle->get_Enemy(0).x_pos + c_Battle->get_Enemy(0).get_Enemy_Size_X(), c_Battle->get_Enemy(0).y_pos + c_Battle->get_Enemy(0).get_Enemy_Size_Y(), 0, 0x00ffffff, 1,0 },		/// v0
				{ c_Battle->get_Enemy(0).x_pos + c_Battle->get_Enemy(0).get_Enemy_Size_X(), c_Battle->get_Enemy(0).y_pos - c_Battle->get_Enemy(0).get_Enemy_Size_Y(), 0, 0x00ffffff, 1,1 },		/// v2	
			};

			if(*g_pVB == NULL)
			{
				if( FAILED( (*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
					0, D3DFVF_CUSTOMVERTEX,
					D3DPOOL_DEFAULT, &(*g_pVB), NULL ) ) )
				{
					return E_FAIL;
				}
			}


			if(*g_pVB != NULL)
			{
				if( FAILED( (*g_pVB)->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 ) ) )
					return E_FAIL;

				memcpy( pVertices, vertices, sizeof( vertices ) );
				(*g_pVB)->Unlock();

				return S_OK;
			}
			//Create_Vertex(g_pVB, pd3dDevice, vertices);
			break;
		}


	case 1:
		{
			CUSTOMVERTEX vertices[] =
			{
				{ c_Battle->get_Enemy(1).x_pos - c_Battle->get_Enemy(1).get_Enemy_Size_X(), c_Battle->get_Enemy(1).y_pos + c_Battle->get_Enemy(1).get_Enemy_Size_Y(), 0, 0x00ffffff, 0,0 },		/// v1
				{ c_Battle->get_Enemy(1).x_pos - c_Battle->get_Enemy(1).get_Enemy_Size_X(), c_Battle->get_Enemy(1).y_pos - c_Battle->get_Enemy(1).get_Enemy_Size_Y(), 0, 0x00ffffff, 0,1 },		/// v3
				{ c_Battle->get_Enemy(1).x_pos + c_Battle->get_Enemy(1).get_Enemy_Size_X(), c_Battle->get_Enemy(1).y_pos + c_Battle->get_Enemy(1).get_Enemy_Size_Y(), 0, 0x00ffffff, 1,0},		/// v0
				{ c_Battle->get_Enemy(1).x_pos + c_Battle->get_Enemy(1).get_Enemy_Size_X(), c_Battle->get_Enemy(1).y_pos - c_Battle->get_Enemy(1).get_Enemy_Size_Y() , 0, 0x00ffffff, 1,1 },		/// v2	
			};

			if(*g_pVB == NULL)
			{
				if( FAILED( (*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
					0, D3DFVF_CUSTOMVERTEX,
					D3DPOOL_DEFAULT, &(*g_pVB), NULL ) ) )
				{
					return E_FAIL;
				}
			}


			if(*g_pVB != NULL)
			{
				if( FAILED( (*g_pVB)->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 ) ) )
					return E_FAIL;

				memcpy( pVertices, vertices, sizeof( vertices ) );
				(*g_pVB)->Unlock();

				return S_OK;
			}
			//Create_Vertex(g_pVB, pd3dDevice, vertices);
			break;
		}
	case 2:
		{
			CUSTOMVERTEX vertices[] =
			{
				{ c_Battle->get_Enemy(2).x_pos - c_Battle->get_Enemy(2).get_Enemy_Size_X(), c_Battle->get_Enemy(2).y_pos + c_Battle->get_Enemy(2).get_Enemy_Size_Y(), 0, 0x00ffffff, 0,0 },		/// v1
				{ c_Battle->get_Enemy(2).x_pos - c_Battle->get_Enemy(2).get_Enemy_Size_X(), c_Battle->get_Enemy(2).y_pos - c_Battle->get_Enemy(2).get_Enemy_Size_Y(), 0, 0x00ffffff, 0,1 },		/// v3
				{ c_Battle->get_Enemy(2).x_pos + c_Battle->get_Enemy(2).get_Enemy_Size_X(), c_Battle->get_Enemy(2).y_pos + c_Battle->get_Enemy(2).get_Enemy_Size_Y(), 0, 0x00ffffff, 1,0 },		/// v0
				{ c_Battle->get_Enemy(2).x_pos + c_Battle->get_Enemy(2).get_Enemy_Size_X(), c_Battle->get_Enemy(2).y_pos - c_Battle->get_Enemy(2).get_Enemy_Size_Y() , 0, 0x00ffffff, 1,1 },		/// v2	
			};

			if(*g_pVB == NULL)
			{
				if( FAILED( (*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
					0, D3DFVF_CUSTOMVERTEX,
					D3DPOOL_DEFAULT, &(*g_pVB), NULL ) ) )
				{
					return E_FAIL;
				}
			}


			if(*g_pVB != NULL)
			{
				if( FAILED( (*g_pVB)->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 ) ) )
					return E_FAIL;

				memcpy( pVertices, vertices, sizeof( vertices ) );
				(*g_pVB)->Unlock();

				return S_OK;
			}
			//Create_Vertex(g_pVB, pd3dDevice, vertices);
			break;
		}
	case 3:
		{

			CUSTOMVERTEX vertices[] =
			{
				{ c_Battle->get_ChanceBee().x_pos - c_Battle->get_ChanceBee().get_Char_Size_X(), 1, 0, 0x00ffffff, c_Battle->get_ChanceBee().get_Char_Sprite_X()- (0.3f/2.0f), c_Battle->get_ChanceBee().get_Char_Sprite_Y()-c_Battle->get_ChanceBee().get_Char_Sprite_Y() },		/// v1
				{ c_Battle->get_ChanceBee().x_pos - c_Battle->get_ChanceBee().get_Char_Size_X(), -1, 0, 0x00ffffff, c_Battle->get_ChanceBee().get_Char_Sprite_X()-(0.3f/2.0f),c_Battle->get_ChanceBee().get_Char_Sprite_Y()+c_Battle->get_ChanceBee().get_Char_Sprite_Y() },		/// v3
				{ c_Battle->get_ChanceBee().x_pos + c_Battle->get_ChanceBee().get_Char_Size_X(), 1, 0, 0x00ffffff, c_Battle->get_ChanceBee().get_Char_Sprite_X()+(0.3f/2.0f), c_Battle->get_ChanceBee().get_Char_Sprite_Y()-c_Battle->get_ChanceBee().get_Char_Sprite_Y() },		/// v0
				{ c_Battle->get_ChanceBee().x_pos + c_Battle->get_ChanceBee().get_Char_Size_X(), -1 , 0, 0x00ffffff, c_Battle->get_ChanceBee().get_Char_Sprite_X()+(0.3f/2.0f), c_Battle->get_ChanceBee().get_Char_Sprite_Y()+c_Battle->get_ChanceBee().get_Char_Sprite_Y() },		/// v2			
			};

			if(*g_pVB == NULL)
			{
				if( FAILED( (*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
					0, D3DFVF_CUSTOMVERTEX,
					D3DPOOL_DEFAULT, &(*g_pVB), NULL ) ) )
				{
					return E_FAIL;
				}
			}

			if(*g_pVB != NULL)
			{
				if( FAILED( (*g_pVB)->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 ) ) )
					return E_FAIL;

				memcpy( pVertices, vertices, sizeof( vertices ) );
				(*g_pVB)->Unlock();

				return S_OK;
			}

			break;
		}
	}
}

void Battle_Scene::Set_Battle_Texture(LPDIRECT3DDEVICE9* pd3dDevice)
{

	//에너미 NUM이라는 변수를 만들던가 define으로 만들것.
	for(int i=0;i<3;i++)
	{
		if(c_Battle->get_Enemy(i).HP > 0)
		{
			(*pd3dDevice)->SetTexture(0, B_enemy[i]);
			(*pd3dDevice)->SetStreamSource(0, m_pVB[i], 0, sizeof( CUSTOMVERTEX ) );
			(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
			(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);
		}
	}

	if(c_Battle->get_ChanceBee().HP > 0)
	{
		(*pd3dDevice)->SetTexture(0, B_char_Test);
		(*pd3dDevice)->SetStreamSource( 0, m_pVB[3], 0, sizeof( CUSTOMVERTEX ) );
		(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
		(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);
	}
}


void Battle_Scene::Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	for(int i = 0; i < DRAW_CHAR_NUM; i++)
		Setting_Vertex(&m_pVB[i], pd3dDevice, i);
}


void Battle_Scene::Final_Battle_Scene(LPDIRECT3DDEVICE9* pd3dDevice)
{
	//메뉴씬은 나중에 다시 작성
	//여기에 써줬더니 큰일날뻔했다. 매 프레임마다 텍스쳐 변수에 이미지를 등록하는데
	//cpu와 메모리 점유율이 100%가 되었다.
	//Registed_Texture(*pd3dDevice);

	c_Battle->Final_Battle();
	Setting_Vertex_Render(pd3dDevice);
	Set_Battle_Texture(pd3dDevice);

}