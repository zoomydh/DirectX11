#include "stdEnemyScript.h"
#include "../StudyEngine_SOURCE/stdInput.h"
#include "../StudyEngine_SOURCE/stdTransform.h"
#include "../StudyEngine_SOURCE/stdTime.h"
#include "../StudyEngine_SOURCE/stdGameObject.h"
#include "../StudyEngine_SOURCE/stdAnimator.h"

namespace study
{
	EnemyScript::EnemyScript()
		: mState(eState::SITDOWN)
		, mAnimator(nullptr)
		, mTime(0.0f)
	{
	}
	EnemyScript::~EnemyScript()
	{
	}
	void EnemyScript::Initialize()
	{

	}

	void EnemyScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();

		switch (mState)
		{
		case study::EnemyScript::eState::SITDOWN:
			sitDown();
			break;
		case study::EnemyScript::eState::WALK:
			move();
			break;
		case study::EnemyScript::eState::SLEEP:
			break;
		case study::EnemyScript::eState::LAYDOWN:

			break;
		case study::EnemyScript::eState::ATTACK:
			break;
		default:
			break;
		}
	}
	void EnemyScript::LateUpdate()
	{
	}
	void EnemyScript::Render(HDC hdc)
	{
	}
	void EnemyScript::sitDown()
	{
		mTime += Time::GetDeltaTime();
		if (mTime > 3.0f)
		{
			mState = EnemyScript::eState::WALK;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}
	void EnemyScript::move()
	{
		mTime += Time::GetDeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LAYDOWN;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SITDOWN;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}
	void EnemyScript::PlayWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case study::EnemyScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case study::EnemyScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case study::EnemyScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case study::EnemyScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void EnemyScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case study::EnemyScript::eDirection::Left:
			if (pos.x > 0 && pos.x < 672)
				pos.x -= 100.0f * Time::GetDeltaTime();
			break;
		case study::EnemyScript::eDirection::Right:
			if (pos.x > 0 && pos.x < 672)
				pos.x += 100.0f * Time::GetDeltaTime();
			break;
		case study::EnemyScript::eDirection::Down:
			if (pos.x > 0 && pos.x < 672)
				pos.y += 100.0f * Time::GetDeltaTime();
			break;
		case study::EnemyScript::eDirection::Up:
			if (pos.x > 0 && pos.x < 672)
				pos.y -= 100.0f * Time::GetDeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}

	void EnemyScript::laydown()
	{
	}

}