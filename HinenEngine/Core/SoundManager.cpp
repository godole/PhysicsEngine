#include "SoundManager.h"


SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::Play_Bg(string path)
{
	// mcisendstring으로 간단하게 배경음을 불러온다.
	string name;
	name = "open ";
	name += path;
	name += " type mpegvideo alias A";

	mciSendString(name.c_str(), NULL, NULL, NULL);

	// 그리고 무한반복 재생
	mciSendString("play A notify repeat", NULL, NULL, NULL);
}

void SoundManager::Play_Ef(string path)
{
	// 효과음 파일을 재생한다.
	sndPlaySound(path.c_str(), SND_ASYNC);
}