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

		void Intialize(HWND hwnd, UINT Width, UINT Height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		HDC mBackHdc;
		HBITMAP mBackBitmap;
		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;
	};
}

