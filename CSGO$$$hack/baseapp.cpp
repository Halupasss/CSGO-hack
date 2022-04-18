#include "includes.h"

// modules config definition
bool moduleConfig::bhop = true;

C_BaseApp::C_BaseApp() {
	m_hModule = NULL;
	m_state = AppState::RUNNING;
}

C_BaseApp::C_BaseApp(HMODULE hModule) {
	this -> m_hModule = hModule;
	m_state = AppState::RUNNING;
}

void C_BaseApp::runModule(const std::string &moduleName) {
	if (!m_mapFunctions[moduleName]) {
		return;
	}
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)m_mapFunctions[moduleName], m_hModule, NULL, NULL);
}

void C_BaseApp::regModule(const std::string &moduleName, void* pFunction) {
	m_mapFunctions[moduleName] = pFunction;
}

void C_BaseApp::run() {
	regModule("basethread", (void*)basethread);
	runModule("basethread");
}

void C_BaseApp::stop() {
	m_state = AppState::STOPPED;
}

// �������� ������� ������ ���� (�������� glowesp, aimthread)
void C_BaseApp::callExternalMethods() {
	if (moduleConfig::bhop) {
		modules::bhop::update();
	}
}

// C_BaseApp getters
AppState C_BaseApp::getState() {
	return m_state;
}

C_LocalPlayer* C_BaseApp::getLocalPlayer() {
	return &m_localPlayer;
}

// C_BaseApp setters
void C_BaseApp::setState(const AppState state) {
	m_state = state;
}