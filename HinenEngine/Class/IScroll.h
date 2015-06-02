#pragma once
#include "stdafx.h"

class IScroll
{
public :
	virtual void Scroll(D3DXVECTOR2 a_vScrollVelocity) = 0;

public :
	IScroll()
	{

	}
};