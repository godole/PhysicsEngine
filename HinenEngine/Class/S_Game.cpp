#include "S_Game.h"
#include "UpdateManager.h"
#include "PhysicsManager.h"
#include "CBox.h"
#include "GameObject.h"
#include "IScroll.h"
#include "Ground.h"


S_Game::S_Game()
{
}


S_Game::~S_Game()
{
}

// �ʱ�ȭ �Լ�
void S_Game::Init()
{
	// ����� ���

	// ĳ���͸� �޸� �Ҵ����� �ؽ��ĸ� �ҷ�����, ũ��, ��ġ���� �ش�.
	m_pPlayer = CreateCharacter(D3DXVECTOR2(100, 100));

	//obj.setCameraPosPtr(&(m_pPlayer->GetPos()));

	CreateBox(D3DXVECTOR2(rand() % 800, rand() % 600));
	CreateBox(D3DXVECTOR2(rand() % 800, rand() % 600));
	CreateBox(D3DXVECTOR2(rand() % 800, rand() % 600));
	CreateBox(D3DXVECTOR2(rand() % 800, rand() % 600));
	CreateBox(D3DXVECTOR2(rand() % 800, rand() % 600));

	CreateGround(D3DXVECTOR2(100, 800));
	CreateGround(D3DXVECTOR2(400, 600));
	CreateGround(D3DXVECTOR2(700, 700));
	CreateGround(D3DXVECTOR2(1200, 900));
}

// ������Ʈ, �� �����Ӹ��� ȣ��ȴ�.
void S_Game::Updata()
{
	// �浹üũ�� �ϰ�ʹٸ� �浹üũ �޼������ ��ȯ���� bool ���̹Ƿ�
	// if�� �Ἥ �⵿üũ Ȯ���� �� �� �ִ�.
	// ������� 
	//
	//if (CollisionManager::GetInstance()->Circle_Check(m_Char->GetPos().x, m_Char->GetPos().y, m_Enemy->GetPos().x, m_Enemy->GetPos().y, 200))
	//{
	//	//m_Enemy��� ������Ʈ�� �����ؼ� ĳ������ x, y��, ���� x, y���� �Ѱ��ְ� �浹üũ ����� �ְ�
	//	//�浹üũ �޼����� ��ȯ���� true �� �浹�� �Ȱ� �̱� ������ �浹�� �ȴٸ� �ؿ� ȿ������ ��µɰ��̴�.
	//
	//	//ȿ���� ���
	//	SoundManager::GetInstance()->Play_Ef("Resource/ex.wav");
	//}

	if((GetAsyncKeyState(VK_LEFT) & 0x8000) == 0x8000)
	{
		m_pPlayer->Key(e_mvLeft);
	}

	if((GetAsyncKeyState(VK_RIGHT) & 0x8000) == 0x8000)
	{
		m_pPlayer->Key(e_mvRight);
	}

	if((GetAsyncKeyState(VK_UP) & 0x8000) == 0x8000)
	{
		m_pPlayer->Key(e_mvUp);
	}

	obj.Camera_Move(m_pPlayer->GetPos());
	PhysicsManager::GetInstance()->Tick();
	UpdateManager::GetInstance()->Tick();
	Render();
}

// �׸���
void S_Game::Render()
{
	// ĳ���� �׸���
	for(int i = 0; i < obj.Object_Vector.size(); i++)
	{
		GraphicManager::GetInstance()->Render(obj.Object_Vector[i]);
	}
}

CBox* S_Game::CreateBox(D3DXVECTOR2 a_Pos)
{
	CBox* temp = new CBox;
	temp->Init("Resource/ĳ����.png");
	temp->SetSize(D3DXVECTOR2(200, 200));
	temp->SetPos(a_Pos);

	obj.Add_Object(temp);
	obj.Add_Scroll_Object(temp);

	return temp;
}

O_Char*		S_Game::CreateCharacter(D3DXVECTOR2 a_Pos)
{
	O_Char* temp = new O_Char;
	temp->Init("Resource/ĳ����.png");
	temp->SetSize(D3DXVECTOR2(100, 100));
	temp->SetPos(a_Pos);

	obj.Add_Object(temp);
	obj.Add_Scroll_Object(temp);

	return temp;
}

CGround*	S_Game::CreateGround(D3DXVECTOR2 a_Pos)
{
	CGround* temp = new CGround;
	temp->Init("Resource/ground1.png");
	temp->SetSize(D3DXVECTOR2(450, 50));
	temp->SetPos(a_Pos);

	obj.Add_Object(temp);
	obj.Add_Scroll_Object(temp);

	return temp;
}