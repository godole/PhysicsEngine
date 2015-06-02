#include "O_Char.h"
#include "RigidBody.h"


O_Char::O_Char()
{
	
}


O_Char::~O_Char()
{
}

void O_Char::Init(string path)
{
	Load_Texture(path);

	m_pRigidBody = new RigidBody;

	m_pRigidBody->setFriction(30.0);
	m_pRigidBody->setMass(10);

	m_pRigidBody->setWidth(m_Size.x);
	m_pRigidBody->setHeight(m_Size.y);

	m_pRigidBody->InsertVertex(D3DXVECTOR2(-m_Size.x / 2, -m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(-m_Size.x / 2, +m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(+m_Size.x / 2, +m_Size.y / 2));
	m_pRigidBody->InsertVertex(D3DXVECTOR2(+m_Size.x / 2, -m_Size.y / 2));
}

void O_Char::Key(EMoveDirection a_Dir)
{
	switch(a_Dir)
	{
	case e_mvLeft :
		//m_pRigidBody->BoostX(-5, -1.0);
		m_pRigidBody->ApplyForce(D3DXVECTOR2(-30, 0));
		break;

	case e_mvRight :
		//m_pRigidBody->BoostX(5, 1.0);
		m_pRigidBody->ApplyForce(D3DXVECTOR2(30, 0));
		break;

	case e_mvUp :
		//m_pRigidBody->BoostY(-5, -1.0);
		m_pRigidBody->ApplyForce(D3DXVECTOR2(0, -1000));
		break;

	case e_mvDown :
		break;
	}
}

void O_Char::Update()
{
	m_Pos = m_pRigidBody->getPosition();
	SetRigidBodyVertices();
}

void O_Char::SetPos(D3DXVECTOR2 a_Pos)
{
	m_pRigidBody->setPositionTo(a_Pos);
}

void O_Char::SetSize(D3DXVECTOR2 a_Size)
{
	m_Size = a_Size;
	m_pRigidBody->setWidth(a_Size.x);
	m_pRigidBody->setHeight(a_Size.y);
}

void O_Char::Scroll(D3DXVECTOR2 a_vScrollVelocity)
{
	m_pRigidBody->setPositionBy(a_vScrollVelocity);
}

void O_Char::SetRigidBodyVertices()
{
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(-m_Size.x / 2, -m_Size.y / 2), 0);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(-m_Size.x / 2, +m_Size.y / 2), 1);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(+m_Size.x / 2, +m_Size.y / 2), 2);
	m_pRigidBody->SetVertexWithIndex(m_Pos + D3DXVECTOR2(+m_Size.x / 2, -m_Size.y / 2), 3);
}