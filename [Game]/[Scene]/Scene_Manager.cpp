#include "Scene_Manager.h"


bool Scene_Manager::instanceFlag = false;
Scene_Manager* Scene_Manager::instance = NULL;


Scene_Manager *Scene_Manager::getInstance()
{

	if(!instance){
		instance = new Scene_Manager();
		instanceFlag = true;	
	}

	return instance;
}


void Scene_Manager :: Singleton_Realese()
{
	if(instance != NULL)
	{
		if(instanceFlag ==true)
		{
			instanceFlag = false;
			delete instance;
			instance = NULL;
		}
	}

}


//¾À Ã¼ÀÎÁö
void Scene_Manager::Change_Scene(e_Situation p_Situation)
{
	m_Situation = p_Situation;
}

//ÇöÀç ¹«½¼ ¾ÀÀÎÁö ¾Ë·ÁÁØ´Ù
e_Situation Scene_Manager::Present_Scene()
{
	return m_Situation;
}



void Scene_Manager:: Battle_get_Instance()
{
	c_Battle = Battle::getInstance();
}





void Scene_Manager::Render_Select(LPDIRECT3DDEVICE9* pd3dDevice)
{
   Chk_Scene_Init(*pd3dDevice);

   if( SUCCEEDED( (*pd3dDevice)->BeginScene() ) )
   {

      switch(Present_Scene())
      {
      case MENU:
		   c_Camera->Move_Z_Position(-5.0f);
         Final_Menu_Render(pd3dDevice);
         break;

      case MAP:
         if(b_Menu_Scene_Chk == true)
         {
			 c_Camera->Move_Z_Position(-10.0f);
            SAFE_DELETE(c_Menu_Scene);
            b_Menu_Scene_Chk = false;
         }


         if(c_Map->Rand_Contact() == true)
         {
           
            if(tm.Timer_Set(1.0f) == true)
            {
				Change_Scene(BATTLE);
				c_Camera->Move_Z_Position(-8.0f);
			}
            
         }
         Final_Map_Render(pd3dDevice);   
         break;

      case BATTLE:
         if(b_Menu_Scene_Chk == true)
         {
            SAFE_DELETE(c_Menu_Scene);
            b_Menu_Scene_Chk = false;
         }

         if(c_Battle->out_battle() == true)
         {
            c_Battle->Init();
            c_Camera->Move_Z_Position(-10.0f);
            Change_Scene(MAP);
         }

         Final_Battle_Render(pd3dDevice);
         break;


      case INTRO:
         break;
      }

      (*pd3dDevice)->EndScene();
   }
}


void Scene_Manager::Init_Map_Scene(IDirect3DDevice9* pd3dDevice)
{
	c_Map_Scene = new Map_Scene();
	c_Map_Scene->Registed_Texture(pd3dDevice);
}

void Scene_Manager::Init_Menu_Scene(IDirect3DDevice9* pd3dDevice)
{
	c_Menu_Scene = new Menu_Scene();
	c_Menu_Scene->Registed_Texture(pd3dDevice);
}

void Scene_Manager::Init_Battle_Scene(IDirect3DDevice9* pd3dDevice)
{
	c_Battle = Battle::getInstance();
	c_Battle_Scene = new Battle_Scene();
	c_Battle_Scene->Registed_Texture(pd3dDevice);
}

void Scene_Manager::Init_Intro(IDirect3DDevice9* pd3dDevice)
{
	c_Intro = new Intro();
	c_Intro->Registed_Texture(pd3dDevice);
}

void Scene_Manager::Final_Map_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	c_Map_Scene->Final_Map_Scene(pd3dDevice);
}

void Scene_Manager::Final_Menu_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	c_Menu_Scene->Final_Menu_Scene(pd3dDevice);
}

void Scene_Manager::Final_Battle_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	c_Battle_Scene->Final_Battle_Scene(pd3dDevice);
}

void Scene_Manager::Final_Intro_Render(LPDIRECT3DDEVICE9* pd3dDevice)
{
	c_Intro->Final_Intro(pd3dDevice);
}

void Scene_Manager::Del_Map_Scene()
{
	SAFE_DELETE(c_Map_Scene);
}
void Scene_Manager::Del_Menu_Scene()
{
	SAFE_DELETE(c_Menu_Scene);
}

void Scene_Manager::Del_Battle_Scene()
{
	SAFE_DELETE(c_Battle_Scene);
}

void Scene_Manager::Del_Intro()
{
	SAFE_DELETE(c_Intro);
}



void Scene_Manager::Chk_Scene_Init(IDirect3DDevice9* pd3dDevice)
{
	switch(Present_Scene())
	{
	case MAP : 
		if(b_Map_Scene_Chk == false)
		{
			b_Map_Scene_Chk = true;
			//c_Camera->Move_Z_Position(-5.0f);
			Init_Map_Scene(pd3dDevice);
		}

		break;

	case MENU : 
		
		if(b_Menu_Scene_Chk == false)
		{
			b_Menu_Scene_Chk = true;
			//c_Camera->Move_Z_Position(-10.0f);
			Init_Menu_Scene(pd3dDevice);
		}
		break;

	case BATTLE : 
		if(b_Battle_Scene_Chk == false)
		{
			Battle_get_Instance();
			//c_Camera->Move_Z_Position(-10.0f);
			b_Battle_Scene_Chk = true;
			Init_Battle_Scene(pd3dDevice);
		}

		break;

	case INTRO : 
		if(b_Intro_Chk == false)
		{
			b_Intro_Chk = true;
			Init_Intro(pd3dDevice);
		}
		break;

	}
}