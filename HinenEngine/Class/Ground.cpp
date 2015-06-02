#include "Ground.h"
#include "RigidBody.h"


CGround::CGround(void)
{
}


CGround::~CGround(void)
{
}

void CGround::Init(string path)
{
	Load_Texture(path);

	m_pRigidBody = new RigidBody;
	m_pRigidBody->setFriction(10);
	m_pRigidBody->setMass(0);
	m_pRigidBody->setIsGravity(false);

	m_pRigidBody->InsertVertex(D3DXVECTOR2(-m_Size.x / 2, -m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(-m_Size.x / 2, +m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(+m_Size.x / 2, +m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(+m_Size.x / 2, -m_Size.y / 2));
}

void CGround::Scroll(D3DXVECTOR2 a_vScrollVelocity)
{
	m_pRigidBody->setPositionBy(a_vScrollVelocity);
}

void CGround::Update() 
{
	m_Pos = m_pRigidBody->getPosition();
	SetRigidBodyVertices();
}

void CGround::SetPos(D3DXVECTOR2 a_Pos)
{
	m_pRigidBody->setPositionTo(a_Pos);
}

void CGround::SetRigidBodyVertices()
{
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(-m_Size.x / 2, -m_Size.y / 2), 0);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(-m_Size.x / 2, +m_Size.y / 2), 1);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(+m_Size.x / 2, +m_Size.y / 2), 2);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(+m_Size.x / 2, -m_Size.y / 2), 3);
}