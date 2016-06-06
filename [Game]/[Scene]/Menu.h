#pragma once
#include "..\[Scene]\Scene_Manager.h"
#include "..\..\[Device]\Define.h"
#include <iostream>

class Scene_Manager;

class Menu
{
private:
	//씬 매니저를 불러온다.
	Scene_Manager *c_Scene_Manager;

public:
	Menu(void);
	~Menu(void);

	void GameStart();
	void GameLoad();
	void GameOption();
	void GameExit();

	//방향키로 메뉴 조절
	void Menu_Control(int &x_pos, int &y_pos);
	//메뉴 오픈.
	void Menu_Open(int &x_pos, int &y_pos);

};

