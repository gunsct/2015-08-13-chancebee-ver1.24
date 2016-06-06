#include "Menu.h"


Menu::Menu(void)
{
	c_Scene_Manager = Scene_Manager::getInstance();
}


Menu::~Menu(void)
{
}


void Menu :: GameStart()
{
	//게임 초반부 씬으로 이동시킬것.	
	c_Scene_Manager->Change_Scene(MAP);
}

void Menu :: GameLoad()
{
	//게임 저장과 로드 구현시키는 코드 가져올것.
}

void Menu :: GameOption()
{
	//소리 설정.. 밝기... 한번 해볼까.
}

void Menu :: GameExit()
{
	//게임 끌것.
	exit(0);
}
	
//메뉴의 키입력을 받는다.
void Menu :: Menu_Control(int &x_pos, int &y_pos)
{
	if (KEY_DOWN_ONE_CLICK(VK_UP))
      y_pos += 1;
 
	if (KEY_DOWN_ONE_CLICK(VK_DOWN))
      y_pos -= 1;

	if (KEY_DOWN_ONE_CLICK(VK_LEFT))
      x_pos -= 1;
 
	if (KEY_DOWN_ONE_CLICK(VK_RIGHT))
      x_pos += 1;

   //이 아래는 메뉴가 끝까지 내려가거나 위로 끝까지 올라가면 다시 밑에서부터 시작하게 해준다.
   if(y_pos>0)
      y_pos = (-3);

   if(y_pos<-3)
      y_pos = 0;

   Menu_Open(x_pos,y_pos);

   if(KEY_DOWN(VK_ESCAPE))
   exit(0);
}


//메뉴를 연다
void Menu::Menu_Open(int &x_pos, int &y_pos)
{
	if(KEY_DOWN(VK_RETURN))
	{
		
		//밥먹고 와서 스위치문 고치는것부터 시작
		switch(y_pos)
		{
			std::cout << y_pos << std::endl;
			//게임 시작
		case 0:
			GameStart();
			break;

			//불러오기
		case -1:
			GameLoad();
			break;

			//옵션
		case -2:
			GameOption();
			break;

			//끝내기
		case -3:
			GameExit();
			break;
		}
	}

}

