//////////////////////////////////////////////////////////////
//////////////////////  ���Ӿ� Ŭ����  ///////////////////////
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

class S_Game : public Scene	// ���� ��ӹ޴´�.
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
	// ĳ���� Ŭ������ ����
	O_Char* m_pPlayer;

	vector<IScroll*> m_arrScroll;
};

