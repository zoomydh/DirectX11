#pragma once
#include "../StudyEngine_SOURCE/stdResources.h"
#include "../StudyEngine_SOURCE/stdTexture.h"

namespace study
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\catAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}

//camera :