#pragma once
#include "../StudyEngine_SOURCE/stdScript.h"

namespace study
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

	private:
	};
}


