//////////////////////////////////////////////////////////////
///////////////  ���带 ����ϴ� Ŭ����  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

class SoundManager : public CSingleton<SoundManager>
{
public:
	SoundManager();
	~SoundManager();

public:
	// ������� ����ϴ� �޼���
	void Play_Bg(string path);

	// ȿ������ ����ϴ� �޼���
	void Play_Ef(string path);
};

