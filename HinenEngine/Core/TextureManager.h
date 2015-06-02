//////////////////////////////////////////////////////////////
///////////////  �ؽ��ĸ� �����ϴ� Ŭ����  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

// �ؽ��� ������ ����ִ� ����ü
struct Texture_Info
{
	// ��� �� �ؽ��ĸ� �����ϰ� �ִ�.
	string path;
	LPDIRECT3DTEXTURE9 Texture;
};

class TextureManager : public CSingleton<TextureManager>
{
public:
	TextureManager();
	~TextureManager();

public:
	// �ؽ��ĸ� ������ ����
	vector<Texture_Info> Info_Vector;

	// �ؽ��� �ҷ�����, �߰�, ����
	LPDIRECT3DTEXTURE9 Load_Texture(string path);
	void Add_Texture(string path);
	void Release();
};

