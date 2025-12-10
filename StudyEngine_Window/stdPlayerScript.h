#pragma once
#include "../StudyEngine_SOURCE/stdScript.h"

namespace study
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			IDLE,
			WALK,
			SLEEP,
			GIVEWATER,
			ATTACK
		};

		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

	private:
		void idle();
		void move();
		void givewater();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}


