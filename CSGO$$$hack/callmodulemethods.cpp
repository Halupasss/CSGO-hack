#include "includes.h"

#include "glowesp.h"

// ����������� ����������
bool moduleconfig::glowesp = true;

void
basethread::C_Thread::callModuleMethods() {
	if (moduleconfig::glowesp) {
		glowesp::update();
	}
}