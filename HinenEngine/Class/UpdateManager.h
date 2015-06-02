#pragma once
#include <vector>
#include "Singleton.h"

using namespace std;

class IUpdate;

class UpdateManager :
	public CSingleton<UpdateManager>
{
public :
	void Insert(IUpdate* a_pUpdate);
	void Tick();

public:
	UpdateManager();
	~UpdateManager();

private :
	vector<IUpdate*> m_vUpdateArr;
};

