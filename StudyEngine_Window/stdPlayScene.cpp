#include "stdPlayScene.h"
#include "../StudyEngine_SOURCE/stdGameObject.h"
#include "stdPlayer.h"
#include "../StudyEngine_SOURCE/stdTransform.h"
#include "../StudyEngine_SOURCE/stdSpriteRender.h"
#include "../StudyEngine_SOURCE/stdInput.h"
#include "stdTitleScene.h"
#include "../StudyEngine_SOURCE/stdSceneManager.h"
#include "../StudyEngine_SOURCE/stdObject.h"
#include "../StudyEngine_SOURCE/stdTexture.h"
#include "../StudyEngine_SOURCE/stdResources.h"

namespace study
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		// game object 만들기 전에 resource 전부 load 해두면 좋다.

		bg = object::Instantiate<Player>(enums::eLayerType::BACKGROUND/*, Vector2(100.0f, 100.0f)*/);
		SpriteRender* sr = bg->AddComponent<SpriteRender>();
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(bg);

		// game object 생성 후에 layer와 game object의 init 함수 호출
		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}
