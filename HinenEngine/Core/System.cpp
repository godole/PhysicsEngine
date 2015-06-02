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
	// �׷��� Ŭ������ �ʱ�ȭ�Ѵ�.
	GraphicManager::GetInstance()->Init();

	// �׸��� ���� �����Ѵ�.
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
	// ���� �׷����� �����Ѵ�.
	// �� �������� �ؽ���, ������Ʈ ������ ���ԵǾ��ִ�.
	SceneManager::GetInstance()->m_Scene->Release();
	GraphicManager::GetInstance()->Release();
}

void System::Main_Loop()
{
	// Render�� �����Ѵ�.
	GraphicManager::GetInstance()->RenderStart();

	// �ش� ���� ������Ʈ�� ���ְ�
	SceneManager::GetInstance()->m_Scene->Updata();

	// Render�� ������.
	GraphicManager::GetInstance()->RenderEnd();
}