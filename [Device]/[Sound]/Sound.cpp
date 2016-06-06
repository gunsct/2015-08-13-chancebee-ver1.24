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
	//Bgm->setSoundVolume(0.1f);//현재 메인 BGM 나중에 발전하면 매개변수를 받아 BGM도 선택 할 수 있을것이다.
	//Bgm2->setSoundVolume(0.1f);
	//pSound[0]->play2D("[Music]\\얼음연못.ogg",true);//무한루프
	//Bgm->play2D("[Music]\\얼음연못.ogg");
	//Bgm2->play2D("[Music]\\Dead_Space_Twinkle_Twinkle_Little_Star_Boot_Traile.ogg");


	switch(Num)//다른 bgm을 틀때 멈추는건 아직 구현 안함
	{
	case 0:
		m_Bgm_Sound[0]->setSoundVolume(1.0f);
		m_Bgm_Sound[0]->play2D("[Game]\\[Music]\\Ice_Hole.ogg",true);
		break;
	}


}
void Sound::Play_Effcet(int Num)
{
	//if(m_Bgm_Sound[0]->isCurrentl    6yPlaying("얼음연못.ogg") == true)
	{
		switch(Num)
		{
		case 0:
			m_Effect_Sound[0]->setSoundVolume(0.25f);//소리 꺼놨다. 타일깔때 거슬릴까봐.
			m_Effect_Sound[0]->play2D("[Music]\\Boom.ogg");
			break;
		case 1:
			m_Effect_Sound[1]->setSoundVolume(0.25f);//소리 꺼놨다. 타일깔때 거슬릴까봐.
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
	if(m_Effect_Sound[0]->isCurrentlyPlaying("[Music]\\유리깨지는소리1.ogg")==true || m_Effect_Sound[1]->isCurrentlyPlaying("[Music]\\발자국소리.ogg")==true ||
		m_Effect_Sound[2]->isCurrentlyPlaying("[Music]\\Tristy_Walk.ogg")==true || m_Effect_Sound[3]->isCurrentlyPlaying("[Music]\\MentalGauge01.ogg")==true ||
		m_Effect_Sound[4]->isCurrentlyPlaying("[Music]\\MentalGauge03.ogg")==true || m_Effect_Sound[5]->isCurrentlyPlaying("[Music]\\MentalGauge03.ogg")==true
		)
		m_Bgm_Sound[0]->setSoundVolume(0.2f);

	else
		m_Bgm_Sound[0]->setSoundVolume(0.5f);

}
//원하는 음악을 반복시켜주고 싶을때 사용하는 함수
//매개변수 1은 반복을 원하는 객체를 넣어주고 매개변수2는 객체의 파일 명을 넣어준다.

void Sound::m_Sound_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename)
{
	char* temp_handle;
	temp_handle = (char*)p_filename.c_str();
	temp_Sound->play2D(temp_handle,true);
}

//매개변수 3은 반복할 횟수
void Sound::m_Sound_Lim_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename,int Num)
{
	char* temp_handle;
	temp_handle = (char*)p_filename.c_str();
	temp_Sound->play2D(temp_handle,Num);
}

void Sound::m_Eff_Stop(int temp_Sound)//멈출 사운드 배열입력//캐스팅 완료되면 종료는 시켜야되니깐..
{
	m_Effect_Sound[temp_Sound]->stopAllSounds();
}

Sound::~Sound(void)
{
}
