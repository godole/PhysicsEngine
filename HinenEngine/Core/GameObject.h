//////////////////////////////////////////////////////////////
///////////////////  ���� ������Ʈ Ŭ����  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

class GameObject
{
public :
	virtual void Init(string path);

public:
	GameObject();
	~GameObject();

public:
	// ������Ʈ�� ������ �־�� �� ��

	// �ؽ���, ������, ��ġ, ����, Visible
	LPDIRECT3DTEXTURE9	m_Texture;
	D3DXVECTOR2			m_Size;
	D3DXVECTOR2			m_Pos;
	float				Degree;
	bool				Visible;

	// �ִϸ��̼��� ���� ��
	// ���� �� ����������, üũ�� ���� �ð�
	int					Ani_Now;
	float				Ani_Time;


	// �޼���
	// �ؽ��� �ҷ�����
	void Load_Texture(string path);

	// ������� ��ġ ����
	void SetSize(int x, int y);
	virtual void SetPos(int x, int y);
	virtual void SetSize(D3DXVECTOR2 size);
	virtual void SetPos(D3DXVECTOR2 pos);

	// ������� ��ġ ��������
	D3DXVECTOR2 GetSize();
	D3DXVECTOR2 GetPos();

	// �ִϸ��̼�
	bool Animation(string path, int Frame, float Delay);

};

