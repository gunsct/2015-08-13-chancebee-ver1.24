#pragma once
#include "..\\..\\[Device]\Define.h"
#include "..\\..\\[Device]\FileLoader.h"
#include "..\..\[Device]\[Input_Manager]\Input_Manager.h"
#include <iostream>
#include <list>
using namespace std;

class Collider
{
private:
	float Sectoin_Num;
	float LX_Size, RX_Size, UY_Size, DY_Size;
	//파일로더에서 오브젝트랑 캐릭터 이미지의 버텍스 좌표랑 크기 가져온다 이건 함수로
	FileLoader *g_FileLoader;
public :
	Collider();
	Collider(int _section_num, float _lx_size, float _rx_size, float _uy_size, float _dy_size);
	~Collider();

	list<Collider*> *L_Section;//섹션 리스트
	list<Collider*>::iterator It_Section;

	
	list<FileLoader*>::iterator It_Obj;//오브젝트 리스트

	void Section_devide();
	//섹션 배열 불러다가 for문으로 범위 지정해

	bool Section_Check_And_Collider(float Cvtx_xpos, float Cvtx_ypos, float Cvtx_LX_Size, float Cvtx_RX_Size, float Cvtx_UY_Size, float Cvtx_DY_Size);
	//섹션 나눈거로 그 안에 정점 있는지 체크하고 섹션 번호 먹여주고 
	
	//생각좀해보고
	//섹션체크 불러다가 체크하고 그안에 있으면 체크 들어감
	
	//섹션에 섹션 번호만인지 섹션 좌우상하 크기를 해야하는지는생각해보자
};