#pragma once
#include "../StudyEngine_SOURCE/stdResources.h"
#include "../StudyEngine_SOURCE/stdTexture.h"

namespace study
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"E:\\DirectX12_Study\\StudyEngine\\Resources\\CloudOcean.png");
	}
}