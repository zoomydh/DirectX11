#include "stdSpriteRender.h"
#include "stdGameObject.h"
#include "stdTransform.h"

namespace study 
{
	SpriteRender::SpriteRender()
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
		// Create a brush
		HBRUSH blueBrush = CreateSolidBrush(RGB(255, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Rectangle(hdc, tr->GetX(), tr->GetY(), 100 + tr->GetX(), 100 + tr->GetY());

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);	
	}
}