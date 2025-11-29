#pragma once
#include "stdEntity.h"
#include "stdComponent.h"

namespace study
{
	class SpriteRender : public Component
	{
	public:
		SpriteRender();
		~SpriteRender();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
	};
}

