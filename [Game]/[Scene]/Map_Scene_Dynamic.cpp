#include "Map_Scene_Dynamic.h"	

Map_Scene_Dynamic::Map_Scene_Dynamic()
{

	for(int i=0;i<DRAW_CHAR_NUM;i++)
	{
		m_img_Char[i]=NULL;
	}
	c_FileLoader = FileLoader::getInstance();
	img_cnt=0;

	c_Camera = Camera::getInstance();
	c_ChanceBee = new Char_ChanceBee(0.5, 1, 944	, 2288	, 4, 4);
	//c_ChanceBee = new Char_ChanceBee(1, 1, (*c_FileLoader->It_CHRECTER)->Return_XSize(), (*c_FileLoader->It_CHRECTER)->Return_YSize(), 4, 3);
}

Map_Scene_Dynamic::~Map_Scene_Dynamic()
{
		for(int i = 0; i<DRAW_CHAR_NUM; i++)
	{
		if(m_img_Char[i] != NULL)
			m_img_Char[i]->Release();
	}
		SAFE_DELETE(c_ChanceBee);
}





struct Map_Scene_Dynamic::CUSTOMVERTEX
{
	//D3DXVECTOR3 position; // The transformed position for the vertex
	float x, y, z;		
	DWORD color;        // The vertex color
	FLOAT tu,tv;
};

void Map_Scene_Dynamic::OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex)
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


void Map_Scene_Dynamic::Registed_Texture(IDirect3DDevice9* pd3dDevice)
{
	for(c_FileLoader->It_CHRECTER = c_FileLoader->L_CHRECTER->begin();c_FileLoader->It_CHRECTER != c_FileLoader->L_CHRECTER->end(); (c_FileLoader->It_CHRECTER)++)
	{
		OnD3DCreateTexture(pd3dDevice,(*c_FileLoader->It_CHRECTER)->Return_Root().c_str(),(*c_FileLoader->It_CHRECTER)->Return_XSize(),
			(*c_FileLoader->It_CHRECTER)->Return_YSize(), &m_img_Char[img_cnt]);

		img_cnt++;
	}

	mm_pVB = new LPDIRECT3DVERTEXBUFFER9[img_cnt];

	for(int i = 0; i <(img_cnt); i++)
		mm_pVB[i] = NULL;

	c_ChanceBee->Init_Get_Device(&pd3dDevice);
}


HRESULT Map_Scene_Dynamic::Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice)
{
	VOID* pVertices;
		{
			CUSTOMVERTEX vertices[] =
			{
				{ c_ChanceBee->x_pos - c_ChanceBee->get_Char_Size_X() , c_ChanceBee->y_pos - c_ChanceBee->get_Char_Size_Y() , 0, 0x00ffffff, c_ChanceBee->get_Char_Sprite_X() - c_ChanceBee->c_Sprite->get_m_Sprite_Pos_X(), c_ChanceBee->get_Char_Sprite_Y() + c_ChanceBee->c_Sprite->get_m_Sprite_Pos_Y() },		/// v1
				{ c_ChanceBee->x_pos - c_ChanceBee->get_Char_Size_X() , c_ChanceBee->y_pos + c_ChanceBee->get_Char_Size_Y() , 0, 0x00ffffff, c_ChanceBee->get_Char_Sprite_X() - c_ChanceBee->c_Sprite->get_m_Sprite_Pos_X(), c_ChanceBee->get_Char_Sprite_Y() - c_ChanceBee->c_Sprite->get_m_Sprite_Pos_Y() },		/// v3
				{ c_ChanceBee->x_pos + c_ChanceBee->get_Char_Size_X() , c_ChanceBee->y_pos - c_ChanceBee->get_Char_Size_Y() , 0, 0x00ffffff, c_ChanceBee->get_Char_Sprite_X() + c_ChanceBee->c_Sprite->get_m_Sprite_Pos_X(), c_ChanceBee->get_Char_Sprite_Y() + c_ChanceBee->c_Sprite->get_m_Sprite_Pos_Y() },		/// v0
				{ c_ChanceBee->x_pos + c_ChanceBee->get_Char_Size_X() , c_ChanceBee->y_pos + c_ChanceBee->get_Char_Size_Y() , 0, 0x00ffffff, c_ChanceBee->get_Char_Sprite_X() + c_ChanceBee->c_Sprite->get_m_Sprite_Pos_X(), c_ChanceBee->get_Char_Sprite_Y() - c_ChanceBee->c_Sprite->get_m_Sprite_Pos_Y() },		/// v2
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

			//c_FileLoader->It_CHRECTER = c_FileLoader->L_CHRECTER->begin();
			if(c_FileLoader->It_CHRECTER != c_FileLoader->L_CHRECTER->end())
			(c_FileLoader->It_CHRECTER)++;

			return S_OK;
			}
	}
}

void Map_Scene_Dynamic::Set_Char_Texture(LPDIRECT3DDEVICE9* pd3dDevice)
{

		for(int i = 0; i < img_cnt; i++)
	{
		(*pd3dDevice)->SetTexture(0, m_img_Char[i]);
		(*pd3dDevice)->SetStreamSource(0, mm_pVB[i], 0, sizeof( CUSTOMVERTEX ) );
		(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
		(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);
	}
}


void Map_Scene_Dynamic::Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	c_FileLoader->It_CHRECTER = c_FileLoader->L_CHRECTER->begin();

	for(int i = 0; i < img_cnt; i++)
		Setting_Vertex(&mm_pVB[i], pd3dDevice);
}


void Map_Scene_Dynamic::Final_Dynamic_Map_Scene(LPDIRECT3DDEVICE9* pd3dDevice)
{
	
	c_ChanceBee->Interaction();
	c_ChanceBee->get_text();

	c_Camera->Final_Camera(pd3dDevice, c_ChanceBee->x_pos, c_ChanceBee->y_pos);

	Setting_Vertex_Render(pd3dDevice);
	Set_Char_Texture(pd3dDevice);
	c_ChanceBee->Movement();
}