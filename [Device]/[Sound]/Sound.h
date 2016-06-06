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

	//���� �÷���
	void Play_BGM(int Num);
	void Play_Effcet(int Num);

	//���� �ٲٱ�
	void Change_Volume_Bgm(float vol);
	void Change_Volume_Eff(int Num,float vol);

	//ȿ���� ������̸� bgm�� ���̴� �Լ�
	//������ ������ �־��ָ� �� �����Ӹ��� üũ�����ش�.
	void Check_Bgm();

	//���� ����.. ������
	void m_Sound_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename);
	void m_Sound_Lim_Loop(irrklang::ISoundEngine *temp_Sound,std::string p_filename,int Num);

	//�����Ǵ� ���� ����
	//�Ű������� ��� ��Ű�� �ִ� ������ ��ȣ�� �־��ָ� ����
	void m_Eff_Stop(int temp_Sound);
};

