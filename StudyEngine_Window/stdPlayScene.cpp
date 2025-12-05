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
#include "stdPlayerScript.h"
#include "../StudyEngine_SOURCE/stdCamera.h"
#include "../StudyEngine_SOURCE/stdRender.h"
#include "../StudyEngine_SOURCE/stdAnimator.h"

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
		//main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::NONE, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		Render::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();

		// game object 만들기 전에 resource 전부 load 해두면 좋다.
		mPlayer = object::Instantiate<Player>(enums::eLayerType::PLAYER/*, Vector2(100.0f, 100.0f)*/);
		//SpriteRender* sr = mPlayer->AddComponent<SpriteRender>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* pactex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", pactex, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->PlayAnimation(L"CatFrontMove", true);
		//sr->SetTexture(pactex);
		

		GameObject * bg = object::Instantiate<GameObject>(enums::eLayerType::BACKGROUND/*, Vector2(100.0f, 100.0f)*/);
		SpriteRender* bgsr = bg->AddComponent<SpriteRender>();
		bgsr->SetSize(Vector2(3.0f, 3.0f));
		//bg->AddComponent<PlayerScript>();

		graphics::Texture* bgtex = Resources::Find<graphics::Texture>(L"Map");
		bgsr->SetTexture(bgtex);

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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
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
