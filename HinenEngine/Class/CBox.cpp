#include "stdafx.h"
#include "CBox.h"

CBox::CBox()
{
	//m_pRigidBody->setVelocity(D3DXVECTOR2(rand() % 5, rand() % 5));
}

CBox::~CBox()
{

}

void CBox::Init(string path)
{
	Load_Texture(path);

	m_pRigidBody = new RigidBody;
	//m_pRigidBody->setIsGravity(false);

	m_pRigidBody->setMass(3);
	m_pRigidBody->setFriction(100);

	m_pRigidBody->setWidth(m_Size.x);
	m_pRigidBody->setHeight(m_Size.y);

	m_pRigidBody->InsertVertex(D3DXVECTOR2(-m_Size.x / 2, -m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(-m_Size.x / 2, +m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(+m_Size.x / 2, +m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(+m_Size.x / 2, -m_Size.y / 2));
}

void CBox::Update()
{
	m_Pos = m_pRigidBody->getPosition();
	SetRigidBodyVertices();
}

void CBox::SetSize(D3DXVECTOR2 a_Size)
{
	m_Size = a_Size;
	m_pRigidBody->setWidth(a_Size.x);
	m_pRigidBody->setHeight(a_Size.y);
}

void CBox::SetRigidBodyVertices()
{
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(-m_Size.x / 2, -m_Size.y / 2), 0);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(-m_Size.x / 2, +m_Size.y / 2), 1);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(+m_Size.x / 2, +m_Size.y / 2), 2);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(+m_Size.x / 2, -m_Size.y / 2), 3);
}

void CBox::Scroll(D3DXVECTOR2 a_Vec)
{
	m_pRigidBody->setPositionBy(a_Vec);
}