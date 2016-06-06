#include "Sprite.h"

Sprite::Sprite(void)
{
}

Sprite::~Sprite(void)
{
}

Sprite::Sprite(int _Char_Img_Size_X, int _Char_Img_Size_Y,
			int _Sprite_Size_X, int _Sprite_Size_Y)
{
	m_Sprite_Size_X = _Sprite_Size_X;
	m_Sprite_Size_Y = _Sprite_Size_Y;

	m_Img_Size_X = _Char_Img_Size_X;
	m_Img_Size_Y = _Char_Img_Size_Y;

	m_Sprite_Pos_X = (1.0f/(float)m_Sprite_Size_X);
	m_Sprite_Pos_Y = (1.0f/(float)m_Sprite_Size_Y);

	//프레임은 맨 왼쪽 위를 1로 해준다.
	//0으로 초기화 하면 %를 연산할때 에러가 나거든..

	m_Frame_Min = 1;
	m_Frame_Max = m_Sprite_Size_X * m_Sprite_Size_Y;
	m_Frame_Num = m_Frame_Min;

	m_Now_Sprite_Pos_X = m_Sprite_Pos_X/2.0f;
	m_Now_Sprite_Pos_Y = m_Sprite_Pos_Y/2.0f;
}





int		Sprite::m_GetFrameNum()
{
	return m_Frame_Num;
}


void	Sprite::m_SetImage(int _sizeX, int _sizeY,int _cntX, int _cntY)
{
	m_Img_Size_X = _sizeX;
	m_Img_Size_Y = _sizeY;

	m_Sprite_Pos_X = (1.0f/(float)m_Sprite_Size_X);
	m_Sprite_Pos_Y = (1.0f/(float)m_Sprite_Size_Y);

	m_Now_Sprite_Pos_X = m_Sprite_Pos_X/2;
	m_Now_Sprite_Pos_Y = m_Sprite_Pos_Y/2;

	m_Sprite_Size_X = _cntX;
	m_Sprite_Size_Y = _cntY;

	m_Frame_Num = m_Frame_Min;
	m_Frame_Max = m_Sprite_Size_X * m_Sprite_Size_Y ;
	m_Frame_Num = m_Frame_Min;
}




void Sprite::m_SetSprite(int cnt)
{

	//현재 프레임 번호가 최대 번호에 다다르면
	//현재 프레임을 1로 초기화하고 UV좌표의 y를 초기화시킨다.
	if(m_Frame_Num >= m_Frame_Max)
	{
		m_Frame_Num = m_Frame_Min;
		m_Now_Sprite_Pos_X = m_Sprite_Pos_X/2.0f;
		m_Now_Sprite_Pos_Y = ( (m_Sprite_Pos_Y) * ((float)m_Frame_Max/ (float)m_Sprite_Size_X) ) - (m_Sprite_Pos_Y/2.0f);
	}

	//프레임 번호가 우측 끝에 다다르지 않았다면 uv의 x좌표를 증가.
	if((m_Frame_Num % m_Sprite_Size_X) > 0)
	{
	m_Now_Sprite_Pos_X += m_Sprite_Pos_X;
	++m_Frame_Num;
	}

	else if((m_Frame_Num - ((m_Sprite_Size_X) * (m_Frame_Max/m_Sprite_Size_X)) ) != 0)
	{
	m_Now_Sprite_Pos_X += m_Sprite_Pos_X;
	++m_Frame_Num;
	}

	//아니라면 y좌표를 증가시켜준다.
	else
	{
		m_Now_Sprite_Pos_X = m_Sprite_Pos_X/2.0f;
		m_Now_Sprite_Pos_Y += m_Sprite_Pos_Y;
		++m_Frame_Num;
	}
}


/*-------------------------------------------------------------------*/
bool Sprite::m_NextFrame(bool isLoop, float f_Speed)
{

		static DWORD frameCount = 0;            //프레임 카운트수
	static float timeElapsed = 0.0f;            //흐른 시간
	static DWORD lastTime = timeGetTime();   //마지막 시간(temp변수)

	DWORD curTime = timeGetTime();      //현재 시간
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.

	timeElapsed += timeDelta; 
	frameCount++;

	if( timeElapsed >= f_Speed )         //흐른시간이 1초이상이면 내가 하고싶은것 처리
	{
		frameCount = 0;
		timeElapsed = 0.0f;
	


	//반복 여부 반환
	//마지막 프레임이면 거짓, 아니라면 참을 반환
	//무한 루프일경우 무조건 참을 반환
	if(!isLoop)
	{
		if(m_Frame_Num >= m_Frame_Max-1)
		{
			m_SetSprite(m_Frame_Num);
			return false;
		}
		else 
		{
			m_SetSprite(++m_Frame_Num);
			return true;
		}
	}
	else 
	{
		m_SetSprite(m_Frame_Num);
	}

	}

		else
	{
		//흐른 시간이 1초가 안되면 생략함  
		//Sleep() 해도되고 안해도 되구~ 
	} 

	lastTime = curTime;
}


void Sprite::FrameMove(float f_Speed)
{
	m_NextFrame(true, f_Speed);
}


void Sprite::m_Set_Another_Frame(int Min, int Max)
{
	m_Frame_Min = Min;
	m_Frame_Max = Max;
	m_Frame_Num = m_Frame_Min;

	m_Now_Sprite_Pos_X = m_Sprite_Pos_X/2.0f;

	m_Now_Sprite_Pos_Y = ( (m_Sprite_Pos_Y) * ((float)m_Frame_Max/ (float)m_Sprite_Size_X) ) - (m_Sprite_Pos_Y/2.0f);
}



bool Sprite::m_isFrameContinue()
{
	return true;
}

bool Sprite::m_isLastFrame()
{
	if(m_Frame_Num >= m_Frame_Max-1)
		return true;
	else
		return false;
}


float Sprite::get_Now_Sprite_Pos_X()
{
	return m_Now_Sprite_Pos_X;
}

float Sprite::get_Now_Sprite_Pos_Y()
{
	return m_Now_Sprite_Pos_Y;
}

float Sprite::get_m_Sprite_Pos_X()
{
	return m_Sprite_Pos_X/2;
}

float Sprite::get_m_Sprite_Pos_Y()
{
	return m_Sprite_Pos_Y/2;
}
