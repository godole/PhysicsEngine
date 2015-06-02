//////////////////////////////////////////////////////////////
////////////////////////  �� Ŭ����  /////////////////////////
//////////////////////////////////////////////////////////////


#pragma once
// ������ ����� �پ��� �������
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

	// ���� �����Լ��� �����Լ��� �پ缺�� Ȱ��
	virtual void Init() = 0;
	virtual void Updata() = 0;
	virtual void Render() = 0;
	virtual void Release();

	// ������Ʈ �Ŵ����� �����Ѵ�.
	Object_Manger obj;
};

