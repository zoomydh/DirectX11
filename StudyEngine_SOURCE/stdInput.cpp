#include "stdInput.h"

namespace study
{
	std::vector<Input::Key> Input::mKeys = {};
	
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};
	
	void Input::Initailize()
	{

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = { };
			key.bPressed = false;
			key.state = ekeyState::NONE;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = ekeyState::PRESSED;
				}
				else
				{
					mKeys[i].state = ekeyState::DOWN;
				}

				mKeys[i].bPressed = true;
			}
			else
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = ekeyState::UP;
				}
				else
				{
					mKeys[i].state = ekeyState::NONE;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}


