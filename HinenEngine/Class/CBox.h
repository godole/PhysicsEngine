#pragma once
#include "Update.h"
#include "GameObject.h"
#include "RigidBody.h"
#include "IScroll.h"

class CBox :
	public IUpdate,
	public GameObject,
	public IScroll
{
public :	//Scroll Interface
	virtual void Scroll(D3DXVECTOR2 a_vScrollVelocity) override;

public :	//Update Interface
	virtual void Update();

public :
	virtual void Init(string path) override;
	virtual void SetPos(D3DXVECTOR2 a_Pos) { m_pRigidBody->setPositionTo(a_Pos); }
	virtual void SetSize(D3DXVECTOR2 a_Size) override;

public :
	CBox();
	~CBox();

private :
	RigidBody* m_pRigidBody;

	void SetRigidBodyVertices();
};