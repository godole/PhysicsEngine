#include "Scene.h"

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Release()
{
	// 텍스쳐와 오브젝트를 모두 해제한다.
	TextureManager::GetInstance()->Release();
	obj.Release();
}