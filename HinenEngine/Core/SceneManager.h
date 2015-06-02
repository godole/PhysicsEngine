//////////////////////////////////////////////////////////////
//////////////////  씬을 관리하는 클래스  ////////////////////
//////////////////////////////////////////////////////////////


#pragma once
#include "stdafx.h"
#include "Scene.h"

class SceneManager : public CSingleton<SceneManager>
{
public:
	// 씬의 종류를 enum으로 선언
	enum Type
	{
		eGame,
	};

public:
	SceneManager();
	~SceneManager();

public:
	// 씬을 선언한다.
	Scene *m_Scene;

	// 씬을 변경하는 메서드
	void SceneChange(int What_Scene);
};

