#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include "Define.h"

using namespace std;

class FileLoader// ���Ͽ��� ��ǥ �ҷ�����
{
private:
	//��� ����
	int Object_Num, Type, Type_Kinds, XSize, YSize;
	float Img_Xpos, Img_Ypos, Img_Zpos, Vtx_RX_Size, Vtx_LX_Size, Vtx_UY_Size, Vtx_DY_Size;
	string Root;

	ifstream Map;
	ifstream Img_Root;

	//�̱���
	FileLoader();
	static bool InstanceFlag;
	static FileLoader *Instance;

public:
	//�̱���
	static FileLoader *getInstance();

	FileLoader(int Type_Num,float _posX, float _posY, int _sizeX, int _sizeY, float _vtx_lx, float _vtx_rx, float _vtx_uy, float _vtx_dy, string _root);
	virtual ~FileLoader();

	
	list<FileLoader*> *L_MAP_IMG;
	list<FileLoader*>::iterator It_MAP_IMG;
	list<FileLoader*> *L_MAP_OBJ;
	list<FileLoader*>::iterator It_MAP_OBJ;
	list<FileLoader*> *L_NPC;
	list<FileLoader*>::iterator It_NPC;
	list<FileLoader*> *L_CHRECTER;
	list<FileLoader*>::iterator It_CHRECTER;
	
	void Load_Pos();
	void Add_Object(int Type_Num,float _posX, float _posY, int _sizeX,int _sizeY, float _vtx_lx, float _vtx_rx, float _vtx_uy, float _vtx_dy, string _root);
	void Add_Root(string _root);

	void Init();
	//�� ��ȯ����..
	float Return_Img_Xpos();
	float Return_Img_Ypos();
	int Return_XSize();
	int Return_YSize();
	float Return_Vtx_LXpos();
	float Return_Vtx_RXpos();
	float Return_Vtx_UYpos();
	float Return_Vtx_DYpos();
	string Return_Root();
	//�ʱ�ȭ�� ���� ������
	
};