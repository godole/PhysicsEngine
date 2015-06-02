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

// 초기화 함수
void S_Game::Init()
{
	// 배경음 출력

	// 캐릭터를 메모리 할당이후 텍스쳐를 불러오고, 크기, 위치값을 준다.
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

// 업데이트, 매 프레임마다 호출된다.
void S_Game::Updata()
{
	// 충돌체크를 하고싶다면 충돌체크 메서드들의 반환값이 bool 값이므로
	// if를 써서 출동체크 확인을 할 수 있다.
	// 예를들어 
	//
	//if (CollisionManager::GetInstance()->Circle_Check(m_Char->GetPos().x, m_Char->GetPos().y, m_Enemy->GetPos().x, m_Enemy->GetPos().y, 200))
	//{
	//	//m_Enemy라는 오브젝트를 생성해서 캐릭터의 x, y값, 적의 x, y값을 넘겨주고 충돌체크 사이즈를 주고
	//	//충돌체크 메서드의 반환값이 true 면 충돌이 된것 이기 때문에 충돌이 된다면 밑에 효과음이 출력될것이다.
	//
	//	//효과음 출력
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

// 그리기
void S_Game::Render()
{
	// 캐릭터 그리기
	for(int i = 0; i < obj.Object_Vector.size(); i++)
	{
		GraphicManager::GetInstance()->Render(obj.Object_Vector[i]);
	}
}

CBox* S_Game::CreateBox(D3DXVECTOR2 a_Pos)
{
	CBox* temp = new CBox;
	temp->Init("Resource/캐릭터.png");
	temp->SetSize(D3DXVECTOR2(200, 200));
	temp->SetPos(a_Pos);

	obj.Add_Object(temp);
	obj.Add_Scroll_Object(temp);

	return temp;
}

O_Char*		S_Game::CreateCharacter(D3DXVECTOR2 a_Pos)
{
	O_Char* temp = new O_Char;
	temp->Init("Resource/캐릭터.png");
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