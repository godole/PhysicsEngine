#pragma once
#include "UpdateManager.h"

class IUpdate
{
public :
	IUpdate()
	{
		UpdateManager::GetInstance()->Insert(this);
	}

	virtual void Update() = 0;
};