#pragma once
#include "..\..\[Device]\Define.h"
#include "..\..\[Game]\[Character]\Entity.h"
#include "..\[Device]\Camera.h"
#include "..\[Device]\Render.h"
#include "FPS.h"
#include "[Sound]\Sound.h"

//�� �Ŵ��� �޸� �������ֱ� ���ؼ� ����.
//���߿� �ű�Ŵ�.
#include "..\[Game]\[Scene]\Scene_Manager.h"
class Entity;
class Sound;


class D3Ddevice //����̽� ������Ҹ� Ŭ����ȭ ��Ŵ
{
private:
	LPDIRECT3D9         g_pD3D;// = NULL; // Used to create the D3DDevice
	LPDIRECT3DDEVICE9   g_pd3dDevice;// = NULL; // Our rendering device
	
	Sound c_Sound;

	friend class Render;		//Render Ŭ������ friend�� �����Ͽ� D3Ddevice ������ ��밡���ϰ� ����
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