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
	//스프라이트 가로 세로 갯수
	int m_Sprite_Size_X;
	int m_Sprite_Size_Y;

	//스프라이트 좌표
	float m_Sprite_Pos_X, m_Sprite_Pos_Y;

	//스프라이트 현재좌표
	float m_Now_Sprite_Pos_X, m_Now_Sprite_Pos_Y;

	//스프라이트 이미지 사이즈
	int m_Img_Size_X;
	int m_Img_Size_Y;

	//현재 프레임과 프레임 갯수
	int m_Frame_Num;
	int m_Frame_Min;
	int m_Frame_Max;

public:
	Sprite(void);
	~Sprite(void);
	
	//스프라이트를 매개변수가 있는 생성자를 만들었다.
	Sprite( int _Char_Img_Size_X, int _Char_Img_Size_Y,
			int m_Sprite_Size_X, int m_Sprite_Size_Y);

	//현재 프레임 번호를 가져온다.
	int					m_GetFrameNum();

	//이미지를 다시 초기화 시켜주어야 할때 사용.
	void				m_SetImage(int _sizeX, int _sizeY,int _cntX, int _cntY);
	
	//특정 프레임으로 스프라이트 건너뛰기
	void				m_SetSprite(int cnt);
	bool				m_NextFrame(bool isLoop, float f_Speed);
	void				m_Set_Another_Frame(int Min, int Max);


	//애니메이션 플레이(애니메이션이 계속 된다면 참,마지막이라면 거짓을 반환)
	void				FrameMove(float f_Speed);
	//애니메이션이 계속 될것인지를 반환(반복 여부도 반영한다.무한반복이라면 언제나 참)
	virtual	bool		m_isFrameContinue();
	//현재 프레임이 마지막 프레임인지 확인.
	bool				m_isLastFrame();

	//현재 스프라이트 UV좌표
	float get_Now_Sprite_Pos_X();
	float get_Now_Sprite_Pos_Y();

	float get_m_Sprite_Pos_X();
	float get_m_Sprite_Pos_Y();


};
