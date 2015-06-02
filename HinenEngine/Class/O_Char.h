//////////////////////////////////////////////////////////////
//////////////////////  ĳ���� Ŭ����  ///////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "GameObject.h"
#include "Update.h"
#include "IScroll.h"
#include "MoveDirection.h"

class RigidBody;

class O_Char : public GameObject,	// ���� ������Ʈ�� ��ӹ޴´�.
	public IUpdate,
	public IScroll
{
public :	//Scroll Interface
	virtual void Scroll(D3DXVECTOR2 a_vScrollVelocity) override;

public :	//Update Interface
	virtual void Update() override;

public:
	O_Char();
	~O_Char();

	virtual void Init(string path);
	virtual void SetPos(D3DXVECTOR2 a_Pos) override;
	virtual void SetSize(D3DXVECTOR2 a_Size) override;

	// Key�� üũ�ϴ� �޼���
	void Key(EMoveDirection a_Dir);

private :
	RigidBody* m_pRigidBody;

	void SetRigidBodyVertices();
};

