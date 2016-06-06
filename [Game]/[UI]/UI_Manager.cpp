#include "UI_Manager.h"

bool UI_Manager::InstanceFlag = false;
UI_Manager* UI_Manager::Instance = NULL;
bool UI_Manager::Change_Chk = false;

UI_Manager::UI_Manager(void)
{
	c_Scene_Manager = Scene_Manager::getInstance();
	

	c_UI_Map = new UI_Map();
	c_UI_Battle = new UI_Battle();
}

UI_Manager :: UI_Manager(LPDIRECT3DDEVICE9* pd3dDevice)
{
	c_Scene_Manager = Scene_Manager::getInstance();
	

	c_UI_Map = new UI_Map(*pd3dDevice);
	c_UI_Battle = new UI_Battle(*pd3dDevice);

}

UI_Manager* UI_Manager::getInstance(LPDIRECT3DDEVICE9* pd3dDevice)
{
	if(!Instance)
	{
		Instance = new UI_Manager(pd3dDevice);
		InstanceFlag = true;
	}
	return Instance;
}

void UI_Manager :: Singleton_Realese()
{
	if(Instance != NULL)
	{
		if(InstanceFlag ==true)
		{
			InstanceFlag = false;
			delete Instance;
			Instance = NULL;
		}
	}
}

void UI_Manager :: Present_UI(e_Situation m_Situation, LPDIRECT3DDEVICE9* pd3dDevice)
{
	if(Change_Chk == false)
	{
		switch(m_Situation)
		{
		case MAP:
			//SAFE_DELETE(c_UI_Battle);
			//if(c_UI_Map == NULL)
			//{
			//	c_UI_Map = new UI_Map(*pd3dDevice);
			//}
			c_UI_Map->Final_UI_Map(pd3dDevice);
			break;

		case BATTLE:
			c_UI_Battle->Final_UI_Battle(pd3dDevice);
			//SAFE_DELETE(c_UI_Map);
			break;
		}
	}
}