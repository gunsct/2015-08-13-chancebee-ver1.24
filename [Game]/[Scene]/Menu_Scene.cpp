#include "Menu_Scene.h"


Menu_Scene::Menu_Scene(void)
{
	m_Select_X_pos = 0;
	m_Select_Y_pos = 0;
	c_Menu = new Menu();

	for(int i = 0; i<DRAW_MENU_NUM; i++)
	{
		m_pVB[i] = NULL;
	}
}


Menu_Scene::~Menu_Scene(void)
{
	for(int i = 0; i<DRAW_MENU_NUM; i++)
	{
		if( m_pVB[i] != NULL )
			m_pVB[i]->Release();
	}
	SAFE_DELETE(c_Menu);
}

struct Menu_Scene::CUSTOMVERTEX
{
	//D3DXVECTOR3 position; // The transformed position for the vertex
	float x, y, z;		
	DWORD color;        // The vertex color
	FLOAT tu,tv;
};

void Menu_Scene::OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex)
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


void Menu_Scene::Registed_Texture(IDirect3DDevice9* pd3dDevice)
{
	OnD3DCreateTexture(pd3dDevice,MENU_INDEX,579, 1238, &m_tex_Menu);
	OnD3DCreateTexture(pd3dDevice,MENU_SELECT,115, 36, &m_tex_Slect);
	OnD3DCreateTexture(pd3dDevice,"[Image]\\Woan_Hwa.png",2000, 1574, &m_tex_BackGround);
}


HRESULT Menu_Scene::Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB, LPDIRECT3DDEVICE9* pd3dDevice, int i)
{
	VOID* pVertices;
	switch(i)
	{
			case 0:
		{
			CUSTOMVERTEX vertices[] =
			{
				{ -4, 4, 0, 0x00ffffff, 0, 0 },		/// v1
				{ -4, -4, 0, 0x00ffffff, 0, 1 },		/// v3
				{ 4, 4, 0, 0x00ffffff, 1, 0 },		/// v0
				{ 4, -4 , 0, 0x00ffffff, 1, 1 },		/// v2
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

		//메뉴 바
	case 1:
		{
			CUSTOMVERTEX vertices[] =
			{
				{ -1, 2, 0, 0xffffffff, 0, 0 },		/// v1
				{ -1, -2, 0, 0xffffffff, 0, 1 },		/// v3	
				{ 1, 2, 0, 0xffffffff, 1, 0 },		/// v0
				{ 1, -2 , 0, 0xffffffff, 1, 1},		/// v2
				

			};

			if(*g_pVB == NULL)
			{
				if( FAILED( (*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
					0, D3DFVF_CUSTOMVERTEX,
					D3DPOOL_DEFAULT, &(*g_pVB), NULL ) ) )
				{
					return E_FAIL;
				}




				if( FAILED( (*g_pVB)->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 ) ) )
					return E_FAIL;

				memcpy( pVertices, vertices, sizeof( vertices ) );
				(*g_pVB)->Unlock();

				return S_OK;
			}
			//Create_Vertex(g_pVB, pd3dDevice, vertices);
			break;
		}

		//셀렉트 바
	case 2:
		{
			CUSTOMVERTEX vertices[] =
			{
				{ -1 + m_Select_X_pos, 2 + m_Select_Y_pos, 0, 0x00ffffff, 0, 0 },		/// v1
				{ -1 + m_Select_X_pos, 1 + m_Select_Y_pos, 0, 0x00ffffff, 0, 1 },		/// v3
				{ 1 + m_Select_X_pos, 2 + m_Select_Y_pos, 0, 0x00ffffff, 1, 0 },		/// v0
				{ 1 + m_Select_X_pos, 1 + m_Select_Y_pos , 0, 0x00ffffff, 1, 1 },		/// v2
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


	}
}

void Menu_Scene::Set_Menu_Texture(LPDIRECT3DDEVICE9* pd3dDevice)
{
	(*pd3dDevice)->SetTexture(0, m_tex_BackGround);
	(*pd3dDevice)->SetStreamSource( 0, m_pVB[0], 0, sizeof( CUSTOMVERTEX ) );
	(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
	(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);

	(*pd3dDevice)->SetTexture(0, m_tex_Menu);
	(*pd3dDevice)->SetStreamSource(0, m_pVB[1], 0, sizeof( CUSTOMVERTEX ) );
	(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
	(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);

	(*pd3dDevice)->SetTexture(0, m_tex_Slect);
	(*pd3dDevice)->SetStreamSource( 0, m_pVB[2], 0, sizeof( CUSTOMVERTEX ) );
	(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
	(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);


}

//위에 정점 선언하는곳에서 좀 길이 줄이려고 만든 함수인데 가동이 안된다.
//이유는 아는데 해결 방법을 모르겠다.
//HRESULT Menu_Scene::Create_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice, CUSTOMVERTEX *vertices)
//{
//	if( FAILED( (*pd3dDevice)->CreateVertexBuffer( 4 * sizeof( CUSTOMVERTEX ),
//		0, D3DFVF_CUSTOMVERTEX,
//		D3DPOOL_DEFAULT, &(*g_pVB), NULL ) ) )
//	{
//		return E_FAIL;
//	}
//
//
//	VOID* pVertices;
//
//	if( FAILED( (*g_pVB)->Lock( 0, sizeof( vertices ), ( void** )&pVertices, 0 ) ) )
//		return E_FAIL;
//
//	memcpy( pVertices, vertices, sizeof( vertices ) );
//	(*g_pVB)->Unlock();
//
//	return S_OK;
//}


void Menu_Scene::Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	for(int i = 0; i < DRAW_MENU_NUM; i++)
		Setting_Vertex(&m_pVB[i], pd3dDevice, i);
}


void Menu_Scene::Final_Menu_Scene(LPDIRECT3DDEVICE9* pd3dDevice)
{
	//메뉴씬은 나중에 다시 작성
	//여기에 써줬더니 큰일날뻔했다. 매 프레임마다 텍스쳐 변수에 이미지를 등록하는데
	//cpu와 메모리 점유율이 100%가 되었다.
	//Registed_Texture(*pd3dDevice);

	c_Menu->Menu_Control(m_Select_X_pos, m_Select_Y_pos);
	Setting_Vertex_Render(pd3dDevice);
	Set_Menu_Texture(pd3dDevice);

}