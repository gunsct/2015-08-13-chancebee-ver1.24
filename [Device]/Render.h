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

	//관리대장
	Scene_Manager	*c_Scene_Manager;
	UI_Manager		*c_UI_Manager;

	//씬 클래스들이 들어갈 곳.
	//Menu_Scene		*c_Menu_Scene;
	//Map_Scene		*c_Map_Scene;
	//Battle_Scene	*c_Battle_Scene;
	//Intro			*c_Intro;

	Camera *m_Camera;

public:
	Render(void);
	~Render(void);

	//만약 스프라이트를 사용하게 된다면 사용할 함수다.
	//지금은 가동 안함.
	//void Render_Sprite_Init(LPDIRECT3DDEVICE9 &d3ddev, LPD3DXSPRITE &d3dspt);
	//void Render_Frame(LPDIRECT3DDEVICE9 &d3ddev, LPD3DXSPRITE &d3dspt);
	
	//초기화 할 것들을 이 함수에 넣어주고.
	void Init_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//매 프레임마다 그려줄것은 여기다가 넣어준다.
	void Final_Render(LPDIRECT3DDEVICE9* pd3dDevice);
};

