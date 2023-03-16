#pragma once
#include <windows.h>
#include <stdlib.h>

inline void ClearUI() {
	unsigned long dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 300 * 300, { 0, 0 }, &dw);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//1 : LEFT || 2 : RIGHT  || 3 : UP || 4 : DOWN
inline int getKey() {

	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		return 1;
	}
	
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		return 2;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return 3;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return 4;
	}

	return 0;
}