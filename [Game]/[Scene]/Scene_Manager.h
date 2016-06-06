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
	//������
	//�ܺο��� �ν��Ͻ��� ������ �� ������ private ������ �����ϰ� ������
	//����: private ������ �����ڰ� �����ϹǷ� �ܺο��� SingletonClass()�� ȣ���� �� ����
	Scene_Manager(void)
	{
		m_Situation = MENU;

		b_Menu_Scene_Chk =		false;
		b_Map_Scene_Chk =		false;
		b_Battle_Scene_Chk =	false;
		b_Intro_Chk =			false;

		c_Camera = Camera::getInstance();
	};


	//�̱��� �ν��Ͻ��� �����Ǿ����� ����
	static bool instanceFlag;

	//�̱��� �ν��Ͻ�
	static Scene_Manager *instance;

	//private ��� ����
	e_Situation m_Situation;

	//�� Ŭ�������� �� ��.
	Menu_Scene		*c_Menu_Scene;
	Map_Scene		*c_Map_Scene;
	Battle_Scene	*c_Battle_Scene;
	Intro			*c_Intro;
	Map				*c_Map;
	Battle			*c_Battle;
	Camera			*c_Camera;

	Timer			tm;
	//���� �޴��� �׷������� üũ���ִ� ����.
	bool b_Menu_Scene_Chk;
	bool b_Map_Scene_Chk;
	bool b_Battle_Scene_Chk;
	bool b_Intro_Chk;


public:


	//�̱��� �ν��Ͻ��� ��ȯ�� ����Լ�
	static Scene_Manager *getInstance();

	//�Ҹ���, instanceFlag�� false�� ����
	virtual ~Scene_Manager(void)
	{
		instanceFlag = false;
	}

	void Singleton_Realese();



	//�ڱⰡ ���� ���� �Լ��� ������.
	void Change_Scene(e_Situation p_Situation);
	e_Situation Present_Scene();

	//
	void Battle_get_Instance();
	//���� �ʱ�ȭ
	void Init_Map_Scene(IDirect3DDevice9* pd3dDevice);
	void Init_Menu_Scene(IDirect3DDevice9* pd3dDevice);
	void Init_Battle_Scene(IDirect3DDevice9* pd3dDevice);
	void Init_Intro(IDirect3DDevice9* pd3dDevice);

	//����Ʈ
	void Del_Map_Scene();
	void Del_Menu_Scene();
	void Del_Battle_Scene();
	void Del_Intro();



	//������
	void Final_Map_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Menu_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Battle_Render(LPDIRECT3DDEVICE9* pd3dDevice);
	void Final_Intro_Render(LPDIRECT3DDEVICE9* pd3dDevice);

	//������ ����Ʈ
	void Render_Select(LPDIRECT3DDEVICE9* pd3dDevice);

	//����� �ʱ�ȭ �Ұ��� üũ
	void Chk_Scene_Init(IDirect3DDevice9* pd3dDevice);
};

