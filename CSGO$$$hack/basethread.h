#pragma once
#include <Windows.h>

#ifndef CSGO$$$HACK_BASETHREAD_H_
#define CSGO$$$HACK_BASETHREAD_H_

// ��������� ������, ��� �������� stopped ����� �� ����� �����������
enum class ThreadState
{
	running,
	stopped
};

namespace moduleconfig
{
	extern bool glowesp;
}

namespace basethread
{
	class C_Thread
	{
	private:
		HMODULE hModule;
		ThreadState state;
	public:
		void run(HMODULE hModule);
		void stop();
	private:
		uintptr_t __stdcall mainthread();
		// �������� keyboardHandler
		void initKeyboardHandler();
		// �������� ������� ������� ����
		// ��������� � callmodulemethods.cpp
		void callModuleMethods();
		// �������� �� ��������� ������� �� ������� �������
		// ��������� � keyboardhandler.cpp
		uintptr_t __stdcall keyboardHandler();
	public:
		C_Thread();
	};

	extern C_Thread *pThread;
}

#endif // !CSGO$$$HACK_BASETHREAD_H_