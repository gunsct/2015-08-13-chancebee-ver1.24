#include "D3Ddevice.h"

D3Ddevice::D3Ddevice()
{
	g_pD3D = NULL; // Used to create the D3DDevice
	g_pd3dDevice = NULL; // Our rendering device

	c_Camera = Camera :: getInstance();
	c_Scene_Manager = Scene_Manager::getInstance();
}



D3Ddevice::~D3Ddevice()
{
}

VOID D3Ddevice::D3D_Render()
{
    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 100, 100 ), 1.0f, 0 );

	//���������� Ȯ���Ϸ��� �̹����� ȸ���ϰ��־���.
//	D3DXMATRIXA16 matWorld_1;
//UINT iTime2 = timeGetTime() % 2000;
//    FLOAT fAngle2 = -(iTime2 * ( 2.0f * D3DX_PI ) / 2000.0f);
//    D3DXMatrixRotationY( &matWorld_1, fAngle2 );
//    g_pd3dDevice->SetTransform( D3DTS_WORLD, &matWorld_1 );

	m_Render.Final_Render(&g_pd3dDevice);

	m_FPS.Draw_FPS();
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}




