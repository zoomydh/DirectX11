#pragma once
#include "../StudyEngine_SOURCE/stdScene.h"

namespace study
{
	class TitleScene: public Scene
	{
		public:
			TitleScene();
			~TitleScene();

			void Initialize() override;
			void Update() override;
			void LateUpdate() override;
			void Render(HDC hdc) override;

		private:
	};
}


