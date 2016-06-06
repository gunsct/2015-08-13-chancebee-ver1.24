#include "Render.h"


Render::Render(void)
{
	c_Scene_Manager = Scene_Manager::getInstance();

	//c_Battle_Scene = new Battle_Scene();
	//c_Menu_Scene = new Menu_Scene();
	//c_Map_Scene = new Map_Scene();
	
	m_Camera = Camera::getInstance();
}


Render::~Render(void)
{
	//SAFE_DELETE(c_Menu_Scene);
	//SAFE_DELETE(c_Map_Scene);
	//SAFE_DELETE(c_Battle_Scene);
}


void Render::Init_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	//c_Menu_Scene->Registed_Texture(*pd3dDevice);
	//c_Map_Scene->Registed_Texture(*pd3dDevice);
	//c_Battle_Scene->Registed_Texture(*pd3dDevice);


	//디바이스를 불러와야 했기에 초기화를 여기에서 해 주었다.
	c_UI_Manager = UI_Manager::getInstance(pd3dDevice);
}



//여기서부터 메모리 잡아먹는 문제 해결 시작
void Render::Final_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	if( SUCCEEDED( (*pd3dDevice)->BeginScene() ) )
	{
		c_UI_Manager->Present_UI(c_Scene_Manager->Present_Scene(), pd3dDevice);
		(*pd3dDevice)->EndScene();
	}
	c_Scene_Manager->Render_Select(pd3dDevice);
	m_Camera->Final_Camera(pd3dDevice, 0,0);
	//_CrtDumpMemoryLeaks();
}

