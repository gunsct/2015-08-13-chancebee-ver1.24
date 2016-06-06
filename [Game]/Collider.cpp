#include "Collider.h"

Collider::Collider()
{
	Sectoin_Num = 0;
	LX_Size = RX_Size = UY_Size = DY_Size = 0.0f;
	L_Section = new list<Collider*>;
	Section_devide();
	g_FileLoader = FileLoader::getInstance();
}

Collider::Collider(int _section_num, float _lx_size, float _rx_size, float _uy_size, float _dy_size)
{
	Sectoin_Num = 0;
	Sectoin_Num = _section_num;
	LX_Size = _lx_size;
	RX_Size = _rx_size;
	UY_Size = _uy_size;
	DY_Size = _dy_size;
};

Collider::~Collider()
{
	delete L_Section;
};

void Collider::Section_devide()//100*100 크기의 맵에 5*5로 구역을 나눠 구역의 상하좌우 범위를 리스트 클래스를 이용해 순서대로 저장
{
	int _section_num = 0;
	float _lx_size = 0, _rx_size = 0, _uy_size = 0, _dy_size = 0;
	int interval = MAP_SIZE/SECTION;//20
	for(int i=1;i<SECTION+1;i++)
	{
		for(int j=1; j<SECTION+1;j++)
		{
			++_section_num;
			_lx_size = (i-(SECTION-2))*interval;
			_rx_size = (i-(SECTION-3))*interval;
			_uy_size = (j-(SECTION-3))*interval;
			_dy_size = (j-(SECTION-2))*interval;
			L_Section->push_back(new Collider(_section_num, _lx_size, _rx_size, _uy_size, _dy_size));
		}
	}

};

bool Collider::Section_Check_And_Collider(float Cvtx_xpos, float Cvtx_ypos, float Cvtx_LX_Size, float Cvtx_RX_Size, float Cvtx_UY_Size, float Cvtx_DY_Size)
{
	//우선 캐릭터를 어느섹션인지 찾자
	for(It_Section = L_Section->begin(); It_Section != L_Section->end(); It_Section++)
	{
		//특정 섹션 범위에 캐릭터가 있을시
		if(((*It_Section)->LX_Size <= Cvtx_xpos < (*It_Section)->RX_Size) && ((*It_Section)->UY_Size >= Cvtx_ypos > (*It_Section)->DY_Size))
		{
			//섹션 찾았으니 이제 그 섹션에 8방향 상하좌우 오브젝트랑 섹션이 겹치는게 있는지 판별
			for(It_Obj = g_FileLoader->L_MAP_IMG->begin(); It_Obj != g_FileLoader->L_MAP_IMG->end(); It_Obj++)
			{//섹션안에 오브젝트 있다면
				//if(((*It_Section)->LX_Size < (*It_Obj)->Return_Img_Xpos() < (*It_Section)->RX_Size) && ((*It_Section)->DY_Size < (*It_Obj)->Return_Img_Ypos() < (*It_Section)->UY_Size))
				{//캐릭터와 오브젝트간의 상하 위치판별

					if(Cvtx_xpos >= (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos <= (*It_Obj)->Return_Img_Ypos())//1상좌
					{
						if(Cvtx_LX_Size <= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_RXpos() && Cvtx_UY_Size >= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_DYpos())
							return false;
					}
					else if(Cvtx_xpos < (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos < (*It_Obj)->Return_Img_Ypos())//2상우
					{
						if(Cvtx_RX_Size >= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_LXpos() && Cvtx_UY_Size >= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_DYpos())
							return false;
					}
					else if(Cvtx_xpos > (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos > (*It_Obj)->Return_Img_Ypos())//3하좌
					{
						if(Cvtx_LX_Size <= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_RXpos() && Cvtx_DY_Size <= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_UYpos())
							return false;
					}
					else if(Cvtx_xpos <= (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos >= (*It_Obj)->Return_Img_Ypos())//4하우
					{
						if(Cvtx_RX_Size >= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_LXpos() && Cvtx_DY_Size <= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_UYpos())
							return false;
					}
					else return true;
				}
			}
				for(It_Obj = g_FileLoader->L_MAP_OBJ->begin(); It_Obj != g_FileLoader->L_MAP_OBJ->end(); It_Obj++)
			{//섹션안에 오브젝트 있다면
				//if(((*It_Section)->LX_Size < (*It_Obj)->Return_Img_Xpos() < (*It_Section)->RX_Size) && ((*It_Section)->DY_Size < (*It_Obj)->Return_Img_Ypos() < (*It_Section)->UY_Size))
				{//캐릭터와 오브젝트간의 상하 위치판별

					if(Cvtx_xpos >= (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos <= (*It_Obj)->Return_Img_Ypos())//1상좌
					{
						if(Cvtx_LX_Size <= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_RXpos() && Cvtx_UY_Size >= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_DYpos())
							return false;
					}
					else if(Cvtx_xpos < (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos < (*It_Obj)->Return_Img_Ypos())//2상우
					{
						if(Cvtx_RX_Size >= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_LXpos() && Cvtx_UY_Size >= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_DYpos())
							return false;
					}
					else if(Cvtx_xpos > (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos > (*It_Obj)->Return_Img_Ypos())//3하좌
					{
						if(Cvtx_LX_Size <= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_RXpos() && Cvtx_DY_Size <= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_UYpos())
							return false;
					}
					else if(Cvtx_xpos <= (*It_Obj)->Return_Img_Xpos() && Cvtx_ypos >= (*It_Obj)->Return_Img_Ypos())//4하우
					{
						if(Cvtx_RX_Size >= (*It_Obj)->Return_Img_Xpos() + (*It_Obj)->Return_Vtx_LXpos() && Cvtx_DY_Size <= (*It_Obj)->Return_Img_Ypos() + (*It_Obj)->Return_Vtx_UYpos())
							return false;
					}
					else return true;
				}
			}
			return true;
		}
	}
};
