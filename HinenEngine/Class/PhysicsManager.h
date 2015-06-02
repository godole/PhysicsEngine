#pragma once
#include "stdafx.h"
#include "Singleton.h"
#include <vector>

class RigidBody;

typedef struct _tagCollisionCheckResult
{
	bool bIsCollided;
	bool bIsWillCollided;
	D3DXVECTOR2 translateVector;
}CollisionCheckResult;

using namespace std;

class PhysicsManager :
	public CSingleton<PhysicsManager>
{
public :
	void InsertBody(RigidBody* a_pBody);

public :
	void Tick(float dt = 0.016);

public:
	PhysicsManager();
	~PhysicsManager();

private :
	vector<RigidBody*> m_vRigidBodyArray;

	CollisionCheckResult PolygonCollisionCheck(RigidBody* sprite1, RigidBody* sprite2, D3DXVECTOR2 velocity);
	void ApplyImpulse(RigidBody* Body1, RigidBody* Body2, D3DXVECTOR2 axis);
};

