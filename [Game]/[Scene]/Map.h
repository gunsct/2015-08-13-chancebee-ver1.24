#pragma once
#include "..\..\[Device]\Define.h"
#include "..\[Character]\Char_ChanceBee.h"
#include <time.h>
#include <math.h>

class Map
{//����.. ��..�� ���� �迭��ġ�� ���� �����ϰ� �����ϰ� �Ź� �ٸ� �ű⿡ �����Ÿ��� ������ ��Ʋ������ ��ȯ�ȴ�. 
	//��ǥ �� 25*25�� ����� �� ���� �������� �����Ҵ��ؼ� �׸�ŭ�̶� ���ϰ� �ؾ��ҵ�
public:
	
	Map(void);
	~Map(void);

	Char_ChanceBee *c_ChanceBee;

	bool Rand_Contact();
};