#include "Map_Scene.h"


Map_Scene::Map_Scene(void)
{
	//c_ChanceBee = new Char_ChanceBee(1, 1, 500, 400, 5, 4);

	for(int i=0;i<DRAW_MAP_NUM;i++)
	{
		m_img_Map_Object[i]=NULL;
	}
	c_FileLoader = FileLoader::getInstance();
	img_cnt=0;

	c_Map_Scene_Dynamic = new Map_Scene_Dynamic();
}


Map_Scene::~Map_Scene(void)
{
	for(int i = 0; i<DRAW_MAP_NUM; i++)
	{
		if(m_img_Map_Object[i] != NULL)
			m_img_Map_Object[i]->Release();

		//if( mm_pVB[i] != NULL )
		//	mm_pVB[i]->Release();
	}
	SAFE_DELETE(mm_pVB);
}

struct Map_Scene::CUSTOMVERTEX
{
	float x, y, z;		
	DWORD color;        // The vertex color
	FLOAT tu,tv;
};

void Map_Scene::OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex)
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


void Map_Scene::Registed_Texture(IDirect3DDevice9* pd3dDevice)
{
	//오브젝트들을 등록한다.
	for(Img_info = c_FileLoader->L_MAP_IMG->begin();Img_info != c_FileLoader->L_MAP_IMG->end(); Img_info++)
	{
		OnD3DCreateTexture(pd3dDevice,(*Img_info)->Return_Root().c_str(),(*Img_info)->Return_XSize(),
			(*Img_info)->Return_YSize(), &m_img_Map_Object[img_cnt]);

		img_cnt++;
	}
	
	//오브젝트들을 등록한다.
	for(Img_info = c_FileLoader->L_MAP_OBJ->begin();Img_info != c_FileLoader->L_MAP_OBJ->end(); Img_info++)
	{
		OnD3DCreateTexture(pd3dDevice,(*Img_info)->Return_Root().c_str(),(*Img_info)->Return_XSize(),
			(*Img_info)->Return_YSize(), &m_img_Map_Object[img_cnt]);

		img_cnt++;
	}

	mm_pVB = new LPDIRECT3DVERTEXBUFFER9[img_cnt];
	for(int i = 0; i <(img_cnt); i++)
		mm_pVB[i] = NULL;
	//OnD3DCreateTexture(pd3dDevice,MAP_EEVEE,1177, 1251, &m_tex_Slect);

	c_Map_Scene_Dynamic->Registed_Texture(pd3dDevice);
}


HRESULT Map_Scene::Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB, LPDIRECT3DDEVICE9* pd3dDevice)
{
	VOID* pVertices;

	CUSTOMVERTEX vertices[] =
	{
		{ (*Img_info)->Return_Img_Xpos() + (*Img_info)->Return_Vtx_LXpos(), (*Img_info)->Return_Img_Ypos() + (*Img_info)->Return_Vtx_UYpos(), 0, 0xffffffff, 0, 0 },		/// v1
		{ (*Img_info)->Return_Img_Xpos() + (*Img_info)->Return_Vtx_LXpos(), (*Img_info)->Return_Img_Ypos() + (*Img_info)->Return_Vtx_DYpos(), 0, 0xffffffff, 0, 1 },		/// v3	

		{ (*Img_info)->Return_Img_Xpos() + (*Img_info)->Return_Vtx_RXpos(), (*Img_info)->Return_Img_Ypos() + (*Img_info)->Return_Vtx_UYpos(), 0, 0xffffffff, 1, 0 },		/// v0
		{ (*Img_info)->Return_Img_Xpos() + (*Img_info)->Return_Vtx_RXpos(), (*Img_info)->Return_Img_Ypos() + (*Img_info)->Return_Vtx_DYpos(), 0, 0xffffffff, 1, 1 },		/// v2

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

		//if(Img_info != c_FileLoader->L_MAP_IMG->end())
			Img_info++;

		return S_OK;
	}
}

void Map_Scene::Set_Map_Texture(LPDIRECT3DDEVICE9* pd3dDevice)
{
	for(int i = 0; i < img_cnt; i++)
	{
		(*pd3dDevice)->SetTexture(0, m_img_Map_Object[i]);
		(*pd3dDevice)->SetStreamSource(0, mm_pVB[i], 0, sizeof( CUSTOMVERTEX ) );
		(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
		(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

void Map_Scene::Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	Img_info = c_FileLoader->L_MAP_IMG->begin();
	for(int i = 0; i < img_cnt; i++)
	{
		if(Img_info != c_FileLoader->L_MAP_IMG->end())
		Setting_Vertex(&mm_pVB[i], pd3dDevice);
		
		else if(Img_info == c_FileLoader->L_MAP_IMG->end())
		{
			Img_info = c_FileLoader->L_MAP_OBJ->begin();

		if(Img_info != c_FileLoader->L_MAP_OBJ->end())
		Setting_Vertex(&mm_pVB[i], pd3dDevice);
	}
	}
}

void Map_Scene::Final_Map_Scene(LPDIRECT3DDEVICE9* pd3dDevice)
{
	//함수 순서를 잘 배치해주어야 한다.
	//조심 할 것.

	c_Map_Scene_Dynamic->Final_Dynamic_Map_Scene(pd3dDevice);
	Setting_Vertex_Render(pd3dDevice);
	Set_Map_Texture(pd3dDevice);
}

