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

	//�������� �� ���� ���� 1�� ���ش�.
	//0���� �ʱ�ȭ �ϸ� %�� �����Ҷ� ������ ���ŵ�..

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

	//���� ������ ��ȣ�� �ִ� ��ȣ�� �ٴٸ���
	//���� �������� 1�� �ʱ�ȭ�ϰ� UV��ǥ�� y�� �ʱ�ȭ��Ų��.
	if(m_Frame_Num >= m_Frame_Max)
	{
		m_Frame_Num = m_Frame_Min;
		m_Now_Sprite_Pos_X = m_Sprite_Pos_X/2.0f;
		m_Now_Sprite_Pos_Y = ( (m_Sprite_Pos_Y) * ((float)m_Frame_Max/ (float)m_Sprite_Size_X) ) - (m_Sprite_Pos_Y/2.0f);
	}

	//������ ��ȣ�� ���� ���� �ٴٸ��� �ʾҴٸ� uv�� x��ǥ�� ����.
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

	//�ƴ϶�� y��ǥ�� ���������ش�.
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

		static DWORD frameCount = 0;            //������ ī��Ʈ��
	static float timeElapsed = 0.0f;            //�帥 �ð�
	static DWORD lastTime = timeGetTime();   //������ �ð�(temp����)

	DWORD curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.

	timeElapsed += timeDelta; 
	frameCount++;

	if( timeElapsed >= f_Speed )         //�帥�ð��� 1���̻��̸� ���� �ϰ������ ó��
	{
		frameCount = 0;
		timeElapsed = 0.0f;
	


	//�ݺ� ���� ��ȯ
	//������ �������̸� ����, �ƴ϶�� ���� ��ȯ
	//���� �����ϰ�� ������ ���� ��ȯ
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
		//�帥 �ð��� 1�ʰ� �ȵǸ� ������  
		//Sleep() �ص��ǰ� ���ص� �Ǳ�~ 
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
