#include "Intro.h"


Intro::Intro(void)
{
		for(int i=0;i<DRAW_MAP_NUM;i++)
	{
		m_img_Map_Object[i]=NULL;
	}
	c_FileLoader = FileLoader::getInstance();
	img_cnt=0;
}


Intro::~Intro(void)
{
		for(int i = 0; i<DRAW_MAP_NUM; i++)
	{
		if(m_img_Map_Object[i] != NULL)
			m_img_Map_Object[i]->Release();
	}
	SAFE_DELETE(mm_pVB);
}


struct Intro::CUSTOMVERTEX
{
	float x, y, z;		
	DWORD color;        // The vertex color
	FLOAT tu,tv;
};

void Intro::OnD3DCreateTexture(IDirect3DDevice9* pd3dDevice, LPCSTR _name, int sizeX, int sizeY, LPDIRECT3DTEXTURE9* tex)
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


void Intro::Registed_Texture(IDirect3DDevice9* pd3dDevice)
{
	//오브젝트들을 등록한다.
	for(c_FileLoader->It_MAP_IMG = c_FileLoader->L_MAP_IMG->begin(); c_FileLoader->It_MAP_IMG != c_FileLoader->L_MAP_IMG->end(); c_FileLoader->It_MAP_IMG++)
	{
		OnD3DCreateTexture(pd3dDevice,(*c_FileLoader->It_MAP_IMG)->Return_Root().c_str(),(*c_FileLoader->It_MAP_IMG)->Return_XSize(),
			(*c_FileLoader->It_MAP_IMG)->Return_YSize(), &m_img_Map_Object[img_cnt]);

		img_cnt++;
	}
	
	//오브젝트들을 등록한다.
	for(c_FileLoader->It_MAP_IMG = c_FileLoader->L_MAP_OBJ->begin();c_FileLoader->It_MAP_IMG != c_FileLoader->L_MAP_OBJ->end(); c_FileLoader->It_MAP_IMG++)
	{
		OnD3DCreateTexture(pd3dDevice,(*c_FileLoader->It_MAP_IMG)->Return_Root().c_str(),(*c_FileLoader->It_MAP_IMG)->Return_XSize(),
			(*c_FileLoader->It_MAP_IMG)->Return_YSize(), &m_img_Map_Object[img_cnt]);

		img_cnt++;
	}

	mm_pVB = new LPDIRECT3DVERTEXBUFFER9[img_cnt];
	for(int i = 0; i <(img_cnt); i++)
		mm_pVB[i] = NULL;
	//OnD3DCreateTexture(pd3dDevice,MAP_EEVEE,1177, 1251, &m_tex_Slect);
}


HRESULT Intro::Setting_Vertex(LPDIRECT3DVERTEXBUFFER9 *g_pVB,LPDIRECT3DDEVICE9* pd3dDevice)
{
	VOID* pVertices;

	CUSTOMVERTEX vertices[] =
	{
		{ (*c_FileLoader->It_MAP_IMG)->Return_Img_Xpos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_LXpos(), (*c_FileLoader->It_MAP_IMG)->Return_Img_Ypos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_UYpos(), 0, 0xffffffff, 0, 0 },		/// v1
		{ (*c_FileLoader->It_MAP_IMG)->Return_Img_Xpos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_LXpos(), (*c_FileLoader->It_MAP_IMG)->Return_Img_Ypos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_DYpos(), 0, 0xffffffff, 0, 1 },		/// v3	

		{ (*c_FileLoader->It_MAP_IMG)->Return_Img_Xpos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_RXpos(), (*c_FileLoader->It_MAP_IMG)->Return_Img_Ypos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_UYpos(), 0, 0xffffffff, 1, 0 },		/// v0
		{ (*c_FileLoader->It_MAP_IMG)->Return_Img_Xpos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_RXpos(), (*c_FileLoader->It_MAP_IMG)->Return_Img_Ypos() + (*c_FileLoader->It_MAP_IMG)->Return_Vtx_DYpos(), 0, 0xffffffff, 1, 1 },		/// v2

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
			c_FileLoader->It_MAP_IMG++;

		return S_OK;
	}
}

void Intro::Set_Map_Texture(LPDIRECT3DDEVICE9* pd3dDevice)
{
	for(int i = 0; i < img_cnt; i++)
	{
		(*pd3dDevice)->SetTexture(0, m_img_Map_Object[i]);
		(*pd3dDevice)->SetStreamSource(0, mm_pVB[i], 0, sizeof( CUSTOMVERTEX ) );
		(*pd3dDevice)->SetFVF( D3DFVF_CUSTOMVERTEX );
		(*pd3dDevice)->DrawPrimitive( D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

void Intro::Setting_Vertex_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	c_FileLoader->It_MAP_IMG = c_FileLoader->L_MAP_IMG->begin();
	for(int i = 0; i < img_cnt; i++)
	{
		if(c_FileLoader->It_MAP_IMG != c_FileLoader->L_MAP_IMG->end())
		Setting_Vertex(&mm_pVB[i], pd3dDevice);
		
		else if(c_FileLoader->It_MAP_IMG == c_FileLoader->L_MAP_IMG->end())
		{
			c_FileLoader->It_MAP_IMG = c_FileLoader->L_MAP_OBJ->begin();

		if(c_FileLoader->It_MAP_IMG != c_FileLoader->L_MAP_OBJ->end())
		Setting_Vertex(&mm_pVB[i], pd3dDevice);
	}
	}
}

void Intro::Final_Intro(LPDIRECT3DDEVICE9* pd3dDevice)
{
	//함수 순서를 잘 배치해주어야 한다.
	//조심 할 것.

	Setting_Vertex_Render(pd3dDevice);
	Set_Map_Texture(pd3dDevice);
}

