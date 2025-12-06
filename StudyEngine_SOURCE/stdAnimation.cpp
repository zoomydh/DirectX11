#include "stdAnimation.h"
#include "stdTime.h"
#include "stdTransform.h"
#include "stdGameobject.h"
#include "stdAnimator.h"
#include "stdRender.h"

namespace study
{
	Animation::Animation()
		: Resource(enums::eResourceType::ANIMATION)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)

	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if(mbComplete)
			return;

		mTime += Time::GetDeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1 )
			{
				mIndex++;
			}
			else
			{
				mbComplete = true;
			}
		}
	}

	void Animation::Render(HDC hdc)
	{
		// AlphaBlend : 해당 이미지 알파채널이 있어야 함
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rotation = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (Render::mainCamera)
			pos = Render::mainCamera->CalucatePosition(pos);
		Sprite sprite = mAnimationSheet[mIndex];
		graphics::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphics::Texture::eTextureType::BMP)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 125; // 0(transparent) ~ 255(opaque)

			HDC imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc, 
				pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f),
				sprite.size.x * scale.x, sprite.size.y * scale.y, 
				imgHdc,
				sprite.startPos.x, sprite.startPos.y, 
				sprite.size.x, sprite.size.y, func);
		}
		else if (type == graphics::Texture::eTextureType::PNG)
		{
			// 내가 원하는 픽셀을	투명화 시킬때
			Gdiplus::ImageAttributes imgAttr = {};
			//투명화 시킬 픽셀의 색 범위
			imgAttr.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));		
			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-pos.x, -pos.y);
	
			graphics.DrawImage(mTexture->GetImage(),
								Gdiplus::Rect(pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f),
								sprite.size.x * scale.x, sprite.size.y * scale.y),
								sprite.startPos.x , sprite.startPos.y,
								sprite.size.x, sprite.size.y,
								Gdiplus::Unit::UnitPixel, &imgAttr);
		}


	}

	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet,
		Vector2 startPos, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.startPos.x = startPos.x + (size.x * i);
			sprite.startPos.y = startPos.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}