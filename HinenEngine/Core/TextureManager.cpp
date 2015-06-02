#include "TextureManager.h"
#include "GraphicManager.h"

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

LPDIRECT3DTEXTURE9 TextureManager::Load_Texture(string path)
{
	// 벡터의 사이즈만큼 for문을 돌린다.
	for (int i = 0; i < Info_Vector.size(); i++)
	{
		// 만약 찾을려는 이미지의 path와 벡터가 가지고 있는 path의 값이 같다면
		// 이미 벡터안에 사용할려는 이미지가 있다는 뜻이므로
		if (path == Info_Vector[i].path)
		{
			// 벡터안의 텍스쳐를 리턴해준다.
			return Info_Vector[i].Texture;
		}
	}

	// 만약 이미지가 벡터에 없다면 이미지를 추가한후 다시 돌린다.
	Add_Texture(path);
	return Load_Texture(path);
}

void TextureManager::Add_Texture(string path)
{
	// 텍스쳐 정보를 선언,
	Texture_Info Info;

	// Info의 path에 추가할려는 path를 넣는다.
	Info.path = path;

	// 텍스쳐를 생성하는 메서드
	D3DXCreateTextureFromFileEx(GraphicManager::GetInstance()->g_pd3dDevice,
								Info.path.c_str(),
								D3DX_DEFAULT_NONPOW2,
								D3DX_DEFAULT_NONPOW2,
								1,
								0,
								D3DFMT_UNKNOWN,
								D3DPOOL_MANAGED,
								1,
								1,
								NULL,
								NULL,
								NULL,
								&Info.Texture);

	// path와 텍스쳐에 값을 넣었다면 이 Info를 벡터에 넣는다.
	Info_Vector.push_back(Info);
}

void TextureManager::Release()
{
	// 벡터의 사이즈만큼 for문을 돌린다.
	for (int i = 0; i < Info_Vector.size(); i++)
	{
		// 모든 벡터안의 텍스쳐를 해제한다.
		Info_Vector[i].Texture->Release();
	}
	
	// 벡터를 비운다.
	Info_Vector.clear();
}