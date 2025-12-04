#pragma once
#include "stdResource.h"

namespace study::graphics
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			BMP,
			PNG,
			NONE,
		};

		Texture();
		~Texture();

		HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType;  }
		Gdiplus::Image* GetImage() { return mImage;  }

	private:
		eTextureType mType;
		Gdiplus::Image* mImage; //PNG
		HBITMAP mBitmap;		//BMP
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}

