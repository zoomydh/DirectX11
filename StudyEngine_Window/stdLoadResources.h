#pragma once
#include "../StudyEngine_SOURCE/stdResources.h"
#include "../StudyEngine_SOURCE/stdTexture.h"

namespace study
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"..\\Resources\\img\\pacman\\0.png");
		Resources::Load<graphics::Texture>(L"Chicken", L"..\\Resources\\chicken.bmp");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\catAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Bubble", L"..\\Resources\\bubble.png");
		Resources::Load<graphics::Texture>(L"MapleEffect", L"..\\Resources\\ezgif.com-gif-maker.png");
	}
}

//camera :