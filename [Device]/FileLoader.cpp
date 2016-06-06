#include "FileLoader.h"

bool FileLoader::InstanceFlag = false;
FileLoader* FileLoader::Instance = NULL;

FileLoader* FileLoader::getInstance(){
	if(!Instance)
	{
		Instance = new FileLoader();
		InstanceFlag = true;
	}
	return Instance;
}
FileLoader::FileLoader()
{
	Object_Num = Type = Type_Kinds = XSize = YSize = 0;
	Img_Xpos = Img_Ypos = Img_Zpos = Vtx_RX_Size = Vtx_LX_Size = Vtx_UY_Size = Vtx_DY_Size = 0.0f;

	L_MAP_IMG = new list<FileLoader*>;
	L_MAP_OBJ = new list<FileLoader*>;
	L_NPC = new list<FileLoader*>;
	L_CHRECTER = new list<FileLoader*>;

	Load_Pos();
}

FileLoader::FileLoader(int Type_Num,float _posX, float _posY, int _sizeX, int _sizeY, float _vtx_lx, float _vtx_rx, float _vtx_uy, float _vtx_dy, string _root)
{
	Type = Type_Num;
	Img_Xpos = _posX;
	Img_Ypos = _posY;
	XSize = _sizeX;
	YSize = _sizeY;
	Vtx_LX_Size = _vtx_lx;
	Vtx_RX_Size = _vtx_rx;
	Vtx_UY_Size = _vtx_uy;
	Vtx_DY_Size = _vtx_dy;
	Root = _root;
}

FileLoader::~FileLoader()
{
	SAFE_DELETE(L_MAP_IMG);
	SAFE_DELETE(L_MAP_OBJ);
	SAFE_DELETE(L_NPC);
	SAFE_DELETE(L_CHRECTER);
	InstanceFlag = false;
}

void FileLoader::Load_Pos()
{
	Map.open("[Image]\\Image_Pos.txt");
	Map.seekg(65,ios::beg);//바이트 단위로 커서 옮김
    while(!Map.eof()){
            Map >> Object_Num >>Type >> Type_Kinds >> Img_Xpos >> Img_Ypos >> Vtx_LX_Size >> Vtx_RX_Size >> Vtx_UY_Size >> Vtx_DY_Size >> XSize >> YSize >> Root;
			cout << Object_Num << Type << Type_Kinds << Img_Xpos << Img_Ypos << XSize << YSize << Vtx_LX_Size << Vtx_RX_Size << Vtx_UY_Size << Vtx_DY_Size << Root << endl;
			Add_Object(Type, Img_Xpos, Img_Ypos, XSize, YSize, Vtx_LX_Size, Vtx_RX_Size, Vtx_UY_Size, Vtx_DY_Size, Root);
    }
    Map.close(); 
}
//MAP_IMG 0, MAP_OBJ 1, NPC 2, CHRECTER 3

void FileLoader::Add_Object(int Type_Num,float _posX, float _posY,int _sizeX,int _sizeY, float _vtx_lx, float _vtx_rx, float _vtx_uy, float _vtx_dy, string _root)
{
	switch(Type_Num)
	{
		case MAP_IMG://0
			L_MAP_IMG->push_back(new FileLoader(Type_Num, _posX, _posY, _sizeX, _sizeY, _vtx_lx, _vtx_rx, _vtx_uy, _vtx_dy, _root));
			break;

		case MAP_OBJ://1
			L_MAP_OBJ->push_back(new FileLoader(Type_Num, _posX, _posY, _sizeX, _sizeY, _vtx_lx, _vtx_rx, _vtx_uy, _vtx_dy, _root));
			break;

		case NPC://2
			L_NPC->push_back(new FileLoader(Type_Num, _posX, _posY, _sizeX, _sizeY, _vtx_lx, _vtx_rx, _vtx_uy, _vtx_dy, _root));
			break;

		case CHRECTER://3
			L_CHRECTER->push_back(new FileLoader(Type_Num, _posX, _posY, _sizeX, _sizeY, _vtx_lx, _vtx_rx, _vtx_uy, _vtx_dy, _root));
			break;
	}
}

void FileLoader::Init()
{
	It_MAP_IMG = L_MAP_IMG->begin();
	It_MAP_OBJ = L_MAP_OBJ->begin();
	It_NPC = L_NPC->begin();
	It_CHRECTER = L_CHRECTER->begin();
}

float FileLoader::Return_Img_Xpos()
{
	return Img_Xpos;
}

float FileLoader::Return_Img_Ypos()
{
	return Img_Ypos;
}

int FileLoader::Return_XSize()
{
	return XSize;
}

int FileLoader::Return_YSize()
{
	return YSize;
}
float FileLoader::Return_Vtx_LXpos()
{
	return Vtx_LX_Size;
}

float FileLoader::Return_Vtx_RXpos()
{
	return Vtx_RX_Size;
}

float FileLoader::Return_Vtx_UYpos()
{
	return Vtx_UY_Size;
}

float FileLoader::Return_Vtx_DYpos()
{
	return Vtx_DY_Size;
}

string FileLoader::Return_Root()
{
	return Root;
}