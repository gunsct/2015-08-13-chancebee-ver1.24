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
	//���� �ʹݺ� ������ �̵���ų��.	
	c_Scene_Manager->Change_Scene(MAP);
}

void Menu :: GameLoad()
{
	//���� ����� �ε� ������Ű�� �ڵ� �����ð�.
}

void Menu :: GameOption()
{
	//�Ҹ� ����.. ���... �ѹ� �غ���.
}

void Menu :: GameExit()
{
	//���� ����.
	exit(0);
}
	
//�޴��� Ű�Է��� �޴´�.
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

   //�� �Ʒ��� �޴��� ������ �������ų� ���� ������ �ö󰡸� �ٽ� �ؿ������� �����ϰ� ���ش�.
   if(y_pos>0)
      y_pos = (-3);

   if(y_pos<-3)
      y_pos = 0;

   Menu_Open(x_pos,y_pos);

   if(KEY_DOWN(VK_ESCAPE))
   exit(0);
}


//�޴��� ����
void Menu::Menu_Open(int &x_pos, int &y_pos)
{
	if(KEY_DOWN(VK_RETURN))
	{
		
		//��԰� �ͼ� ����ġ�� ��ġ�°ͺ��� ����
		switch(y_pos)
		{
			std::cout << y_pos << std::endl;
			//���� ����
		case 0:
			GameStart();
			break;

			//�ҷ�����
		case -1:
			GameLoad();
			break;

			//�ɼ�
		case -2:
			GameOption();
			break;

			//������
		case -3:
			GameExit();
			break;
		}
	}

}

