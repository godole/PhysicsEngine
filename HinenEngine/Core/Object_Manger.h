//////////////////////////////////////////////////////////////
///////////////////  오브젝트 관리 클래스  ///////////////////
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
	// 오브젝트를 관리할 오브젝트 벡터와 Ui 벡터
	vector<GameObject*> Object_Vector, UI_Vector;
	vector<IScroll*> m_arrScroll;

	// 오브젝트를 추가하는 메서드
	void Add_Object(GameObject* obj);

	void Add_Scroll_Object(IScroll* a_pScrl);

	// Ui를 추가하는 메서드
	void Add_UI(GameObject* ui);

	// 모든 게임 오브젝트를 해제하는 메서드
	void Release();

	void Camera_Move(D3DXVECTOR2 m_vCenterPosition);

	//void setCameraPosPtr(D3DXVECTOR2* a_pPos){m_pCameraPosition = a_pPos;}

private :
	D3DXVECTOR2* m_pCameraPosition;
};

