#pragma once
#include "..\[Device]\Define.h"
#include "..\[Game]\[Character]\Entity.h"//카메라가 캐릭터를 따라다니게 하려면 캐릭터 좌표가 필요
//그에 해당하는 카메라의 x,y,z축을 움직인다.

class Camera
{
private:
	//싱글톤
	static bool instanceFlag;
	static Camera *instance;
	
	//멤버변수
	float _x, _y, _z; //카메라 x, y, z축 설정용
	Camera();

public:

	virtual ~Camera()
	{
		instanceFlag = false;
	}

	static Camera *getInstance();

	D3DXMATRIXA16 matWorld;
	D3DXVECTOR3 vEyePt;
	D3DXVECTOR3 vLookatPt;
	D3DXVECTOR3 vUpVec;
	D3DXMATRIXA16 matView;
	D3DXMATRIXA16 matProj;

	bool _object_stat[5];//캐릭터별로 카메라 좌표 이동위해 상태를 끄고 킬고함

	/*캐릭터를 움직이는 버튼을 누른다
	모든 캐릭터 카메라 상태를 false로 하고 해당 캐릭터만 true한다
	if 해당 캐릭터 true일때
	move camera
	이렇게 해야지 각 캐릭터 움직일때 카메라가 왔다리갔다리안하고 해당 캐릭터에만 따라다니겠지
	*/
	void Move_Camera();
	void Move_XY_Position(float &x, float &y);
	void Move_Z_Position(float char_z);//이 캐릭터 선택됬을시에 확대되는 개념으로 써야하나

	void All_Off_Camera();//모든 캐릭터 카메라 상태 끄기

	void Final_Camera(LPDIRECT3DDEVICE9 *g_pd3dDevice, float x_pos, float y_pos);

	void Singleton_Realese();
};