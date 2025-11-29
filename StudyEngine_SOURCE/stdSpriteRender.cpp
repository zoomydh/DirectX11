#include "stdSpriteRender.h"
#include "stdGameObject.h"
#include "stdTransform.h"

namespace study 
{
	SpriteRender::SpriteRender()
		: mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
	{

	}

	SpriteRender::~SpriteRender()
	{

	}

	void SpriteRender::Initialize()
	{

	}

	void SpriteRender::Update()
	{

	}

	void SpriteRender::LateUpdate()
	{

	}

	void SpriteRender::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();

		Vector2 pos = tr->GetPosition();
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRender::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		if (mImage != nullptr)
		{
			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}
	}
}