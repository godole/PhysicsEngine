#include "SoundManager.h"


SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

void SoundManager::Play_Bg(string path)
{
	// mcisendstring���� �����ϰ� ������� �ҷ��´�.
	string name;
	name = "open ";
	name += path;
	name += " type mpegvideo alias A";

	mciSendString(name.c_str(), NULL, NULL, NULL);

	// �׸��� ���ѹݺ� ���
	mciSendString("play A notify repeat", NULL, NULL, NULL);
}

void SoundManager::Play_Ef(string path)
{
	// ȿ���� ������ ����Ѵ�.
	sndPlaySound(path.c_str(), SND_ASYNC);
}