//////////////////////////////////////////////////////////////
//////////////////////  게임씬 클래스  ///////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "Scene.h"
#include "O_Char.h"
#include <vector>

class CBox;
class GameObject;
class IScroll;
class CGround;

using namespace std;

class S_Game : public Scene	// 씬을 상속받는다.
{
public:
	S_Game();
	~S_Game();

public:
	void Init();
	void Updata();
	void Render();

	CBox* CreateBox(D3DXVECTOR2 a_Pos);
	O_Char* CreateCharacter(D3DXVECTOR2 a_Pos);
	CGround* CreateGround(D3DXVECTOR2 a_Pos);

public:
	// 캐릭터 클래스를 선언
	O_Char* m_pPlayer;

	vector<IScroll*> m_arrScroll;
};

