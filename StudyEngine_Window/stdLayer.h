#pragma once
#include "stdEntity.h"
#include "CommonInclude.h"
#include "stdGameObject.h"

namespace study
{
	class Layer : public Entity
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		 eLayerType mType;
		 std::vector<GameObject*> mGameObjects;
	};

}

