//////////////////////////////////////////////////////////////
///////////////  사운드를 출력하는 클래스  ///////////////////
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
	// 배경음을 출력하는 메서드
	void Play_Bg(string path);

	// 효과음을 출력하는 메서드
	void Play_Ef(string path);
};

