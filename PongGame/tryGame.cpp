#include "tryGame.h"

using namespace std;

tryGame::tryGame()
{
	UINT_PTR timerid = SetTimer(NULL, 0, 10, (TIMERPROC)&timeAction);
}

void tryGame::toString() {
	cout<< "Hello" << endl;
}

void tryGame::timeAction(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime) {
	pc->toString();
}


tryGame::~tryGame()
{
}
