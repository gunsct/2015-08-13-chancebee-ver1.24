#pragma once
#include "Define.h"
#include "Entity.h"//카메라가 캐릭터를 따라다니게 하려면 캐릭터 좌표가 필요
//머리가 잘 안돌아서 설명을 정리해보기로 했다.
//일단 사용할 카메라를 정한다. 키는 P,[,]
//그에 해당하는 카메라의 x,y,z축을 움직인다.

class Camera
{
private:
	//D3DXMATRIXA16 m_matWorld;	//월드 좌표계 //나 멍청인가 ㅡㅡ;
	//D3DXMATRIXA16 m_matScale;	//확대		  //이건 오브젝트 옮기려고 만든 변수지 카메라를 움직이려고 한게 아니다
	//D3DXMATRIXA16 m_matTran;	//위치 좌표계


	D3DXMATRIXA16 vmatView;
	D3DXVECTOR3 vEyePt;
	D3DXVECTOR3 vLookatPt;
	D3DXVECTOR3 vUpVec;

	float _x, _y, _z; //카메라 x, y, z축 설정용
	bool	On_vEyePt, On_vLookatPt, On_vUpVec;

	int Gey_Key;

public:
	Camera();
	~Camera();

	//void Set_Camera();

	float Move_X_Position();
	float Move_Y_Position();
	float Move_Z_Position();//이 캐릭터 선택됬을시에 확대되는 개념으로 써야하나


	void Set_vEyePt(float x, float y, float z);
	void Set_vLookatPt(float x, float y, float z);
	void Set_vUpVec(float x, float y, float z);


	void Move_Camera();

	void SetupCamera();
};