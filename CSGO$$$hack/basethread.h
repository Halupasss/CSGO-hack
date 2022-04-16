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
		virtual void run();
		virtual void stop();
	private:
		// �������� keyboardHandler
		virtual void initKeyboardHandler();
		// �������� ������� ������� ����
		// ��������� � callmodulemethods.cpp
		virtual void callModuleMethods();
		// �������� �� ��������� ������� �� ������� �������
		// ��������� � keyboardhandler.cpp
		virtual void keyboardHandler();
	public:
		C_Thread();
	};

	extern C_Thread *pThread;
}

#endif // !CSGO$$$HACK_BASETHREAD_H_