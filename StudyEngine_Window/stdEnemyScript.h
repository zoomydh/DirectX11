#pragma once
#include "../StudyEngine_SOURCE/stdScript.h"
#include "../StudyEngine_SOURCE/stdTransform.h"

namespace study
{
	class EnemyScript : public Script
	{
	public:
		enum class eState
		{
			SITDOWN,
			WALK,
			SLEEP,
			LAYDOWN,
			ATTACK
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
		};

		EnemyScript();
		~EnemyScript();
		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

	private:
		void sitDOwn();
		void move();
		void PlayWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);
		void laydown();

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
	};
}
