#include "Battle.h"


bool Battle :: instanceFlag = false;
Battle *Battle :: instance = NULL;

Battle *Battle::getInstance()
{

	if(!instance){
		instance = new Battle();
		instanceFlag = true;	
	}

	return instance;
}

void Battle :: Singleton_Realese()
{
	if(instance != NULL)
	{
		if(instanceFlag ==true)
		{
			instanceFlag = false;
			delete instance;
			instance = NULL;

			SAFE_DELETE(c_B_ChanceBee);
		}

	}

}

Battle::Battle(void)
{
	c_Scene_Manager = Scene_Manager::getInstance();
	c_B_ChanceBee = new B_Char_ChanceBee(1, 2, 944	, 2288	, 4, 4);
	c_UI_Text_Battle = UI_Text_Battle::getInstance();

	b_Selected_Char = false;
	b_Select_Battle_Menu_Attack = false;
	b_Select_Battle_Menu_Item = false;
	b_Select_Battle_Menu_ECT = false;

	m_Selected_Char_Menu = S_M_NOTHING;


	//define에서 enemy_num 같은걸로 설정할것 변수로 하던가..
	for(int i=0;i<ENEMY_NUM;i++)
	{
		c_B_Enemy[i] = new B_Enemy(5-i,-2+2*i,1,1,500,400, 5, 4);
		c_B_Enemy[i]->Attack_Stat = false;
		c_B_Enemy[i]->HP = 10;
	}

	s_slash[0] = new Skill(1,4,30);
	s_slash[1] = new Skill(2,1,20);
	s_slash[2] = new Skill(3,3,25);
	s_slash[3] = new Skill(4,5,40);
	s_slash[4] = new Skill(5,8,60);

	Sebu_Menu_y_pos = 0;
}




void Battle :: Select_Char()
{

	if(KEY_DOWN_ONE_CLICK('R'))
	{
		if(c_Scene_Manager->Present_Scene() == BATTLE)
		{
			b_Selected_Char = 1-b_Selected_Char;
			//캐릭터 선택(화살표로 보여준다던가 이런거)

			//선택된 캐릭터의 행동
			Sebu_Menu_y_pos = 0;
		}
	}
	else
	{}

	if(b_Selected_Char == true)
		Act_Char();

	if(b_Selected_Char == false)
		m_Selected_Char_Menu = S_M_NOTHING;
}


void Battle :: Act_Char()
{

	if(b_Select_Battle_Menu_Attack == false && b_Select_Battle_Menu_Item == false && b_Select_Battle_Menu_ECT == false)
	{
		if(KEY_DOWN(VK_UP))
		{
			m_Selected_Char_Menu = S_M_UP;
		}

		else if(KEY_DOWN(VK_DOWN))
		{
			m_Selected_Char_Menu = S_M_DOWN;
		}

		else if(KEY_DOWN(VK_LEFT))
		{
			m_Selected_Char_Menu = S_M_LEFT;
		}

		else if(KEY_DOWN(VK_RIGHT))
		{
			m_Selected_Char_Menu = S_M_RIGHT;
		}

	}


	else if(KEY_DOWN(VK_ESCAPE))
	{
		m_Selected_Char_Menu = S_M_NOTHING;
		Sebu_Menu_y_pos = 0;
	}
}

int Battle :: Battle_Sebu_Menu()
{
	if(b_Select_Battle_Menu_Attack == true || b_Select_Battle_Menu_Item == true || b_Select_Battle_Menu_ECT == true)
	{

		if(KEY_DOWN_ONE_CLICK(VK_UP))
		{
			if(Sebu_Menu_y_pos <= 0)
				Sebu_Menu_y_pos = 100;

			else
				Sebu_Menu_y_pos -= 25;
		}

		else if(KEY_DOWN_ONE_CLICK(VK_DOWN))
		{
			if(Sebu_Menu_y_pos >= 100)
				Sebu_Menu_y_pos = 0;

			else
				Sebu_Menu_y_pos += 25;
		}

		if(KEY_DOWN(VK_RETURN))
		{
			if(tm.Timer_Set(0.5f) == true)
				Battle_Sebu_Menu_Select();
		}

		return Sebu_Menu_y_pos;
	}

}

void Battle :: Battle_Sebu_Menu_Select()
{
	switch((int)Sebu_Menu_y_pos)
	{
	case 0 :
		if(c_B_ChanceBee->TP > 30)
		{
			if(b_Select_Battle_Menu_Attack == true)
			{
				c_B_ChanceBee->b_Play_(true);
				if(c_B_ChanceBee->b_Play_() == true)
				{
					for(int i=0;i<ENEMY_NUM;i++)
					{	
						c_B_ChanceBee->Attack(c_B_Enemy[i]);
					}
				}

				c_B_ChanceBee->TP -= 30;

				b_Select_Battle_Menu_Attack = false;
				b_Selected_Char = false;
			}
		}
		break;
	}

}

