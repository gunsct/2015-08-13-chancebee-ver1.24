#pragma once
#include "..\[Device]\Define.h"
#include "..\[Device]\Resource.h"
#include "..\[Device]\[Input_Manager]\Input_Manager.h"
#include "..\[Game]\[Character]\Character.h"
#include "..\\[Game]\[Scene]\Scene_Manager.h"
#include "..\[Game]\[Scene]\Map_Scene.h"
#include "..\[Game]\[Scene]\Menu_Scene.h"
#include "..\[Game]\[Scene]\Battle_Scene.h"
#include "..\[Game]\[Scene]\Intro.h"
#include "..\[Game]\[UI]\UI_Manager.h"


class Render
{
private:

	//��������
	Scene_Manager	*c_Scene_Manager;
	UI_Manager		*c_UI_Manager;

	//�� Ŭ�������� �� ��.
	//Menu_Scene		*c_Menu_Scene;
	//Map_Scene		*c_Map_Scene;
	//Battle_Scene	*c_Battle_Scene;
	//Intro			*c_Intro;

	Camera *m_Camera;

public:
	Render(void);
	~Render(void);

	//���� ��������Ʈ�� ����ϰ� �ȴٸ� ����� �Լ���.
	//������ ���� ����.
	//void Render_Sprite_Init(LPDIRECT3DDEVICE9 &d3ddev, LPD3DXSPRITE &d3dspt);
	//void Render_Frame(LPDIRECT3DDEVICE9 &d3ddev, LPD3DXSPRITE &d3dspt);
	
	//�ʱ�ȭ �� �͵��� �� �Լ��� �־��ְ�.
	void Init_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//�� �����Ӹ��� �׷��ٰ��� ����ٰ� �־��ش�.
	void Final_Render(LPDIRECT3DDEVICE9* pd3dDevice);
};

