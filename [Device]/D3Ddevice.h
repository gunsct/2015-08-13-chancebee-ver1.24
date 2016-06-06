#pragma once
#include "..\..\[Device]\Define.h"
#include "..\..\[Game]\[Character]\Entity.h"
#include "..\[Device]\Camera.h"
#include "..\[Device]\Render.h"
#include "FPS.h"
#include "[Sound]\Sound.h"

//씬 매니저 메모리 해제해주기 위해서 생성.
//나중에 옮길거다.
#include "..\[Game]\[Scene]\Scene_Manager.h"
class Entity;
class Sound;


class D3Ddevice //디바이스 구성요소를 클래스화 시킴
{
private:
	LPDIRECT3D9         g_pD3D;// = NULL; // Used to create the D3DDevice
	LPDIRECT3DDEVICE9   g_pd3dDevice;// = NULL; // Our rendering device
	
	Sound c_Sound;

	friend class Render;		//Render 클래스를 friend로 지정하여 D3Ddevice 내에서 사용가능하게 만듬
		Render m_Render;

	FPS m_FPS;

	Scene_Manager *c_Scene_Manager;
	Camera		*c_Camera;

public:
	
	D3Ddevice();
	~D3Ddevice();

	
	VOID D3D_Render();
	HRESULT InitD3D( HWND hWnd );
	VOID Cleanup();
};