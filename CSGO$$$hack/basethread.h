#pragma once

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
		ThreadState state;
	public:
		void run();
		void stop();
	private:
		// �������� keyboardHandler
		void initKeyboardHandler();
		// �������� ������� ������� ����
		// ��������� � callmodulemethods.cpp
		void callModuleMethods();
		// �������� �� ��������� ������� �� ������� �������
		// ��������� � keyboardhandler.cpp
		void keyboardHandler();
	public:
		C_Thread();
	};

	extern C_Thread *pThread;
}

#endif // !CSGO$$$HACK_BASETHREAD_H_