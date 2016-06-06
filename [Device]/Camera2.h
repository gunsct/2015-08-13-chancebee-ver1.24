#pragma once
#include "Define.h"
#include "Entity.h"//ī�޶� ĳ���͸� ����ٴϰ� �Ϸ��� ĳ���� ��ǥ�� �ʿ�
//�Ӹ��� �� �ȵ��Ƽ� ������ �����غ���� �ߴ�.
//�ϴ� ����� ī�޶� ���Ѵ�. Ű�� P,[,]
//�׿� �ش��ϴ� ī�޶��� x,y,z���� �����δ�.

class Camera
{
private:
	//D3DXMATRIXA16 m_matWorld;	//���� ��ǥ�� //�� ��û�ΰ� �Ѥ�;
	//D3DXMATRIXA16 m_matScale;	//Ȯ��		  //�̰� ������Ʈ �ű���� ���� ������ ī�޶� �����̷��� �Ѱ� �ƴϴ�
	//D3DXMATRIXA16 m_matTran;	//��ġ ��ǥ��


	D3DXMATRIXA16 vmatView;
	D3DXVECTOR3 vEyePt;
	D3DXVECTOR3 vLookatPt;
	D3DXVECTOR3 vUpVec;

	float _x, _y, _z; //ī�޶� x, y, z�� ������
	bool	On_vEyePt, On_vLookatPt, On_vUpVec;

	int Gey_Key;

public:
	Camera();
	~Camera();

	//void Set_Camera();

	float Move_X_Position();
	float Move_Y_Position();
	float Move_Z_Position();//�� ĳ���� ���É����ÿ� Ȯ��Ǵ� �������� ����ϳ�


	void Set_vEyePt(float x, float y, float z);
	void Set_vLookatPt(float x, float y, float z);
	void Set_vUpVec(float x, float y, float z);


	void Move_Camera();

	void SetupCamera();
};