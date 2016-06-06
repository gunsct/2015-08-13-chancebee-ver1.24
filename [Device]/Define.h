#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <math.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#include <stdlib.h>
#pragma warning( default : 4996 )

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

//#pragma comment(lib, "winmm.lib")
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1|D3DFVF_TEXCOORDSIZE2(0))
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define D3DPTFILTERCAPS_MINFANISOTROPIC // ���漺 ���͸�

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)//0x0001�� �ϸ� �ѹ��� �����°�
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)//0x8000�̸� �ٿ� ������ �ٹ���

#define KEY_DOWN_ONE_CLICK(vk_code) ((GetAsyncKeyState(vk_code) & 0x0001) ? 1 : 0)//0x0001�� �ϸ� �ѹ��� �����°�
#define KEY_UP_ONE_CLICK(vk_code) ((GetAsyncKeyState(vk_code) & 0x0001) ? 0 : 1)//0x8000�̸� �ٿ� ������ �ٹ���

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	640
#define MAP_SIZE 100 //�� ũ��
#define SECTION 5 //���� ��


#define DRAW_MENU_NUM		3//�޴�
#define DRAW_MAP_NUM		100//��
#define DRAW_CHAR_NUM		5

#define ENEMY_NUM 3//��Ʋ������ �� �������
#define SKILL_NUM 4//��ų�� �����

enum e_Situation{ MENU, MAP, BATTLE, INTRO};
enum e_Key_Input{ MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, SPACE, ESC, NUM1, NUM2, NUM3, NUM4};
enum e_Type{ MAP_IMG, MAP_OBJ, NPC, CHRECTER}; 
enum e_UI_Type{ UI_MAP, UI_BATTLE}; 
enum e_Select_Char_Menu{S_M_UP, S_M_DOWN, S_M_LEFT, S_M_RIGHT, S_M_NOTHING};