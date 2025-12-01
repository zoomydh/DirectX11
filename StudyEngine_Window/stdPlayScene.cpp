#include "stdPlayScene.h"
#include "stdGameObject.h"
#include "stdPlayer.h"
#include "stdTransform.h"
#include "stdSpriteRender.h"
#include "stdInput.h"
#include "stdTitleScene.h"
#include "stdSceneManager.h"

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

		{
			bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");
			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"E:\\DirectX12_Study\\StudyEngine\\Resources\\CloudOcean.png");
			AddGameObject(bg, eLayerType::BACKGROUND);
		}

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
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}
