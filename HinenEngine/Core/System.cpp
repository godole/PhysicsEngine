#include "System.h"
#include "GraphicManager.h"
#include "SceneManager.h"

System::System()
{
}


System::~System()
{
}

void System::Init()
{
	// 그래픽 클래스를 초기화한다.
	GraphicManager::GetInstance()->Init();

	// 그리고 씬을 변경한다.
	SceneManager::GetInstance()->SceneChange(SceneManager::eGame);
}

void System::Msg_Loop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Main_Loop();
		}
	}
}

void System::Release()
{
	// 씬과 그래픽을 해제한다.
	// 씬 해제에는 텍스쳐, 오브젝트 해제도 포함되어있다.
	SceneManager::GetInstance()->m_Scene->Release();
	GraphicManager::GetInstance()->Release();
}

void System::Main_Loop()
{
	// Render을 시작한다.
	GraphicManager::GetInstance()->RenderStart();

	// 해당 씬을 업데이트를 해주고
	SceneManager::GetInstance()->m_Scene->Updata();

	// Render을 끝낸다.
	GraphicManager::GetInstance()->RenderEnd();
}