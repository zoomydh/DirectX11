#include "stdGameObject.h"
#include "stdInput.h"

namespace study
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		if (Input::Getkey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::Getkey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::Getkey(eKeyCode::Up))
		{
			mY -= 0.01f;
		}

		if (Input::Getkey(eKeyCode::Down))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldbrush);
		DeleteObject(brush);
		DeleteObject(redPen);
	}

} // namespace study

