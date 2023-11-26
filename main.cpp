#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "autoClicker.h"

int main() {
	bool bStopAutoClicker = false;
	AutoClicker autoClicker;

	//create console
	FILE* f;
	AllocConsole();
	freopen_s(&f, "CONOUT$", "w", stdout);

	std::cout << "Press 'M' to toggle clicking.\n";
	std::cout << "Press 'END' to exit the program.\n";

	//while program is running
	while (!bStopAutoClicker) {
		if (GetAsyncKeyState('M') & 1) {
			std::cout << "Toggled on.\n";
			autoClicker.ToggleAutoClick();
		}
		else if (GetAsyncKeyState(VK_END) & 1) {
			bStopAutoClicker = true;
		}
	}

	//release console
	fclose(f);
	FreeConsole();
}