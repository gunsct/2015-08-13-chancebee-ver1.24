#pragma once
#pragma comment(lib,"irrKlang.lib")
#include <irrKlang.h>
#include <iostream>
#define BGM_SOUND_NUM	1
#define EFF_SOUND_NUM	2
class Sound
{
private:
	irrklang::ISoundEngine *m_Bgm_Sound[BGM_SOUND_NUM];
	irrklang::ISoundEngine *m_Effect_Sound[EFF_SOUND_NUM];


public:
	Sound(void);
	~Sound(void);

	//사운드 플레이
	void Play_BGM(int Num);
	void Play_Effcet(int Num);

	//볼륨 바꾸기
	void Change_Volume_Bgm(float vol);
	void Change_Volume_Eff(int Num,float vol);

	//효과음 재생중이면 bgm을 줄이는 함수
	//프레임 랜더에 넣어주면 매 프레임마다 체크시켜준다.
	void Check_Bgm();

	//사운드 루프.. 제작중
	void m_Sound_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename);
	void m_Sound_Lim_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename,int Num);

	//루프되는 사운드 정지
	//매개변수에 재생 시키고 있는 사운드의 번호를 넣어주면 정지
	void m_Eff_Stop(int temp_Sound);
};

