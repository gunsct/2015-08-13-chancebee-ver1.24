#include "Map.h"

Map::Map(void)
{
	c_ChanceBee = new Char_ChanceBee;
}


Map::~Map(void)
{
}
//���� ���������� 
bool Map::Rand_Contact()
{	
	int ct_num;
	for(int i=1;i<=50;i++)
	{//���� �Ѱ�ġ�� 50�ܰ��� �ϸ�
		ct_num = rand()%(500/i);//�����ϱ� ���� ������ ����
		if(moving_cnt < i && moving_cnt >= i-1)
		{
			//���� ���� �ܰ迡 �ش��ϸ� ��Ʋ�� ���� Ȯ���� ���Ѵ� 0.2% = 1/500 0.4% = 1/250 if(rand()&250 == 1 �̸� �Ȱŷ� 
			if(ct_num == 1) 
			{
				ct_num = 0;//�̰� �����ָ� �ʰ��ڸ��� �ٽ� 1�ΰ� �о�ͼ� �ٽ� ����
				return true;
			}
		}
	}
	return false;
}