void Battle :: Char_Move()
{//시작하면 조금씩 다가온다 tp빠지면 뒤로 빼는것도 있고
	static float expos[ENEMY_NUM];
	for(int i=0;i<ENEMY_NUM;i++)
	{
		//티피없을때 뒤로 빠지는걸 고려해서 티피 일정수치 있고 에너미랑 플레이어 거리가 어느정도 이상이면 그까지 조금씩 다가온다.
		if(c_B_Enemy[i]->TP > 50 && c_B_Enemy[i]->x_pos - c_B_ChanceBee->x_pos > 3)
		{
			if(c_B_ChanceBee->x_pos < -1.5f)//플레이어 최대전진거리 고정
				c_B_ChanceBee->x_pos += 0.01f;

			c_B_Enemy[i]->x_pos -= 0.01f;

			expos[i] = c_B_Enemy[i]->x_pos;//이건 다가오는동안의 좌표를 저장해주고 공격할때 상대방에 찍고 다시 빼기위한 좌표다
		}

		if(c_B_Enemy[i]->TP <= 50)//티피가 일정치 이하이면 충전하는동안 뒤로 무르는것
			c_B_Enemy[i]->x_pos += 0.02f;

		if(c_B_Enemy[i]->Attack_Stat == true && c_B_Enemy[i]->TP > 50)//티피가 일정치 이상이면서 공격상태일때 상대방을 찍고
		{
			c_B_Enemy[i]->x_pos = c_B_ChanceBee->x_pos+0.5f;
		}

		if(c_B_Enemy[i]->Attack_Stat == false && c_B_Enemy[i]->TP > 50)//티피가 일정치 이상이면서 비공격상태일때 원래자리로 온다.
			c_B_Enemy[i]->x_pos = expos[i];

	}
}

void Battle :: Char_Attack()
{
	//cout << "Attack" <<endl;
	//캐릭터 공격
}



//키입력을 받는다.
void Battle :: Char_Control()
{
	c_B_ChanceBee->Movement();
	c_B_ChanceBee->Repair_TP(0.3f);

	Char_Attack();
	Char_Move();

	if(tm.Timer_Set(1)==true)
	{
		Enemy_Attack();
		if(tm2.Timer_Set(0.5)==true)
			for(int i=0;i<ENEMY_NUM;i++)
				c_B_Enemy[i]->Attack_Stat = false;
	}

	Select_Char();
}

void Battle :: Enemy_Attack()
{//적이 초단위로 자동공격하며 티피도 회복함 공격은 랜덤으로 한다
	for(int i=0;i<ENEMY_NUM;i++)
	{	
		c_B_Enemy[i]->Repair_TP(10);//타이머 초마다 티피 회복
		if ((c_B_Enemy[i]->TP >= 50) && (c_B_ChanceBee->HP) > 0 && (3.5 > c_B_Enemy[i]->x_pos - c_B_ChanceBee->x_pos) && (c_B_Enemy[i]->x_pos - c_B_ChanceBee->x_pos > 2.5))
		{//일정 거리내 플레이어 피통 존재하고 에너미 티피 일정치 이상이면 공격한다.
			c_B_Enemy[i]->Attack_Stat = true;//공격상태

			int skn = rand() % SKILL_NUM;//랜덤으로 스킬을 골라서 공격

			c_B_ChanceBee->Change_HP(s_slash[skn]->Return_Damage());

			c_B_Enemy[i]->Change_TP(s_slash[skn]->Return_TimePoint());

			cout<< "char_HP" << c_B_ChanceBee->HP << ",en_TP " << i << ", " << c_B_Enemy[i]->TP <<endl;
		}
		else 
			c_B_Enemy[i]->Attack_Stat = false;//비공격상태
	}
}

void Battle :: Enemy_Control()
{
	if(tm.Timer_Set(1.0f)==true)
	{
		Enemy_Attack();
		if(tm2.Timer_Set(0.5f)==true)
			for(int i=0;i<ENEMY_NUM;i++)
				c_B_Enemy[i]->Attack_Stat = false;
	}
}

void Battle::Init()
{
	for(int i=0; i<ENEMY_NUM; i++)
		c_B_Enemy[i]->Init(5-i,-2+2*i);
	c_B_ChanceBee->Init(-3,0);

	m_Selected_Char_Menu = S_M_NOTHING;
}


B_Enemy Battle::get_Enemy(int i)
{
	switch(i)
	{
	case 0:
		return *c_B_Enemy[0];
		break;

	case 1:
		return *c_B_Enemy[1];
		break;

	case 2:
		return *c_B_Enemy[2];
		break;
	}
}

B_Char_ChanceBee Battle::get_ChanceBee()
{
	return *c_B_ChanceBee;
}

bool Battle::get_Selected_Char()
{
	return b_Selected_Char;
}

e_Select_Char_Menu Battle::get_Slected_Char_Menu()
{
	return m_Selected_Char_Menu;
}

bool Battle::out_battle()
{
	int cnt=0;
	for(int i=0;i<ENEMY_NUM;i++)
		if(get_Enemy(i).HP <= 0) cnt++;

	if(get_ChanceBee().HP <= 0 || cnt == ENEMY_NUM) 
		if(tm3.Timer_Set(1.0f) == true)
			return true;

	return false;
}		

void Battle::Final_Battle()
{
	Battle_Sebu_Menu();
	Char_Control();	
	Enemy_Control();
}