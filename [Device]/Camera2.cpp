#include "Camera.h"

Camera::Camera()
{
	//D3DXMatrixIdentity(&m_matWorld);	//월드 좌표계
	//D3DXMatrixIdentity(&m_matScale);	//확대
	//D3DXMatrixIdentity(&m_matTran);	//위치 좌표계

	//D3DXMatrixIdentity(&vEyePt);	//월드 좌표계
	//D3DXMatrixIdentity(&vLookatPt);	//확대
	//D3DXMatrixIdentity(&vUpVec);	//위치 좌표계

	vEyePt = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vLookatPt = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vUpVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	_x, _y, _z = 0.0f;
	On_vEyePt, On_vLookatPt, On_vUpVec = 0;


}

Camera::~Camera()
{

}


//void Camera::Set_Camera() //카메라 불러오기 같은걸 하려고 했나?
//{
//	//vEyePt = {0.0f, 0.0f, 0.0f};
// //   vLookatPt = (0.0f, 0.0f, 0.0f);
// //   vUpVec = (0.0f, 0.0f, 0.0f);
//	_x, _y, _z = 0.0f;
//
//	//D3DXVECTOR3 vEyePt(0.0f, 0.0f, 0.0f);
// //   D3DXVECTOR3 vLookatPt(0.0f, 0.0f, 0.0f);
// //   D3DXVECTOR3 vUpVec(0.0f, 0.0f, 0.0f);
//
//}

float Camera::Move_X_Position()	//아마도 나는 x값 조절한다음 특정키 넣으면 값이 들어가게 하려고 했나보다.
{
	_x += 0.1f;
	return _x;
}

float Camera::Move_Y_Position()
{
	_y += 0.1f;
	return _y;
}

float Camera::Move_Z_Position()
{
	_z += 0.1f;
	return _z;
}

void Camera::Set_vEyePt(float x, float y, float z)
{
	vEyePt = D3DXVECTOR3(x, y, z);
}

void Camera::Set_vLookatPt(float x, float y, float z)
{
	vLookatPt = D3DXVECTOR3(x, y, z);
}

void Camera::Set_vUpVec(float x, float y, float z)
{
	vUpVec = D3DXVECTOR3(x, y, z);
}

void Camera::Move_Camera()
{
	switch (WM_KEYDOWN)//일단 어떤 카메라를 움직일지 정한다!
	{
	case 'P':
		On_vEyePt = 1;
		On_vLookatPt = 0;
		On_vUpVec = 0;
		break;

	case '[':
		On_vEyePt = 0;
		On_vLookatPt = 1;
		On_vUpVec = 0;
		break;

	case ']':
		On_vEyePt = 0;
		On_vLookatPt = 0;
		On_vUpVec = 1;
		break;
	}

	if (On_vEyePt == 1)//그 뒤에 움직일 카메라의 변수를 조절한다!
	{
		Set_vEyePt(_x, _y, _z);
	}

	if (On_vLookatPt == 1)
	{
		Set_vLookatPt(_x, _y, _z);
	}

	if (On_vUpVec == 1)
	{
		Set_vUpVec(_x, _y, _z);
	}

}

//void Camera::SetupCamera()
//{
//	vEyePt
//		vLookatPt
//		vUpVec
//		Set_vUpVec
//}