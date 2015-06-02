//////////////////////////////////////////////////////////////
////////////////////  �׷��� ���� Ŭ����  ////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include "GameObject.h"

using namespace std;

class GraphicManager : public CSingleton<GraphicManager>
{
public:
	GraphicManager();
	~GraphicManager();

public:
	LPDIRECT3D9         g_pD3D;
	LPDIRECT3DDEVICE9   g_pd3dDevice;
	LPD3DXSPRITE		g_pSprite;
	LPD3DXFONT			g_pFont;
	WNDCLASSEX			wc;
	HWND				hWnd;

	// �ʱ�ȭ�� ����, Render, ����
	void Init();
	void Create_Sprite();
	void Create_Font();
	void RenderStart();
	void Render(GameObject* obj);
	void Draw_Text(string Text, int x, int y, D3DXCOLOR color);
	void RenderEnd();
	void Release();
};

