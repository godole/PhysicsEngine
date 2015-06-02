//////////////////////////////////////////////////////////////
///////////////////  ������Ʈ ���� Ŭ����  ///////////////////
//////////////////////////////////////////////////////////////


#pragma once
#include "stdafx.h"
#include "GameObject.h"

using namespace std;

class IScroll;

class Object_Manger
{
public:
	Object_Manger();
	~Object_Manger();

public:
	// ������Ʈ�� ������ ������Ʈ ���Ϳ� Ui ����
	vector<GameObject*> Object_Vector, UI_Vector;
	vector<IScroll*> m_arrScroll;

	// ������Ʈ�� �߰��ϴ� �޼���
	void Add_Object(GameObject* obj);

	void Add_Scroll_Object(IScroll* a_pScrl);

	// Ui�� �߰��ϴ� �޼���
	void Add_UI(GameObject* ui);

	// ��� ���� ������Ʈ�� �����ϴ� �޼���
	void Release();

	void Camera_Move(D3DXVECTOR2 m_vCenterPosition);

	//void setCameraPosPtr(D3DXVECTOR2* a_pPos){m_pCameraPosition = a_pPos;}

private :
	D3DXVECTOR2* m_pCameraPosition;
};

