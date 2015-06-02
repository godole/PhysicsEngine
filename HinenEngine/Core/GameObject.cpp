#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject()
{
	// ������ 0��, 0������, Visible�� true�� ����
	Degree = 0;
	Ani_Now = 0;
	Visible = true;

	m_Pos.x = 0;
	m_Pos.y = 0;
}


GameObject::~GameObject()
{
}

void GameObject::Init(string path)
{
	Load_Texture(path);
}

void GameObject::Load_Texture(string path)
{
	// �ؽ��� Ŭ�������� �ؽ��ĸ� �ҷ��´�
	m_Texture = TextureManager::GetInstance()->Load_Texture(path);
}

void GameObject::SetSize(int x, int y)
{
	// ũ�� ������ x, y���� ���Ѵ�
	m_Size.x = x;
	m_Size.y = y;
}

void GameObject::SetPos(int x, int y)
{
	// ��ġ ������ x, y���� ���Ѵ�
	m_Pos.x = x;
	m_Pos.y = y;
}

void GameObject::SetSize(D3DXVECTOR2 size)
{
	m_Size = size;
}

void GameObject::SetPos(D3DXVECTOR2 pos)
{
	m_Pos = pos;
}

D3DXVECTOR2 GameObject::GetSize()
{
	return m_Size;
}

D3DXVECTOR2 GameObject::GetPos()
{
	return m_Pos;
}

bool GameObject::Animation(string path, int Frame, float Delay)
{
	// ���� ����ð� - ����Ƚð��� �����̺��� ũ��
	if (GetTickCount() - Ani_Time >= Delay)
	{
		// ����ð��� ���� �ð��� �����Ѵ�
		Ani_Time = GetTickCount();

		// ���� ���� �������� ��ǥ �����Ӱ� ���ٸ�
		if (Ani_Time == Frame)
		{
			// ���� �������� 0���� �ְ�
			Ani_Now = 0;

			// �ð� �ʱ�ȭ
			Ani_Time = 0;

			// true���� �����Ѵ�.
			return true;
		}

		// ���� �������� �ϳ� �ø���
		Ani_Now++;
		path += to_string((_Longlong)Ani_Now);
		path += ".png";

		// �ؽ��ĸ� �ҷ����� �ٲ۴�.
		Load_Texture(path);
	}

	// �ִϸ��̼��� ���� �ƴ϶�� false�� ����
	return false;
}