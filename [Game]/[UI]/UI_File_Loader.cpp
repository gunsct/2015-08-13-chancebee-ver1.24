#include "UI_File_Loader.h"


bool UI_File_Loader::InstanceFlag = false;
UI_File_Loader* UI_File_Loader::Instance = NULL;


UI_File_Loader::UI_File_Loader(void)
{
	Object_Num = Type = Type_Kinds = XSize = YSize = 0;
	Img_Xpos = Img_Ypos = 0.0f;

	L_UI_MAP_IMG = new list<UI_File_Loader*>;
	L_UI_BATTLE_IMG = new list<UI_File_Loader*>;

	L_temp_UI_MAP_IMG = new list<UI_File_Loader*>;
	L_temp_UI_BATTLE_IMG = new list<UI_File_Loader*>;
}


UI_File_Loader::~UI_File_Loader(void)
{
	SAFE_DELETE(L_UI_MAP_IMG);
	SAFE_DELETE(L_UI_BATTLE_IMG);

	InstanceFlag = false;
}

UI_File_Loader::UI_File_Loader(int _Type_Kinds, int _XSize, int _YSize, float Img_Xpos, float Img_Ypos, string _Root)
{
	Type_Kinds = _Type_Kinds;

	XSize = _XSize;
	YSize = _YSize;

	Img_Xpos = Img_Xpos;
	Img_Ypos = Img_Ypos;

	Root = _Root;
}

UI_File_Loader *UI_File_Loader::getInstance()
{
	if(!Instance){
		Instance = new UI_File_Loader();
		InstanceFlag = true;
	}
	return Instance;
}

void UI_File_Loader::Load_File()
{
	UI_txt.open("[Game]\\[UI]\\UI_File.txt");

	while(!UI_txt.eof())
	{
		UI_txt >> Object_Num >> Type >> Type_Kinds >> XSize >> YSize >> Img_Xpos >> Img_Ypos >> Root;
		Add_UI(Type, Type_Kinds, Img_Xpos, Img_Ypos, XSize, YSize, Root);
	}

}

//여기부터 다시 시작
void UI_File_Loader::Add_UI(int _Type, int _Type_Kinds, int _XSize, int _YSize, float _Img_Xpos, float _Img_Ypos, string _Root)
{
	switch(_Type)
	{
	case UI_MAP:
		L_UI_MAP_IMG->push_back(new UI_File_Loader(_Type_Kinds, _XSize, _YSize, _Img_Xpos, _Img_Ypos, _Root));
		break;

	case UI_BATTLE:
		L_UI_BATTLE_IMG->push_back(new UI_File_Loader(_Type_Kinds, _XSize, _YSize, _Img_Xpos, _Img_Ypos, _Root));
		break;
	}
}

list<UI_File_Loader*> UI_File_Loader::get_UI_MAP()
{
	return *L_temp_UI_MAP_IMG;
}

list<UI_File_Loader*> UI_File_Loader::get_UI_BATTLE()
{
	return *L_temp_UI_BATTLE_IMG;
}

void UI_File_Loader::Reload_UI_MAP()
{
	L_temp_UI_MAP_IMG = L_UI_MAP_IMG;
}

void UI_File_Loader::Reload_UI_BATTLE()
{
	L_UI_BATTLE_IMG = L_temp_UI_BATTLE_IMG;
}

