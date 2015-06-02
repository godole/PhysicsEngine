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
	// ������Ʈ ���Ϳ� ���� ������Ʈ�� �ִ´�.
	Object_Vector.push_back(obj);
}

void Object_Manger::Add_Scroll_Object(IScroll* a_pScrl)
{
	m_arrScroll.push_back(a_pScrl);
}

void Object_Manger::Add_UI(GameObject* ui)
{
	// Ui ���Ϳ� ���� ������Ʈ�� �ִ´�.
	UI_Vector.push_back(ui);
}

void Object_Manger::Release()
{
	// ������Ʈ ���Ϳ� Ui ���͸� ũ�⸸ŭ for���� ������ ������
	for (int i = 0; i < Object_Vector.size(); i++)
	{
		delete Object_Vector[i];
	}
	for (int i = 0; i < UI_Vector.size(); i++)
	{
		delete UI_Vector[i];
	}

	// ���͵��� ����.
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