#include "stdScene.h"

namespace study 
{
	Scene::Scene()
		: mGameObjects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		for (GameObject * gameobj : mGameObjects )
		{
			gameobj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject * gameobj : mGameObjects )
		{
			gameobj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject * gameobj : mGameObjects )
		{
			gameobj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj)
	{
		mGameObjects.push_back(gameObj);
	}
}

