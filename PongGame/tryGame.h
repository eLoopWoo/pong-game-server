#pragma once
#include <Windows.h>
#include <iostream>


class tryGame
{
public:
	tryGame();
	void toString();
	~tryGame();
	static void timeAction(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime);
};

tryGame * pc ;