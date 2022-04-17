#include "includes.h"
// ���� �������� �� ��������� ������� ���� ������� ������

#define ESCAPE_KEY VK_INSERT
// ���������� ����������� � ����� �������
#define MIL_SECOND 1000
// ���������� ����������� � ����� ������
#define MIL_MINUTE (60 * MIL_SECOND)
// �������� ���� ��� ����������� (������ - �������, ������ - ����������)
#define THREAD_DELAY MIL_SECOND // in milliseconds

uintptr_t __stdcall
basethread::C_Thread::keyboardHandler() {
	while (state == ThreadState::running) {
		if (GetAsyncKeyState(ESCAPE_KEY)) {
			state = ThreadState::stopped;
		}

		Sleep(THREAD_DELAY);
	}

	FreeLibraryAndExitThread(hModule, 0);
}