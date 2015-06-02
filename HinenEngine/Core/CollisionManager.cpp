#include "CollisionManager.h"
#include "RigidBody.h"


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

bool CollisionManager::RECT_Collision_Check(GameObject* obj1, GameObject* obj2)
{
	// üũ�� �簢�� 2�� ����
	RECT rect1;
	RECT rect2;

	// �簢���� ����, ������, ��, �Ʒ��� ���� �������ش�.
	rect1.left = obj1->GetPos().x - obj1->GetSize().x / 2;
	rect1.right = obj1->GetPos().x + obj1->GetSize().x / 2;
	rect1.top = obj1->GetPos().y - obj1->GetSize().y / 2;
	rect1.bottom = obj1->GetPos().y + obj1->GetSize().y / 2;

	rect2.left = obj2->GetPos().x - obj2->GetSize().x / 2;
	rect2.right = obj2->GetPos().x + obj2->GetSize().x / 2;
	rect2.top = obj2->GetPos().y - obj2->GetSize().y / 2;
	rect2.bottom = obj2->GetPos().y + obj2->GetSize().y / 2;

	// �׸��� üũ����
	if (rect1.left < rect2.right &&
		rect1.top < rect2.bottom &&
		rect1.right > rect2.left &&
		rect1.bottom > rect2.top)
	{
		// �浹 �Ͻ� true�� ����
		return true;
	}

	// �浹�� �ƴҽ� false ����
	return false;
}


bool CollisionManager::Circle_Check(float x1, float y1, float x2, float y2, float size)
{
	// ���� �������� �Ÿ�, ���� �������� �̿��Ѵ�.

	if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= size * size)
	{
		// �浹 �Ͻ� true�� ����
		return true;
	}

	// �浹�� �ƴҽ� false ����
	return false;
}