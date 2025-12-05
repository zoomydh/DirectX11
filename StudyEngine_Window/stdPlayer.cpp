#include "stdPlayer.h"
#include "../StudyEngine_SOURCE/stdInput.h"
#include "../StudyEngine_SOURCE/stdTransform.h"
#include "../StudyEngine_SOURCE/stdTime.h"

namespace study
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
