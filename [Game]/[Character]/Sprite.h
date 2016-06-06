#pragma once
#include <iostream>
#include "..\..\[Device]\Define.h"
#include "Entity.h"
#pragma warning( disable:4995 )
#pragma warning( disable:4324 )
#pragma warning( disable:4238 )




class Sprite
{
private:
	//��������Ʈ ���� ���� ����
	int m_Sprite_Size_X;
	int m_Sprite_Size_Y;

	//��������Ʈ ��ǥ
	float m_Sprite_Pos_X, m_Sprite_Pos_Y;

	//��������Ʈ ������ǥ
	float m_Now_Sprite_Pos_X, m_Now_Sprite_Pos_Y;

	//��������Ʈ �̹��� ������
	int m_Img_Size_X;
	int m_Img_Size_Y;

	//���� �����Ӱ� ������ ����
	int m_Frame_Num;
	int m_Frame_Min;
	int m_Frame_Max;

public:
	Sprite(void);
	~Sprite(void);
	
	//��������Ʈ�� �Ű������� �ִ� �����ڸ� �������.
	Sprite( int _Char_Img_Size_X, int _Char_Img_Size_Y,
			int m_Sprite_Size_X, int m_Sprite_Size_Y);

	//���� ������ ��ȣ�� �����´�.
	int					m_GetFrameNum();

	//�̹����� �ٽ� �ʱ�ȭ �����־�� �Ҷ� ���.
	void				m_SetImage(int _sizeX, int _sizeY,int _cntX, int _cntY);
	
	//Ư�� ���������� ��������Ʈ �ǳʶٱ�
	void				m_SetSprite(int cnt);
	bool				m_NextFrame(bool isLoop, float f_Speed);
	void				m_Set_Another_Frame(int Min, int Max);


	//�ִϸ��̼� �÷���(�ִϸ��̼��� ��� �ȴٸ� ��,�������̶�� ������ ��ȯ)
	void				FrameMove(float f_Speed);
	//�ִϸ��̼��� ��� �ɰ������� ��ȯ(�ݺ� ���ε� �ݿ��Ѵ�.���ѹݺ��̶�� ������ ��)
	virtual	bool		m_isFrameContinue();
	//���� �������� ������ ���������� Ȯ��.
	bool				m_isLastFrame();

	//���� ��������Ʈ UV��ǥ
	float get_Now_Sprite_Pos_X();
	float get_Now_Sprite_Pos_Y();

	float get_m_Sprite_Pos_X();
	float get_m_Sprite_Pos_Y();


};
