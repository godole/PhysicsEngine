#pragma once
#include "gameobject.h"
#include "IScroll.h"
#include "Update.h"

class RigidBody;

class CGround :
	public GameObject,
	public IScroll,
	public IUpdate
{
public :	//Scroll Interface
	virtual void Scroll(D3DXVECTOR2 a_vScrollVelocity) override;

public :	//Update Interface
	virtual void Update() override;

public :
	virtual void Init(string path) override;
	virtual void SetPos(D3DXVECTOR2 a_Pos) override;

public:
	CGround(void);
	~CGround(void);

private :
	RigidBody* m_pRigidBody;

	void SetRigidBodyVertices();
};

