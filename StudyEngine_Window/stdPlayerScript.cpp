#include "stdPlayerScript.h"
#include "../StudyEngine_SOURCE/stdInput.h"
#include "../StudyEngine_SOURCE/stdTransform.h"
#include "../StudyEngine_SOURCE/stdTime.h"
#include "../StudyEngine_SOURCE/stdGameObject.h"
#include "../StudyEngine_SOURCE/stdAnimator.h"

namespace study
{
	PlayerScript::PlayerScript()
		: mState(eState::IDLE)
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
		case study::PlayerScript::eState::IDLE:
			idle();
			break;
		case study::PlayerScript::eState::WALK:
			move();
			break;
		case study::PlayerScript::eState::SLEEP:
			break;
		case study::PlayerScript::eState::GIVEWATER:
			givewater();
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
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = eState::GIVEWATER;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);
			Vector2 mousePos = Input::GetMousePosition();
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
			mState = eState::IDLE;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}

	void PlayerScript::givewater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::IDLE;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}
