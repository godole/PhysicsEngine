//////////////////////////////////////////////////////////////
////////////////////////  씬 클래스  /////////////////////////
//////////////////////////////////////////////////////////////


#pragma once
// 씬에서 사용할 다양한 헤더파일
#include "stdafx.h"
#include "GraphicManager.h"
#include "CollisionManager.h"
#include "Object_Manger.h"
#include "SoundManager.h"
#include "TextureManager.h"

class Scene
{
public:
	Scene();
	~Scene();

	// 순수 가상함수와 가상함수로 다양성을 활용
	virtual void Init() = 0;
	virtual void Updata() = 0;
	virtual void Render() = 0;
	virtual void Release();

	// 오브젝트 매니저를 선언한다.
	Object_Manger obj;
};

