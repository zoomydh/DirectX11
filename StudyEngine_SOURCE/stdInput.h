#pragma once
#include "CommonInclude.h"

namespace study
{
	enum class ekeyState
	{
		DOWN,
		PRESSED,
		UP,
		NONE,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Up, Down,
		End,
	};

	class Input
	{
	public :
		struct Key
		{
			eKeyCode keyCode;
			ekeyState state;
			bool bPressed;
		};
		static void Initailize();
		static void Update();

		static bool GetKeyDown(eKeyCode key) { return mKeys[(UINT)key].state == ekeyState::DOWN; }
		static bool GetkeyUp(eKeyCode key) { return mKeys[(UINT)key].state == ekeyState::UP; }
		static bool Getkey(eKeyCode key) { return mKeys[(UINT)key].state == ekeyState::PRESSED; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode keyCode);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);

	private :
		static std::vector<Key> mKeys;
	};
}

