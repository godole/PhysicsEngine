#include "Scene.h"

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Release()
{
	// �ؽ��Ŀ� ������Ʈ�� ��� �����Ѵ�.
	TextureManager::GetInstance()->Release();
	obj.Release();
}