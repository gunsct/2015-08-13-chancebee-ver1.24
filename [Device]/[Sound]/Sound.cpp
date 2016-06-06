//#include"DXUT.h"
#include "Sound.h"


Sound::Sound(void)
{
	//Bgm = irrklang::createIrrKlangDevice();
	//Bgm2 = irrklang::createIrrKlangDevice();
	for(int i = 0; i<BGM_SOUND_NUM ; i++)
		m_Bgm_Sound[i] = irrklang::createIrrKlangDevice();

	for(int i = 0; i<EFF_SOUND_NUM ; i++)
		m_Effect_Sound[i] = irrklang::createIrrKlangDevice();
}


//
void Sound::Play_BGM(int Num)
{
	//Bgm->setSoundVolume(0.1f);//���� ���� BGM ���߿� �����ϸ� �Ű������� �޾� BGM�� ���� �� �� �������̴�.
	//Bgm2->setSoundVolume(0.1f);
	//pSound[0]->play2D("[Music]\\��������.ogg",true);//���ѷ���
	//Bgm->play2D("[Music]\\��������.ogg");
	//Bgm2->play2D("[Music]\\Dead_Space_Twinkle_Twinkle_Little_Star_Boot_Traile.ogg");


	switch(Num)//�ٸ� bgm�� Ʋ�� ���ߴ°� ���� ���� ����
	{
	case 0:
		m_Bgm_Sound[0]->setSoundVolume(1.0f);
		m_Bgm_Sound[0]->play2D("[Game]\\[Music]\\Ice_Hole.ogg",true);
		break;
	}


}
void Sound::Play_Effcet(int Num)
{
	//if(m_Bgm_Sound[0]->isCurrentl    6yPlaying("��������.ogg") == true)
	{
		switch(Num)
		{
		case 0:
			m_Effect_Sound[0]->setSoundVolume(0.25f);//�Ҹ� ������. Ÿ�ϱ� �Ž������.
			m_Effect_Sound[0]->play2D("[Music]\\Boom.ogg");
			break;
		case 1:
			m_Effect_Sound[1]->setSoundVolume(0.25f);//�Ҹ� ������. Ÿ�ϱ� �Ž������.
			m_Effect_Sound[1]->play2D("[Music]\\razer.ogg");
		}
	}
}

void Sound::Change_Volume_Bgm(float vol)
{
	m_Effect_Sound[0]->setSoundVolume(vol);
}

void Sound::Change_Volume_Eff(int Num,float vol)
{
	m_Effect_Sound[Num]->setSoundVolume(vol);
}

void Sound::Check_Bgm()
{
	if(m_Effect_Sound[0]->isCurrentlyPlaying("[Music]\\���������¼Ҹ�1.ogg")==true || m_Effect_Sound[1]->isCurrentlyPlaying("[Music]\\���ڱ��Ҹ�.ogg")==true ||
		m_Effect_Sound[2]->isCurrentlyPlaying("[Music]\\Tristy_Walk.ogg")==true || m_Effect_Sound[3]->isCurrentlyPlaying("[Music]\\MentalGauge01.ogg")==true ||
		m_Effect_Sound[4]->isCurrentlyPlaying("[Music]\\MentalGauge03.ogg")==true || m_Effect_Sound[5]->isCurrentlyPlaying("[Music]\\MentalGauge03.ogg")==true
		)
		m_Bgm_Sound[0]->setSoundVolume(0.2f);

	else
		m_Bgm_Sound[0]->setSoundVolume(0.5f);

}
//���ϴ� ������ �ݺ������ְ� ������ ����ϴ� �Լ�
//�Ű����� 1�� �ݺ��� ���ϴ� ��ü�� �־��ְ� �Ű�����2�� ��ü�� ���� ���� �־��ش�.

void Sound::m_Sound_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename)
{
	char* temp_handle;
	temp_handle = (char*)p_filename.c_str();
	temp_Sound->play2D(temp_handle,true);
}

//�Ű����� 3�� �ݺ��� Ƚ��
void Sound::m_Sound_Lim_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename,int Num)
{
	char* temp_handle;
	temp_handle = (char*)p_filename.c_str();
	temp_Sound->play2D(temp_handle,Num);
}

void Sound::m_Eff_Stop(int temp_Sound)//���� ���� �迭�Է�//ĳ���� �Ϸ�Ǹ� ����� ���ѾߵǴϱ�..
{
	m_Effect_Sound[temp_Sound]->stopAllSounds();
}

Sound::~Sound(void)
{
}
