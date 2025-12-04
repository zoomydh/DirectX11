#pragma once
#include "stdEntity.h"

namespace study
{
	class Resource : public Entity //추상 클래스 메모리 할당 안되고 상속받아서만 사용
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수 가상함수 실제메모리 할당이 불가능

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		enums::eResourceType mType;
		std::wstring mPath;
	};
}

