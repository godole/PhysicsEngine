#include "UpdateManager.h"
#include "Update.h"


UpdateManager::UpdateManager()
{
}


UpdateManager::~UpdateManager()
{
}

void UpdateManager::Insert(IUpdate* a_pUpdate)
{
	m_vUpdateArr.push_back(a_pUpdate);
}

void UpdateManager::Tick()
{
	for (int i = 0; i < m_vUpdateArr.size(); i++)
	{
		m_vUpdateArr[i]->Update();
	}
}