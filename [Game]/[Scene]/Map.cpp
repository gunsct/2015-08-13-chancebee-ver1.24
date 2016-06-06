#include "Map.h"

Map::Map(void)
{
	c_ChanceBee = new Char_ChanceBee;
}


Map::~Map(void)
{
}
//걸음 걸을때마다 
bool Map::Rand_Contact()
{	
	int ct_num;
	for(int i=1;i<=50;i++)
	{//대충 한계치가 50단계라고 하면
		ct_num = rand()%(500/i);//제어하기 위해 변수에 담음
		if(moving_cnt < i && moving_cnt >= i-1)
		{
			//걸음 수가 단계에 해당하면 배틀씬 돌입 확률을 정한다 0.2% = 1/500 0.4% = 1/250 if(rand()&250 == 1 이면 된거로 
			if(ct_num == 1) 
			{
				ct_num = 0;//이거 안해주면 맵가자마자 다시 1인거 읽어와서 다시 들어옴
				return true;
			}
		}
	}
	return false;
}