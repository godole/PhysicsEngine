#include "GraphicManager.h"

GraphicManager::GraphicManager()
{
}


GraphicManager::~GraphicManager()
{
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// ���� ���Ͻ���

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
	// ������ Ŭ������ ������ ����
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"D3D Tutorial", NULL
	};
	RegisterClassEx(&wc);

	// �����츦 ������
	hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 01: CreateDevice",
		WS_OVERLAPPEDWINDOW, 100, 100, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	// �����ְ� ������Ʈ�� �Ѵ�.
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	// D3D �ʱ�ȭ
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	// true�� â���, false�� ��üȭ��
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = 800;
	d3dpp.BackBufferHeight = 600;

	// ����̽� ����
	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);

	// ��������Ʈ�� ��Ʈ�� ����
	Create_Sprite();
	Create_Font();
}

void GraphicManager::Create_Sprite()
{
	// ��������Ʈ ����
	D3DXCreateSprite(g_pd3dDevice, &g_pSprite);
}

void GraphicManager::Create_Font()
{
	// ��Ʈ ����
	D3DXCreateFont(g_pd3dDevice, 30, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, NULL, NULL, NULL, "�������ü", &g_pFont);
}

void GraphicManager::RenderStart()
{
	// ȭ���� �����ϰ� �� ��, ����
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);
	g_pd3dDevice->BeginScene();
}

void GraphicManager::Render(GameObject* obj)
{
	// ������Ʈ�� Visible�� true�� ��쿡�� �׸���.
	if (obj->Visible == true)
	{
		// ������Ʈ�� ������
		RECT size;
		size.top = 0;
		size.left = 0;
		size.right = obj->GetSize().x;
		size.bottom = obj->GetSize().y;

		// ������Ʈ�� �������� �޴´�.
		// Radian���� ��ȯ�� ������ ȸ���� ����
		float Degree = D3DXToRadian(obj->Degree);

		// ��Ʈ���� ����
		D3DXMATRIX mat;

		// ȸ��, �̵�, ����, ������
		D3DXMATRIX Rot;
		D3DXMATRIX Trns;
		D3DXMATRIX Center;
		D3DXMATRIX Centerl;

		// ������ķ� �ʱ�ȭ
		D3DXMatrixIdentity(&mat);
		D3DXMatrixIdentity(&Rot);
		D3DXMatrixIdentity(&Trns);
		D3DXMatrixIdentity(&Center);
		D3DXMatrixIdentity(&Centerl);

		// Z���� �������� Degree�� ��ŭ ȸ��
		D3DXMatrixRotationZ(&Rot, Degree);

		// ����� ����
		D3DXMatrixInverse(&Centerl, NULL, &Center);

		// ���Ͱ��� �̵�(��ġ)���� ����
		D3DXMatrixTranslation(&Centerl, -obj->GetSize().x / 2, -obj->GetSize().y / 2, 0);
		D3DXMatrixTranslation(&Trns, obj->GetPos().x, obj->GetPos().y, 0);

		// ��ü ��Ʈ������ ������
		mat = Centerl * Rot * Center * Trns;

		// ����
		g_pSprite->SetTransform(&mat);

		g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

		// Render
		g_pSprite->Draw(obj->m_Texture, &size, NULL, NULL, 0xffffffff);

		g_pSprite->End();
	}
}

void GraphicManager::Draw_Text(string Text, int x, int y, D3DXCOLOR color)
{
	// ������ ����
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
	// ������ ����
	g_pd3dDevice->EndScene();
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GraphicManager::Release()
{
	// ����̽��� D3D, ��������Ʈ, ��Ʈ ����

	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();

	if (g_pD3D != NULL)
		g_pD3D->Release();

	if (g_pSprite != NULL)
		g_pSprite->Release();

	if (g_pFont != NULL)
		g_pFont->Release();
}