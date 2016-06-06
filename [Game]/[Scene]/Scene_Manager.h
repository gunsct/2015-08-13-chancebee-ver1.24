#pragma once
#include "..\\..\\[Device]\Define.h"
#include "Map_Scene.h"
#include "Menu_Scene.h"
#include "Battle_Scene.h"
#include "Map.h"
#include "Intro.h"
#include "..\..\[Device]\timer.h"
#include "..\..\[Device]\Camera.h"

class Map_Scene;
class Menu_Scene;
class Battle_Scene;
class Intro;
class Battle;
class Map;
class Camera;
//class Timer;

class Scene_Manager
{
private:
	//생성자
	//외부에서 인스턴스를 생성할 수 없도록 private 영역에 정의하고 구현함
	//원리: private 영역에 생성자가 존재하므로 외부에서 SingletonClass()를 호출할 수 없음
	Scene_Manager(void)
	{
		m_Situation = MENU;

		b_Menu_Scene_Chk =		false;
		b_Map_Scene_Chk =		false;
		b_Battle_Scene_Chk =	false;
		b_Intro_Chk =			false;

		c_Camera = Camera::getInstance();
	};


	//싱글톤 인스턴스가 생성되었는지 여부
	static bool instanceFlag;

	//싱글톤 인스턴스
	static Scene_Manager *instance;

	//private 멤버 변수
	e_Situation m_Situation;

	//씬 클래스들이 들어갈 곳.
	Menu_Scene		*c_Menu_Scene;
	Map_Scene		*c_Map_Scene;
	Battle_Scene	*c_Battle_Scene;
	Intro			*c_Intro;
	Map				*c_Map;
	Battle			*c_Battle;
	Camera			*c_Camera;

	Timer			tm;
	//현재 메뉴씬 그려졌는지 체크해주는 변수.
	bool b_Menu_Scene_Chk;
	bool b_Map_Scene_Chk;
	bool b_Battle_Scene_Chk;
	bool b_Intro_Chk;


public:


	//싱글톤 인스턴스를 반환할 멤버함수
	static Scene_Manager *getInstance();

	//소멸자, instanceFlag를 false로 변경
	virtual ~Scene_Manager(void)
	{
		instanceFlag = false;
	}

	void Singleton_Realese();



	//자기가 쓰고 싶은 함수를 써주자.
	void Change_Scene(e_Situation p_Situation);
	e_Situation Present_Scene();

	//
	void Battle_get_Instance();
	//씬을 초기화
	void Init_Map_Scene(IDirect3DDevice9* pd3dDevice);
	void Init_Menu_Scene(IDirect3DDevice9* pd3dDevice);
	void Init_Battle_Scene(IDirect3DDevice9* pd3dDevice);
	void Init_Intro(IDirect3DDevice9* pd3dDevice);

	//딜리트
	void Del_Map_Scene();
	void Del_Menu_Scene();
	void Del_Battle_Scene();
	void Del_Intro();



	//랜더링
	void Final_Map_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Menu_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Battle_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Intro_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//랜더링 셀렉트
	void Render_Select(LPDIRECT3DDEVICE9* pd3dDevice);

	//어떤씬을 초기화 할건지 체크
	void Chk_Scene_Init(IDirect3DDevice9* pd3dDevice);
};

