#pragma once
#include "../StudyEngine_SOURCE/stdSceneManager.h"
#include "stdPlayScene.h"

namespace study
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");
		//SceneManager::CreateScene<PlayScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
