#pragma once
#include "Scene_Manager.h"
#include "..\..\[Device]\Define.h"
#include "..\[Character]\B_Char_ChanceBee.h"
#include <iostream>
#include "..\[UI]\UI_Text_Battle.h"
#include "..\[Character]\B_Enemy.h"//적과 스킬도 추가해줌
#include "..\[Character]\Skill.h"
#include "..\\..\\[Device]\Timer.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

class Scene_Manager;

class Battle
{
private: 
	Battle(void);
	//싱글톤
	static bool instanceFlag;
	//싱글톤 인스턴스
	static Battle *instance;


	Scene_Manager *c_Scene_Manager;
	B_Char_ChanceBee *c_B_ChanceBee;
	UI_Text_Battle	*c_UI_Text_Battle;
	Timer tm, tm2, tm3;

	B_Enemy *c_B_Enemy[3];
	Skill *s_slash[5];

	//캐릭터 셀렉트 변수들
	bool b_Selected_Char;
	e_Select_Char_Menu m_Selected_Char_Menu;


public:
	bool b_Select_Battle_Menu_Attack;
	bool b_Select_Battle_Menu_Item;
	bool b_Select_Battle_Menu_ECT;

	float Sebu_Menu_y_pos;

	//싱글톤
	static Battle *getInstance();

	virtual ~Battle(void)
	{
		delete c_B_ChanceBee;
	for(int i=0;i<5;i++)
	{
		if(i<ENEMY_NUM)
			delete c_B_Enemy[i];
		delete s_slash[i];
	}
		instanceFlag = false;
	}

	void Singleton_Realese();

	//캐릭터 셀렉트
	void Select_Char();
	void Act_Char();
	int Battle_Sebu_Menu();
	void Battle_Sebu_Menu_Select();

	//씬 전환시 사용할 초기화
	void Init();

	//캐릭터 제어
	void Char_Move();
	void Char_Attack();

	void Char_Control();

	//에너미 제어
	void Enemy_Control();
	void Enemy_Attack();	

	B_Enemy get_Enemy(int i);
	B_Char_ChanceBee get_ChanceBee();

	//캐릭터를 가져옴
	bool get_Selected_Char();
	
	//배틀을 나감
	bool out_battle();

	e_Select_Char_Menu get_Slected_Char_Menu();

	void Final_Battle();
};

