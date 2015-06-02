//////////////////////////////////////////////////////////////
//////////////////  ���� �����ϴ� Ŭ����  ////////////////////
//////////////////////////////////////////////////////////////


#pragma once
#include "stdafx.h"
#include "Scene.h"

class SceneManager : public CSingleton<SceneManager>
{
public:
	// ���� ������ enum���� ����
	enum Type
	{
		eGame,
	};

public:
	SceneManager();
	~SceneManager();

public:
	// ���� �����Ѵ�.
	Scene *m_Scene;

	// ���� �����ϴ� �޼���
	void SceneChange(int What_Scene);
};

