#pragma once
#include "../StudyEngine_SOURCE/stdScript.h"

namespace study
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			SITDOWN,
			WALK,
			SLEEP,
			ATTACK
		};

		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

	private:
		void sitDOwn();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}


