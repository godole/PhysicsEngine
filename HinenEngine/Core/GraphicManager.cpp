#include "GraphicManager.h"

GraphicManager::GraphicManager()
{
}


GraphicManager::~GraphicManager()
{
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// 메인 프록시저

	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void GraphicManager::Init()
{
	// 윈도우 클래스를 생성후 적용
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"D3D Tutorial", NULL
	};
	RegisterClassEx(&wc);

	// 윈도우를 생성후
	hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 01: CreateDevice",
		WS_OVERLAPPEDWINDOW, 100, 100, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	// 보여주고 업데이트를 한다.
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	// D3D 초기화
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	// true면 창모드, false면 전체화면
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;

	// 디바이스 생성
	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);

	// 스프라이트와 폰트를 생성
	Create_Sprite();
	Create_Font();
}

void GraphicManager::Create_Sprite()
{
	// 스프라이트 생성
	D3DXCreateSprite(g_pd3dDevice, &g_pSprite);
}

void GraphicManager::Create_Font()
{
	// 폰트 생성
	D3DXCreateFont(g_pd3dDevice, 30, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, NULL, NULL, NULL, "맑은고딕체", &g_pFont);
}

void GraphicManager::RenderStart()
{
	// 화면을 깨끗하게 한 후, 시작
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	g_pd3dDevice->BeginScene();
}

void GraphicManager::Render(GameObject* obj)
{
	// 오브젝트의 Visible이 true일 경우에만 그린다.
	if (obj->Visible == true)
	{
		// 오브젝트의 사이즈
		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = obj->GetSize().x;
		size.bottom = obj->GetSize().y;

		// 오브젝트의 각도값을 받는다.
		// Radian으로 변환한 이유는 회전을 위해
		float Degree = D3DXToRadian(obj->Degree);

		// 메트릭스 선언
		D3DXMATRIX mat;

		// 회전, 이동, 센터, 역센터
		D3DXMATRIX Rot;
		D3DXMATRIX Trns;
		D3DXMATRIX Center;
		D3DXMATRIX Centerl;

		// 단위행렬로 초기화
		D3DXMatrixIdentity(&mat);
		D3DXMatrixIdentity(&Rot);
		D3DXMatrixIdentity(&Trns);
		D3DXMatrixIdentity(&Center);
		D3DXMatrixIdentity(&Centerl);

		// Z축을 기준으로 Degree값 만큼 회전
		D3DXMatrixRotationZ(&Rot, Degree);

		// 역행렬 적용
		D3DXMatrixInverse(&Centerl, NULL, &Center);

		// 센터값과 이동(위치)값을 적용
		D3DXMatrixTranslation(&Centerl, -obj->GetSize().x / 2, -obj->GetSize().y / 2, 0);
		D3DXMatrixTranslation(&Trns, obj->GetPos().x, obj->GetPos().y, 0);

		// 전체 메트릭스에 곱한후
		mat = Centerl * Rot * Center * Trns;

		// 적용
		g_pSprite->SetTransform(&mat);

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		g_pSprite->Draw(obj->m_Texture, &size, NULL, NULL, 0xffffffff);

		g_pSprite->End();
	}
}

void GraphicManager::Draw_Text(string Text, int x, int y, D3DXCOLOR color)
{
	// 사이즈 정의
	RECT size;
	size.top = y;
	size.left = x;
	size.right = 0;
	size.bottom = 0;

	g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	// Render
	g_pFont->DrawTextA(g_pSprite, Text.c_str(), -1, &size, DT_NOCLIP, color);

	g_pSprite->End();
}

void GraphicManager::RenderEnd()
{
	// 끝낸후 해제
	g_pd3dDevice->EndScene();
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GraphicManager::Release()
{
	// 디바이스와 D3D, 스프라이트, 폰트 해제

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();

	if (g_pSprite != NULL)
		g_pSprite->Release();

	if (g_pFont != NULL)
		g_pFont->Release();
}