#pragma once
#include "../StudyEngine_SOURCE/stdSceneManager.h"
#include "stdPlayScene.h"
#include "stdTitleScene.h"

namespace study
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
