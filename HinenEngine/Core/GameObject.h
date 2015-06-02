//////////////////////////////////////////////////////////////
///////////////////  게임 오브젝트 클래스  ///////////////////
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
	// 오브젝트가 가지고 있어야 할 값

	// 텍스쳐, 사이즈, 위치, 각도, Visible
	LPDIRECT3DTEXTURE9	m_Texture;
	D3DXVECTOR2			m_Size;
	D3DXVECTOR2			m_Pos;
	float				Degree;
	bool				Visible;

	// 애니메이션을 위한 값
	// 현재 몇 프레임인지, 체크를 위한 시간
	int					Ani_Now;
	float				Ani_Time;


	// 메서드
	// 텍스쳐 불러오기
	void Load_Texture(string path);

	// 사이즈와 위치 적용
	void SetSize(int x, int y);
	virtual void SetPos(int x, int y);
	virtual void SetSize(D3DXVECTOR2 size);
	virtual void SetPos(D3DXVECTOR2 pos);

	// 사이즈와 위치 가져오기
	D3DXVECTOR2 GetSize();
	D3DXVECTOR2 GetPos();

	// 애니메이션
	bool Animation(string path, int Frame, float Delay);

};

