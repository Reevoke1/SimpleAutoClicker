#include "autoClicker.h"
#include <Windows.h>
#include <iostream>

AutoClicker::AutoClicker()
{
	//do nothing
}

void AutoClicker::ToggleAutoClick()
{
	//toggle hook
	bActive = !bActive;

	while (bActive)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(10);

		if (GetAsyncKeyState('M') & 1) {
			std::cout << "Toggled off.\n";
			bActive = !bActive;
			break;
		}
	}
}