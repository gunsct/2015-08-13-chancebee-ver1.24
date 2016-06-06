#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include "..\\..\\[Device]\Define.h"

using namespace std;

class UI_File_Loader
{
private:
	//������Ʈ ����, Ÿ��, Ÿ������, ���α���, ���α���
	int Object_Num, Type, Type_Kinds, XSize, YSize;

	//�̹��� ��ġ�� ��ǥ
	float Img_Xpos, Img_Ypos;
	string Root;
	ifstream UI_txt;

	//�̱���
	UI_File_Loader();
	static bool InstanceFlag;
	static UI_File_Loader *Instance;

	list<UI_File_Loader*> *L_UI_MAP_IMG;
	list<UI_File_Loader*> *L_UI_BATTLE_IMG;

	list<UI_File_Loader*> *L_temp_UI_MAP_IMG;
	list<UI_File_Loader*> *L_temp_UI_BATTLE_IMG;


	list<UI_File_Loader*>::iterator It_UI_MAP_IMG;
	list<UI_File_Loader*>::iterator It_UI_BATTLE_IMG;
public:
	UI_File_Loader(int _Type_Kinds, int XSize, int YSize, float Img_Xpos, float Img_Ypos, string _Root);
	virtual ~UI_File_Loader(void);

	//�̱���
	static UI_File_Loader* getInstance();
	void Singleton_Realese();

	void Load_File();
	void Add_UI(int _Type, int _Type_Kinds, int XSize, int YSize, float Img_Xpos, float Img_Ypos, string _Root);

	list<UI_File_Loader*> get_UI_MAP();
	list<UI_File_Loader*> get_UI_BATTLE();

	void Reload_UI_MAP();
	void Reload_UI_BATTLE();

	void Delete_UI_MAP();
	void Delete_UI_BATTLE();
};

