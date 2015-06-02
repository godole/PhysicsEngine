//////////////////////////////////////////////////////////////
/////////////////////  �浹üũ Ŭ����  //////////////////////
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

	// �簢�� �浹
	bool RECT_Collision_Check(GameObject* obj1, GameObject* obj2);

	// ���浹
	bool Circle_Check(float x1, float y1, float x2, float y2, float size);
};

