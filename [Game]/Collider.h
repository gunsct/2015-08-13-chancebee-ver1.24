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
	//���Ϸδ����� ������Ʈ�� ĳ���� �̹����� ���ؽ� ��ǥ�� ũ�� �����´� �̰� �Լ���
	FileLoader *g_FileLoader;
public :
	Collider();
	Collider(int _section_num, float _lx_size, float _rx_size, float _uy_size, float _dy_size);
	~Collider();

	list<Collider*> *L_Section;//���� ����Ʈ
	list<Collider*>::iterator It_Section;

	
	list<FileLoader*>::iterator It_Obj;//������Ʈ ����Ʈ

	void Section_devide();
	//���� �迭 �ҷ��ٰ� for������ ���� ������

	bool Section_Check_And_Collider(float Cvtx_xpos, float Cvtx_ypos, float Cvtx_LX_Size, float Cvtx_RX_Size, float Cvtx_UY_Size, float Cvtx_DY_Size);
	//���� �����ŷ� �� �ȿ� ���� �ִ��� üũ�ϰ� ���� ��ȣ �Կ��ְ� 
	
	//�������غ���
	//����üũ �ҷ��ٰ� üũ�ϰ� �׾ȿ� ������ üũ ��
	
	//���ǿ� ���� ��ȣ������ ���� �¿���� ũ�⸦ �ؾ��ϴ����»����غ���
};