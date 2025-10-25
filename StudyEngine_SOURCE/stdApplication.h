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

		void Intialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		float mSpeed;

		GameObject mPlayer;
	};
}

