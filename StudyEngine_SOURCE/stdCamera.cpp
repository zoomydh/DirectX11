#include "stdCamera.h"
#include "stdGameObject.h"
#include "stdTransform.h"
#include "stdApplication.h"

extern study::Application app;

namespace study
{
	Camera::Camera()
		: Component(enums::eComponentType::CAMERA)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookAtPosition(Vector2::Zero)
		, mTarget(nullptr)

	{

	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		mResolution.x = app.GetWidth();
		mResolution.y = app.GetHeight();	
	}

	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookAtPosition = tr->GetPosition();
		}

		Transform* cameratr = GetOwner()->GetComponent<Transform>();
		mLookAtPosition = cameratr->GetPosition();
		mDistance = mLookAtPosition - (mResolution / 2.0f);
	}
	void Camera::LateUpdate()
	{

	}
	void Camera::Render(HDC hdc)
	{

	}
}