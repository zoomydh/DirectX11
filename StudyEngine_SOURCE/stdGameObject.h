#pragma once
#include "CommonInclude.h"
#include "stdComponent.h"

namespace study
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		// Virtual : 부모를 상속받은 자식 클래스에서 재정의(오버라이딩)할 수 있도록 허용하는 키워드
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		
		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				//dynamic_cast : 부모 클래스의 포인터에서 자식 클래스의 포인터로 다운 캐스팅해주는 연산자
				//               dynamic_cast <new_type> (expression)
				//               expression를 new_type 개체로 변환
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

	private:
		void InitializeTransform();

	private:
		std::vector<Component*> mComponents;
	};
}


