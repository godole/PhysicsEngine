//////////////////////////////////////////////////////////////
/////////////////////  충돌체크 클래스  //////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"
#include "GameObject.h"

class RigidBody;

class CollisionManager : public CSingleton<CollisionManager>
{
public:
	CollisionManager();
	~CollisionManager();

	// 사각형 충돌
	bool RECT_Collision_Check(GameObject* obj1, GameObject* obj2);

	// 원충돌
	bool Circle_Check(float x1, float y1, float x2, float y2, float size);
};

