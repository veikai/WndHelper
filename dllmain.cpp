// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <string>

extern "C" __declspec(dllexport) long GetWndLeft(DWORD pId) {
	MessageBox(NULL, std::to_wstring(pId).c_str(), NULL, 0);
	HWND hwnd = FindWindow(L"WeChatMainWndForPC", L"微信");
	if (!hwnd) {
		hwnd = FindWindow(L"WeChatLoginWndForPC", L"登录");
	}
	if (hwnd) {
		RECT rect;
		GetWindowRect(hwnd, &rect);
		return rect.left;
	}
	return 0;
}

extern "C" __declspec(dllexport) long GetWndTop(DWORD pId) {
	MessageBox(NULL, std::to_wstring(pId).c_str(), NULL, 0);
	HWND hwnd = FindWindow(L"WeChatMainWndForPC", L"微信");
	if (!hwnd) {
		hwnd = FindWindow(L"WeChatLoginWndForPC", L"登录");
	}
	if (hwnd) {
		RECT rect;
		GetWindowRect(hwnd, &rect);
		return rect.top;
	}
	return 0;
}

extern "C" __declspec(dllexport) int GetWndActiveState(DWORD pId) {
	MessageBox(NULL, std::to_wstring(pId).c_str(), NULL, 0);
	if (FindWindow(L"WeChatMainWndForPC", L"微信") == GetForegroundWindow()) {
		return 1;
	}
	else if (FindWindow(L"WeChatLoginWndForPC", L"登录") == GetForegroundWindow()){
		return 1;
	}
	return 0;
}