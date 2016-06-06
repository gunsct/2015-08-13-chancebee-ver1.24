#include "Camera.h"

Camera::Camera()
{
	//D3DXMatrixIdentity(&m_matWorld);	//���� ��ǥ��
	//D3DXMatrixIdentity(&m_matScale);	//Ȯ��
	//D3DXMatrixIdentity(&m_matTran);	//��ġ ��ǥ��

	//D3DXMatrixIdentity(&vEyePt);	//���� ��ǥ��
	//D3DXMatrixIdentity(&vLookatPt);	//Ȯ��
	//D3DXMatrixIdentity(&vUpVec);	//��ġ ��ǥ��

	vEyePt = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vLookatPt = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	vUpVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	_x, _y, _z = 0.0f;
	On_vEyePt, On_vLookatPt, On_vUpVec = 0;


}

Camera::~Camera()
{

}


//void Camera::Set_Camera() //ī�޶� �ҷ����� ������ �Ϸ��� �߳�?
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

float Camera::Move_X_Position()	//�Ƹ��� ���� x�� �����Ѵ��� Ư��Ű ������ ���� ���� �Ϸ��� �߳�����.
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
	switch (WM_KEYDOWN)//�ϴ� � ī�޶� �������� ���Ѵ�!
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

	if (On_vEyePt == 1)//�� �ڿ� ������ ī�޶��� ������ �����Ѵ�!
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