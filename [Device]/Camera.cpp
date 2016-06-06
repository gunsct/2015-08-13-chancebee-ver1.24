#include "Camera.h"

Camera::Camera()
{
	_x = _y = 0.0f;
	_z = -5.01f;//카메라 좌표 초기화
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&matView);
	D3DXMatrixIdentity(&matProj);
	vEyePt = D3DXVECTOR3(_x, _y, _z);
	vLookatPt = D3DXVECTOR3(_x, _y, 1.0f);
	vUpVec = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
}

bool Camera::instanceFlag = false;
Camera* Camera::instance = NULL;

Camera *Camera::getInstance()
{

	if(!instance){
		instance = new Camera();
		instanceFlag = true;
	}
	return instance;
}


void Camera::Move_Camera()
{
	
}

//캐릭 3개 있다 3개 모두 폴스 움직일 한개 트루 다른거 선택하면 ㄴ나머지 2개 폴스되고 선택한것만 트루
void Camera::Move_XY_Position(float &cx, float &cy)	//캐릭터 위치에 따라 카메라 위치도 바뀌게 설정
{
	//if찬스비캐릭터일때
	vEyePt = D3DXVECTOR3(cx, cy, _z);
	vLookatPt = D3DXVECTOR3(cx, cy, 1.0f);
	vUpVec = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);// 뷰행렬 생성
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 2, 1.0f, 1.0f, 100.0f);//시야각 정의

}
void Camera::Move_Z_Position(float char_z_pos)//캐릭터 선택같은거나 뭐 특정 이벤트시 캐릭터 확대기능용으로 쓸거임
{
	_z = char_z_pos;
}

void Camera::All_Off_Camera()
{
	for (int i = 0; i < 5; i++)
	{
		_object_stat[i] = false;
	}
}

void Camera::Final_Camera(LPDIRECT3DDEVICE9 *g_pd3dDevice, float x_pos, float y_pos)
{
	//XY포지션
	Move_XY_Position(x_pos, y_pos);

	//카메라 세팅이 다 됬다면 디바이스에 세팅을 해준다.
	(*g_pd3dDevice)->SetTransform(D3DTS_WORLD, &matWorld);//월드행렬
	(*g_pd3dDevice)->SetTransform(D3DTS_VIEW, &matView);//뷰행렬
	(*g_pd3dDevice)->SetTransform(D3DTS_PROJECTION, &matProj);//프로젝션 행렬

}

void Camera :: Singleton_Realese()
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