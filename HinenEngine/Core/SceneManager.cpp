#include "SceneManager.h"
#include "S_Game.h"

SceneManager::SceneManager()
{
	// 씬을 처음에 초기화
	m_Scene = NULL;
}


SceneManager::~SceneManager()
{
}

void SceneManager::SceneChange(int What_Scene)
{
	// 만약 이전에 씬이 있다면
	if (m_Scene)
	{
		// 씬을 해제하고 삭제한다.
		m_Scene->Release();
		delete m_Scene;
	}

	// swtih 문으로 내가 변경할 씬을 찾는다.
	switch (What_Scene)
	{
	// 해당 씬을 new로 메모리 할당을 한다.
	case eGame:
		m_Scene = new S_Game;
		break;
	}

	// 만약 새로 만든 씬이 있다면
	if (m_Scene)
	{
		// 그 씬을 Init한다. 
		m_Scene->Init();
	}
}