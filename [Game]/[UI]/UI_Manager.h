#pragma once
#include "..\\..\\[Device]\Define.h"
#include "..\\[Scene]\Scene_Manager.h"
#include "UI_Map.h"
#include "UI_Battle.h"
//#include "UI_Text.h"

class UI_Manager
{
private:
	//싱글톤
	static bool InstanceFlag;
	static UI_Manager* Instance;

	UI_Manager(void);

	//씬매니저 가져오기
	Scene_Manager *c_Scene_Manager;

	//각 씬의 UI 클래스를 불러올것.
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
	//현재 씬을 읽고 어떤 UI를 그릴것인지 선택하는 함수를 만들어라.
};

