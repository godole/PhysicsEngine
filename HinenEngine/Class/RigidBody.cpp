#include "RigidBody.h"
#include "PhysicsManager.h"


RigidBody::RigidBody()
{
	PhysicsManager::GetInstance()->InsertBody(this);

	m_vPosition.x = 0;
	m_vPosition.y = 0;

	m_vOuterForce.x = 0;
	m_vOuterForce.y = 0;

	m_vForce.x = 0;
	m_vForce.y = 0;

	m_vVelocity.x = 0;
	m_vVelocity.y = 0;

	m_fMass = 0;
	m_fMassInv = 0;

	m_fFriction = 0;

	m_fGravityVelocity = 0;

	m_bIsGravity = true;

	m_nWidth = 0;
	m_nHeight = 0;

	m_nImpulseTime = 0;
}


RigidBody::~RigidBody()
{
}


void RigidBody::ApplyForce(D3DXVECTOR2 a_vForce)
{
	m_vOuterForce += a_vForce;
}

void RigidBody::BoostX(float a_fGoal, float a_fAccel)
{
	m_vVelocity += D3DXVECTOR2(1, 0) * a_fAccel;

	if (a_fGoal > 0)
	{
		if (m_vVelocity.x > a_fGoal)
			m_vVelocity.x = a_fGoal;
	}

	else if (a_fGoal < 0)
	{
		if (m_vVelocity.x < a_fGoal)
			m_vVelocity.x = a_fGoal;
	}
}

void RigidBody::BoostY(float a_fGoal, float a_fAccel)
{
	m_vVelocity += D3DXVECTOR2(0, 1) * a_fAccel;

	if (a_fGoal > 0)
	{
		if (m_vVelocity.y > a_fGoal)
			m_vVelocity.y = a_fGoal;
	}

	else if (a_fGoal < 0)
	{
		if (m_vVelocity.y < a_fGoal)
			m_vVelocity.y = a_fGoal;
	}
}

void RigidBody::InsertVertex(D3DXVECTOR2 a_pVertex)
{
	m_arrVertex.push_back(a_pVertex);
}

void RigidBody::SetVertexWithIndex(D3DXVECTOR2 a_Vertex, int a_nIndex)
{
	m_arrVertex[a_nIndex] = a_Vertex;
}

void RigidBody::setMass(float a_fMass)
{
	this->m_fMass = a_fMass; 
	this->m_fMassInv = (1 / a_fMass);

	if (a_fMass == 0)
		m_fMassInv = 0;
}