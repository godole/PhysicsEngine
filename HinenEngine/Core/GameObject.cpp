#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject()
{
	// 각도를 0도, 0프레임, Visible을 true로 설정
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
	// 텍스쳐 클래스에서 텍스쳐를 불러온다
	m_Texture = TextureManager::GetInstance()->Load_Texture(path);
}

void GameObject::SetSize(int x, int y)
{
	// 크기 벡터의 x, y값을 정한다
	m_Size.x = x;
	m_Size.y = y;
}

void GameObject::SetPos(int x, int y)
{
	// 위치 벡터의 x, y값을 정한다
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
	// 만약 현재시간 - 저장된시간이 딜레이보다 크면
	if (GetTickCount() - Ani_Time >= Delay)
	{
		// 저장시간에 현재 시간을 저장한다
		Ani_Time = GetTickCount();

		// 만약 현재 프레임이 목표 프레임과 같다면
		if (Ani_Time == Frame)
		{
			// 현재 프레임을 0으로 주고
			Ani_Now = 0;

			// 시간 초기화
			Ani_Time = 0;

			// true값을 리턴한다.
			return true;
		}

		// 현재 프레임을 하나 늘리고
		Ani_Now++;
		path += to_string((_Longlong)Ani_Now);
		path += ".png";

		// 텍스쳐를 불러온후 바꾼다.
		Load_Texture(path);
	}

	// 애니메이션이 끝이 아니라면 false을 리턴
	return false;
}