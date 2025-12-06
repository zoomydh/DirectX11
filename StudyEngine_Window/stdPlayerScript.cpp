#include "stdPlayerScript.h"
#include "../StudyEngine_SOURCE/stdInput.h"
#include "../StudyEngine_SOURCE/stdTransform.h"
#include "../StudyEngine_SOURCE/stdTime.h"
#include "../StudyEngine_SOURCE/stdGameObject.h"
#include "../StudyEngine_SOURCE/stdAnimator.h"

namespace study
{
	PlayerScript::PlayerScript()
		: mState(eState::SITDOWN)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
		
	}

	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();

		switch (mState)
		{
		case study::PlayerScript::eState::SITDOWN:
			sitDOwn();
			break;
		case study::PlayerScript::eState::WALK:
			move();
			break;
		case study::PlayerScript::eState::SLEEP:
			break;
		case study::PlayerScript::eState::ATTACK:
			break;
		default:
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::sitDOwn()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eState::WALK;
			mAnimator->PlayAnimation(L"RightWalk");
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eState::WALK;
			mAnimator->PlayAnimation(L"LeftWalk");
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mState = eState::WALK;
			mAnimator->PlayAnimation(L"UpWalk");
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eState::WALK;
			mAnimator->PlayAnimation(L"DownWalk");
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
			pos.x += 100.0f * Time::GetDeltaTime();

		if (Input::GetKey(eKeyCode::Left))
			pos.x -= 100.0f * Time::GetDeltaTime();

		if (Input::GetKey(eKeyCode::Up))
			pos.y -= 100.0f * Time::GetDeltaTime();

		if (Input::GetKey(eKeyCode::Down))
			pos.y += 100.0f * Time::GetDeltaTime();

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left) ||
			Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eState::SITDOWN;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
}
