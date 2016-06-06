#pragma once
#include "..\[Scene]\Scene_Manager.h"
#include "..\..\[Device]\Define.h"
#include <iostream>

class Scene_Manager;

class Menu
{
private:
	//�� �Ŵ����� �ҷ��´�.
	Scene_Manager *c_Scene_Manager;

public:
	Menu(void);
	~Menu(void);

	void GameStart();
	void GameLoad();
	void GameOption();
	void GameExit();

	//����Ű�� �޴� ����
	void Menu_Control(int &x_pos, int &y_pos);
	//�޴� ����.
	void Menu_Open(int &x_pos, int &y_pos);

};

