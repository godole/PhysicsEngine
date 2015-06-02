#include "SceneManager.h"
#include "S_Game.h"

SceneManager::SceneManager()
{
	// ���� ó���� �ʱ�ȭ
	m_Scene = NULL;
}


SceneManager::~SceneManager()
{
}

void SceneManager::SceneChange(int What_Scene)
{
	// ���� ������ ���� �ִٸ�
	if (m_Scene)
	{
		// ���� �����ϰ� �����Ѵ�.
		m_Scene->Release();
		delete m_Scene;
	}

	// swtih ������ ���� ������ ���� ã�´�.
	switch (What_Scene)
	{
	// �ش� ���� new�� �޸� �Ҵ��� �Ѵ�.
	case eGame:
		m_Scene = new S_Game;
		break;
	}

	// ���� ���� ���� ���� �ִٸ�
	if (m_Scene)
	{
		// �� ���� Init�Ѵ�. 
		m_Scene->Init();
	}
}