#include "D3Ddevice.h"

HRESULT D3Ddevice::InitD3D( HWND hWnd )
{
    if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

    if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice ) ) )
    {
        return E_FAIL;
    }

	
	//랜더의 초기화를 여기서 실행시켜준다.
	m_FPS.Create_Font(&g_pd3dDevice);
	m_Render.Init_Render(&g_pd3dDevice);
	//c_Sound.Play_BGM(0);
	
	// Turn off culling, so we see the front and back of the triangle
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);//
	g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);//
	g_pd3dDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);//



	g_pd3dDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );//
	g_pd3dDevice->SetRenderState( D3DRS_ZENABLE, TRUE );
	g_pd3dDevice->SetRenderState( D3DRS_LIGHTING, FALSE );
	
	g_pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER,D3DTEXF_ANISOTROPIC);
    g_pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER,D3DTEXF_ANISOTROPIC);
    g_pd3dDevice->SetSamplerState(0, D3DSAMP_MIPFILTER,D3DTEXF_ANISOTROPIC);
    return S_OK;
}



VOID D3Ddevice::Cleanup()
{

	if( g_pd3dDevice != NULL )
        g_pd3dDevice->Release();

    if( g_pD3D != NULL )
        g_pD3D->Release();

	c_Scene_Manager->Singleton_Realese();
	c_Camera->Singleton_Realese();
}




