#include "stdTransform.h"

namespace study
{
	Transform::Transform()
		: Component(enums::eComponentType::TRANSFORM)
		, mPosition(Vector2::Zero)
		, mRotation(0.0f)
		, mScale(Vector2::One)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}