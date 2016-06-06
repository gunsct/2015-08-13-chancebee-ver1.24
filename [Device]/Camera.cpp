#include "Camera.h"

Camera::Camera()
{
	_x = _y = 0.0f;
	_z = -5.01f;//ī�޶� ��ǥ �ʱ�ȭ
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

//ĳ�� 3�� �ִ� 3�� ��� ���� ������ �Ѱ� Ʈ�� �ٸ��� �����ϸ� �������� 2�� �����ǰ� �����Ѱ͸� Ʈ��
void Camera::Move_XY_Position(float &cx, float &cy)	//ĳ���� ��ġ�� ���� ī�޶� ��ġ�� �ٲ�� ����
{
	//if������ĳ�����϶�
	vEyePt = D3DXVECTOR3(cx, cy, _z);
	vLookatPt = D3DXVECTOR3(cx, cy, 1.0f);
	vUpVec = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);// ����� ����
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 2, 1.0f, 1.0f, 100.0f);//�þ߰� ����

}
void Camera::Move_Z_Position(float char_z_pos)//ĳ���� ���ð����ų� �� Ư�� �̺�Ʈ�� ĳ���� Ȯ���ɿ����� ������
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
	//XY������
	Move_XY_Position(x_pos, y_pos);

	//ī�޶� ������ �� ��ٸ� ����̽��� ������ ���ش�.
	(*g_pd3dDevice)->SetTransform(D3DTS_WORLD, &matWorld);//�������
	(*g_pd3dDevice)->SetTransform(D3DTS_VIEW, &matView);//�����
	(*g_pd3dDevice)->SetTransform(D3DTS_PROJECTION, &matProj);//�������� ���

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