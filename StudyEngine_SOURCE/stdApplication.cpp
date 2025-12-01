#include "stdApplication.h"
#include "stdInput.h"
#include "stdTime.h"
#include "stdSceneManager.h"

namespace study
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT Width, UINT Height)
	{
		adjustWindowRect(hwnd, Width, Height);
		createBuffer(Width, Height);
		initializeEtc();

		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();
		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		// BackBuffer -> Original Buffer Copy
		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC src, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, src, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// Widow resolution에 맞는 BackBuffer 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		// BackBuffer를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initailize();
		Time::Initailize();
	}
}