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
		if (Render::mainCamera)
			pos = Render::mainCamera->CalucatePosition(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(opaque)

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		AlphaBlend(hdc, pos.x, pos.y, sprite.size.x*4, sprite.size.y*4, imgHdc, 
					sprite.startPos.x, sprite.startPos.y, sprite.size.x, sprite.size.y, func);
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