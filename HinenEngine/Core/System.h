//////////////////////////////////////////////////////////////
/////////////////  ������ �ý��� Ŭ����  /////////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

class System
{
public:
	System();
	~System();

	// �ʱ�ȭ, �޼�������, ������, �׸��� ���� ������ �̷�����ִ�.
	// ������ ������ ���ư��� �κ��� �޼������� - ���η����̴�.
	void Init();
	void Msg_Loop();
	void Release();
	void Main_Loop();
};
