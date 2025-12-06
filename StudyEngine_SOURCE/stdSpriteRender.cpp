#include "stdSpriteRender.h"
#include "stdGameObject.h"
#include "stdTransform.h"
#include "stdTexture.h"
#include "stdRender.h"

namespace study 
{
	SpriteRender::SpriteRender()
		: Component(enums::eComponentType::SPRITERENDERER),
		mTexture(nullptr),
		mSize(Vector2::One)
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
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rotation = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = Render::mainCamera->CalucatePosition(pos);
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::BMP)
		{
			TransparentBlt(hdc, pos.x, pos.y, 
				mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y, 
				mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::PNG)
		{
			Gdiplus::ImageAttributes imageAttr = {};
			imageAttr.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage(), 
								Gdiplus::Rect(pos.x, pos.y, 
								mTexture->GetWidth()* mSize.x * scale.x, mTexture->GetHeight()* mSize.y * scale.y),
								0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
								Gdiplus::UnitPixel, nullptr);
		}
	}


}