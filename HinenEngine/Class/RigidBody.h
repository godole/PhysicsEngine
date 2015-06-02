#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;

class PhysicsManager;

class RigidBody
{
public :
	void ApplyForce(D3DXVECTOR2 a_vForce);

public:
	RigidBody();
	~RigidBody();

	_inline const D3DXVECTOR2 getPosition(){ return m_vPosition; };

	void					  setMass(float a_fMass);
	_inline void			  setFriction(float a_fFrictioln){ this->m_fFriction = a_fFrictioln; }
	_inline void			  setIsGravity(bool a_bIs){ this->m_bIsGravity = a_bIs; }

	_inline void			  setPositionTo(D3DXVECTOR2 a_Pos){ this->m_vPosition = a_Pos; }
	_inline void			  setPositionBy(D3DXVECTOR2 a_Pos){ this->m_vPosition += a_Pos; }
	_inline void			  setVelocity(D3DXVECTOR2 a_Velocity){ this->m_vVelocity = a_Velocity; }

	_inline void			  setWidth(int a_nWidth){this->m_nWidth = a_nWidth;}
	_inline void			  setHeight(int a_nHeight){this->m_nHeight = a_nHeight;}
	_inline int				  getWidth(){return m_nWidth;}
	_inline int				  getHeight(){return m_nHeight;}

	void					  BoostX(float a_fGoal, float a_fAccel);
	void					  BoostY(float a_fGoal, float a_fAccel);
	void					  InsertVertex(D3DXVECTOR2 a_Vertex);
	void					  SetVertexWithIndex(D3DXVECTOR2 a_Vertex, int index);

private :
	D3DXVECTOR2 m_vPosition;
	D3DXVECTOR2 m_vVelocity;
	D3DXVECTOR2 m_vForce;
	D3DXVECTOR2	m_vOuterForce;
	float		m_fMass;
	float		m_fMassInv;
	float		m_fFriction;
	float		m_fGravityVelocity;

	int			m_nWidth;
	int			m_nHeight;

	float		m_nImpulseTime;

	vector<D3DXVECTOR2> m_arrVertex;

	bool		m_bIsGravity;

	friend class PhysicsManager;
};

