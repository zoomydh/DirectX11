#pragma once
#include "CommonInclude.h"
#include "stdGameObject.h"

namespace study
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT Width, UINT Height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		HDC GetHdc() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC src, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;
		HDC mBackHdc;
		HBITMAP mBackBitmap;
		UINT mWidth;
		UINT mHeight;

		//std::vector<Scene*> mScenes;
	};
}

