#include "Object_Manger.h"
#include "IScroll.h"
#include "ConstantValue.h"


Object_Manger::Object_Manger()
{
}


Object_Manger::~Object_Manger()
{
}

void Object_Manger::Add_Object(GameObject* obj)
{
	// 오브젝트 벡터에 게임 오브젝트를 넣는다.
	Object_Vector.push_back(obj);
}

void Object_Manger::Add_Scroll_Object(IScroll* a_pScrl)
{
	m_arrScroll.push_back(a_pScrl);
}

void Object_Manger::Add_UI(GameObject* ui)
{
	// Ui 벡터에 게임 오브젝트를 넣는다.
	UI_Vector.push_back(ui);
}

void Object_Manger::Release()
{
	// 오브젝트 벡터와 Ui 벡터를 크기만큼 for문을 돌려서 삭제후
	for (int i = 0; i < Object_Vector.size(); i++)
	{
		delete Object_Vector[i];
	}
	for (int i = 0; i < UI_Vector.size(); i++)
	{
		delete UI_Vector[i];
	}

	// 벡터들을 비운다.
	Object_Vector.clear();
	UI_Vector.clear();
}

void Object_Manger::Camera_Move(D3DXVECTOR2 m_vCenterPosition)
{
	D3DXVECTOR2 dv = D3DXVECTOR2(WND_WIDTH / 2, WND_HEIGHT / 2) - m_vCenterPosition;
	dv /= 9;

	for(int i = 0; i < m_arrScroll.size(); i++)
	{
		m_arrScroll[i]->Scroll(dv);
	}
}