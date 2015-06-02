#include "ConstantValue.h"
#include "PhysicsManager.h"
#include "RigidBody.h"
#include "CollisionManager.h"

void PolygonProjectionToVector(vector<D3DXVECTOR2> vertices, D3DXVECTOR2 axis, float* min, float* max)
{
	float dotProduct = D3DXVec2Dot(&vertices[0], &axis);

	*min = dotProduct;
	*max = dotProduct;

	for (int i = 0; i < 4; i++)
	{
		dotProduct = D3DXVec2Dot(&vertices[i], &axis);

		if (*min > dotProduct)
			*min = dotProduct;

		else if (dotProduct> *max)
			*max = dotProduct;
	}
}

float IntervalDistance(float minA, float maxA, float minB, float maxB)
{
	if (minA < minB)
	{
		return minB - maxA;
	}
	else
	{
		return minA - maxB;
	}
}

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::InsertBody(RigidBody* a_pBody)
{
	m_vRigidBodyArray.push_back(a_pBody);
}

void PhysicsManager::Tick(float dt)
{
	for (int i = 0; i < m_vRigidBodyArray.size() - 1; i++)
	{
		auto Body1 = m_vRigidBodyArray[i];

		Body1->m_nImpulseTime += dt;

		D3DXVECTOR2 a = D3DXVECTOR2(0, 0);
		D3DXVECTOR2 dv = D3DXVECTOR2(0, 0);
		D3DXVECTOR2 ds = D3DXVECTOR2(0, 0);

		Body1->m_vForce.x = 0;
		Body1->m_vForce.y = 0;

		////∏∂¬˚∑¬	
		//if (Body1->m_vVelocity.x > 0)
		//{
		//	float dx = -Body1->m_fMass * Body1->m_fFriction;
		//	Body1->m_vForce.x += dx;
		//}

		//else if (Body1->m_vVelocity.x < 0)
		//{
		//	Body1->m_vForce.x += Body1->m_fMass * Body1->m_fFriction;
		//}

		Body1->m_vForce += Body1->m_vOuterForce;

		a = Body1->m_vForce * Body1->m_fMassInv;
		dv = a * dt;
		if (Body1->m_bIsGravity)
			dv.y += GRAVITY_CONSTANT;

		Body1->m_vVelocity += dv;

		ds = Body1->m_vVelocity;

		for (int j = i; j < m_vRigidBodyArray.size(); j++)
		{
			auto Body2 = m_vRigidBodyArray[j];

			if(Body1 == Body2 || !CollisionManager::GetInstance()->Circle_Check(Body1->m_vPosition.x, Body1->m_vPosition.y, Body2->m_vPosition.x, Body2->m_vPosition.y, 700))
				continue;

			CollisionCheckResult result;
			result = PolygonCollisionCheck(Body1, Body2, ds);
			
			if (result.bIsCollided)
			{
				ApplyImpulse(Body1, Body2, result.translateVector);
			}

		}
		Body1->m_vPosition += Body1->m_vVelocity;

		/*if (Body1->m_vPosition.x > 800)
		{
			Body1->m_vVelocity.x *= -1;
			Body1->m_vPosition.x = 800;
		}
		if (Body1->m_vPosition.x < 0)
		{
			Body1->m_vVelocity.x *= -1;
			Body1->m_vPosition.x = 0;
		}

		if (Body1->m_vPosition.y < 0)
		{
			Body1->m_vVelocity.y *= (-1);
			Body1->m_vPosition.y = 0;
		}

		if (Body1->m_vPosition.y > 600)
		{
			Body1->m_vVelocity.y *= (-1);
			Body1->m_vPosition.y = 600;
		}*/

		Body1->m_vOuterForce.x = 0;
		Body1->m_vOuterForce.y = 0;
	}
}

