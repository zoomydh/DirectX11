#include "stdPlayScene.h"
#include "stdGameObject.h"
#include "stdPlayer.h"
#include "stdTransform.h"
#include "stdSpriteRender.h"


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
			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");
			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"E:\\DirectX12_Study\\StudyEngine\\Resources\\CloudOcean.png");
			AddGameObject(bg);
		}

	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
