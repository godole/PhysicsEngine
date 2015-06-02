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
	// ������ �����ŭ for���� ������.
	for (int i = 0; i < Info_Vector.size(); i++)
	{
		// ���� ã������ �̹����� path�� ���Ͱ� ������ �ִ� path�� ���� ���ٸ�
		// �̹� ���;ȿ� ����ҷ��� �̹����� �ִٴ� ���̹Ƿ�
		if (path == Info_Vector[i].path)
		{
			// ���;��� �ؽ��ĸ� �������ش�.
			return Info_Vector[i].Texture;
		}
	}

	// ���� �̹����� ���Ϳ� ���ٸ� �̹����� �߰����� �ٽ� ������.
	Add_Texture(path);
	return Load_Texture(path);
}

void TextureManager::Add_Texture(string path)
{
	// �ؽ��� ������ ����,
	Texture_Info Info;

	// Info�� path�� �߰��ҷ��� path�� �ִ´�.
	Info.path = path;

	// �ؽ��ĸ� �����ϴ� �޼���
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

	// path�� �ؽ��Ŀ� ���� �־��ٸ� �� Info�� ���Ϳ� �ִ´�.
	Info_Vector.push_back(Info);
}

void TextureManager::Release()
{
	// ������ �����ŭ for���� ������.
	for (int i = 0; i < Info_Vector.size(); i++)
	{
		// ��� ���;��� �ؽ��ĸ� �����Ѵ�.
		Info_Vector[i].Texture->Release();
	}
	
	// ���͸� ����.
	Info_Vector.clear();
}