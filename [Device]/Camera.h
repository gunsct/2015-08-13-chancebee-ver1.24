#pragma once
#include "..\[Device]\Define.h"
#include "..\[Game]\[Character]\Entity.h"//ī�޶� ĳ���͸� ����ٴϰ� �Ϸ��� ĳ���� ��ǥ�� �ʿ�
//�׿� �ش��ϴ� ī�޶��� x,y,z���� �����δ�.

class Camera
{
private:
	//�̱���
	static bool instanceFlag;
	static Camera *instance;
	
	//�������
	float _x, _y, _z; //ī�޶� x, y, z�� ������
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

	bool _object_stat[5];//ĳ���ͺ��� ī�޶� ��ǥ �̵����� ���¸� ���� ų����

	/*ĳ���͸� �����̴� ��ư�� ������
	��� ĳ���� ī�޶� ���¸� false�� �ϰ� �ش� ĳ���͸� true�Ѵ�
	if �ش� ĳ���� true�϶�
	move camera
	�̷��� �ؾ��� �� ĳ���� �����϶� ī�޶� �Դٸ����ٸ����ϰ� �ش� ĳ���Ϳ��� ����ٴϰ���
	*/
	void Move_Camera();
	void Move_XY_Position(float &x, float &y);
	void Move_Z_Position(float char_z);//�� ĳ���� ���É����ÿ� Ȯ��Ǵ� �������� ����ϳ�

	void All_Off_Camera();//��� ĳ���� ī�޶� ���� ����

	void Final_Camera(LPDIRECT3DDEVICE9 *g_pd3dDevice, float x_pos, float y_pos);

	void Singleton_Realese();
};