CollisionCheckResult PhysicsManager::PolygonCollisionCheck(RigidBody* sprite1, RigidBody* sprite2, D3DXVECTOR2 velocity)
{
	CollisionCheckResult result;
	unsigned int vertexCountA = sprite1->m_arrVertex.size();
	unsigned int vertexCountB = sprite2->m_arrVertex.size();
	D3DXVECTOR2 translationVector;
	float minintervalDistance = 100000000;

	vector<D3DXVECTOR2> verticeA = sprite1->m_arrVertex;
	vector<D3DXVECTOR2> verticeB = sprite2->m_arrVertex;
	vector<D3DXVECTOR2> edgesA;
	vector<D3DXVECTOR2> edgesB;

	for (int i = 0; i < vertexCountA; i++)
	{
		edgesA.push_back(verticeA[i] - verticeA[(i + 1) % vertexCountA]);
	}

	for (int i = 0; i < vertexCountB; i++)
	{
		edgesB.push_back(verticeB[i] - verticeB[(i + 1) % vertexCountB]);
	}

	for (int i = 0; i < vertexCountA + vertexCountB; i++)
	{
		D3DXVECTOR2 currEdge;
		if (i < vertexCountA)
			currEdge = edgesA[i];
		else
			currEdge = edgesB[i - vertexCountA];

		D3DXVECTOR2 axis = D3DXVECTOR2(-currEdge.y, currEdge.x);
		D3DXVec2Normalize(&axis, &axis);

		float minA, maxA, minB, maxB;
		PolygonProjectionToVector(verticeA, axis, &minA, &maxA);
		PolygonProjectionToVector(verticeB, axis, &minB, &maxB);

		if (IntervalDistance(minA, maxA, minB, maxB) > 0)
			result.bIsCollided = false;

		float projectedVelocity = D3DXVec2Dot(&axis, &velocity);

		if (projectedVelocity < 0)
			minA += projectedVelocity;
		else
			maxA += projectedVelocity;

		float intervalDistance = IntervalDistance(minA, maxA, minB, maxB);
		if (intervalDistance > 0)
			result.bIsWillCollided = false;

		if ((!result.bIsCollided) && (!result.bIsWillCollided))
			break;

		intervalDistance = abs(intervalDistance);

		if (intervalDistance < minintervalDistance)
		{
			minintervalDistance = intervalDistance;
			translationVector = axis;

			D3DXVECTOR2 d = sprite1->getPosition() - sprite2->getPosition();
			if (D3DXVec2Dot(&d, &translationVector) > 0)
				translationVector *= -1;
		}
	}

	if (result.bIsWillCollided)
	{
		result.translateVector = translationVector * minintervalDistance;
	}

	return result;
}

void PhysicsManager::ApplyImpulse(RigidBody* Body1, RigidBody* Body2, D3DXVECTOR2 axis)
{
	if (axis.x == 0 && axis.y == 0)
		return;

	float j;
	D3DXVECTOR2 vRelativeVelocity = Body1->m_vVelocity - Body2->m_vVelocity;
	D3DXVECTOR2 vRelativePosition = Body1->m_vPosition - Body2->m_vPosition;

	if (D3DXVec2Dot(&vRelativeVelocity, &axis) < 0)
	{
		return;
	}

	D3DXVECTOR2 vCollisionNormal = axis;
	D3DXVec2Normalize(&vCollisionNormal, &vCollisionNormal);

	j = (-(1 + 0) * (D3DXVec2Dot(&vRelativeVelocity, &vCollisionNormal))) / ((D3DXVec2Dot(&vCollisionNormal, &vCollisionNormal)) * (Body1->m_fMassInv + Body2->m_fMassInv));

	if (Body1->m_fMass != 0)
		Body1->m_vVelocity += (j * vCollisionNormal) * Body1->m_fMassInv;

	if (Body2->m_fMass != 0)
		Body2->m_vVelocity -= (j * vCollisionNormal) * Body2->m_fMassInv;
}

//π›ªÁ ∫§≈Õ : R = P +  2n(-P°§n)