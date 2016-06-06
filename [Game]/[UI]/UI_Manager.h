#pragma once
#include "..\\..\\[Device]\Define.h"
#include "..\\[Scene]\Scene_Manager.h"
#include "UI_Map.h"
#include "UI_Battle.h"
//#include "UI_Text.h"

class UI_Manager
{
private:
	//�̱���
	static bool InstanceFlag;
	static UI_Manager* Instance;

	UI_Manager(void);

	//���Ŵ��� ��������
	Scene_Manager *c_Scene_Manager;

	//�� ���� UI Ŭ������ �ҷ��ð�.
	UI_Map *c_UI_Map;
	UI_Battle *c_UI_Battle;

	//UI_Text c_UI_Text;

public:
	UI_Manager(LPDIRECT3DDEVICE9* pd3dDevice);

	static UI_Manager* getInstance(LPDIRECT3DDEVICE9* pd3dDevice);
	virtual ~UI_Manager(void){
		InstanceFlag = false;
	};

	void Singleton_Realese();

	void Present_UI(e_Situation m_Situation, LPDIRECT3DDEVICE9* pd3dDevice);
	static bool Change_Chk;
	//���� ���� �а� � UI�� �׸������� �����ϴ� �Լ��� ������.
};

