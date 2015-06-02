//////////////////////////////////////////////////////////////
///////////////  텍스쳐를 관리하는 클래스  ///////////////////
//////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

using namespace std;

// 텍스쳐 정보를 담고있는 구조체
struct Texture_Info
{
	// 경로 와 텍스쳐를 포함하고 있다.
	string path;
	LPDIRECT3DTEXTURE9 Texture;
};

class TextureManager : public CSingleton<TextureManager>
{
public:
	TextureManager();
	~TextureManager();

public:
	// 텍스쳐를 관리할 벡터
	vector<Texture_Info> Info_Vector;

	// 텍스쳐 불러오기, 추가, 해제
	LPDIRECT3DTEXTURE9 Load_Texture(string path);
	void Add_Texture(string path);
	void Release();
};

