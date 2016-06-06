#pragma once
#include "..\..\[Device]\Define.h"
#include "..\[Character]\Char_ChanceBee.h"
#include <time.h>
#include <math.h>

class Map
{//맵은.. 음..어 랜덤 배열위치에 적이 투명하게 존재하고 매번 다름 거기에 직선거리로 닿으면 배틀씬으로 전환된다. 
	//좌표 한 25*25로 만들고 적 수를 랜덤으로 동적할당해서 그만큼이랑 비교하게 해야할듯
public:
	
	Map(void);
	~Map(void);

	Char_ChanceBee *c_ChanceBee;

	bool Rand_Contact();
};