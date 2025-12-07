#pragma once
#include "../StudyEngine_SOURCE/stdGameObject.h"

namespace study
{
	class Enemy : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}
