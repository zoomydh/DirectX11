#include "stdInput.h"
#include "stdApplication.h"

extern study::Application app;

namespace study
{
	std::vector<Input::Key> Input::Keys = {};
	math::Vector2 Input::mMousePos = math::Vector2::One;
	
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
	};
	
	void Input::Initailize()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = ekeyState::NONE;
			key.keyCode = (eKeyCode)i;
			Keys.push_back(key);
		}
	}

	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(), [](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
				updateKeyDown(key);
			else
				updateKeyUp(key);

			getMousePositionByWindow();

		}
		else
		{
			Clearkeys();
		}
	}

	bool Input::isKeyDown(eKeyCode keyCode)
	{
		return GetAsyncKeyState(ASCII[(UINT)keyCode]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = ekeyState::PRESSED;
		}
		else
		{
			key.state = ekeyState::DOWN;
		}
		key.bPressed = true;
	}

	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = ekeyState::UP;
		}
		else
		{
			key.state = ekeyState::NONE;
		}
		key.bPressed = false;
	}

	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(app.GetHwnd(), &mousePos);

		mMousePos.x = mousePos.x;
		mMousePos.y = mousePos.y;
	}

	void Input::Clearkeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == ekeyState::DOWN || key.state == ekeyState::PRESSED)
				key.state = ekeyState::UP;
			else if (key.state == ekeyState::UP)
				key.state = ekeyState::NONE;
			key.bPressed = false;
		}
	}
}
