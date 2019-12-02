// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <string>

typedef struct
{
	HWND hWnd;
	DWORD dwPid;
}WNDINFO;

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	WNDINFO* pInfo = (WNDINFO*)lParam;
	DWORD dwProcessId = 0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);

	if (dwProcessId == pInfo->dwPid)
	{
		wchar_t title_buffer[100] = { 0 };
		wchar_t class_buffer[100] = { 0 };
		GetWindowText(hWnd, title_buffer, 100);
		RealGetWindowClass(hWnd, class_buffer, 100);
		std::wstring title = title_buffer;
		std::wstring classname = class_buffer;
		if (title == L"登录" and classname == L"WeChatLoginWndForPC") {
			pInfo->hWnd = hWnd;
			return FALSE;
		}
		else if (title == L"微信" and classname == L"WeChatMainWndForPC") {
			pInfo->hWnd = hWnd;
			return FALSE;
		}
	}
	return TRUE;
}

HWND GetHwndByProcessId(DWORD dwProcessId)
{
	WNDINFO info = { 0 };
	info.hWnd = NULL;
	info.dwPid = dwProcessId;
	EnumWindows(EnumWindowsProc, (LPARAM)&info);
	return info.hWnd;
}

extern "C" __declspec(dllexport) long GetWndLeft(DWORD pId) {
	//MessageBox(NULL, std::to_wstring(pId).c_str(), NULL, 0);
	/*HWND hwnd = FindWindow(L"WeChatMainWndForPC", L"微信");
	if (!hwnd) {
		hwnd = FindWindow(L"WeChatLoginWndForPC", L"登录");
	}
	if (hwnd) {
		RECT rect;
		GetWindowRect(hwnd, &rect);
		return rect.left;
	}*/
	HWND hwnd = GetHwndByProcessId(pId);
	if (hwnd) {
		RECT rect;
		GetWindowRect(hwnd, &rect);
		return rect.left;
	}
	return 0;
}

extern "C" __declspec(dllexport) long GetWndTop(DWORD pId) {
	//MessageBox(NULL, std::to_wstring(pId).c_str(), NULL, 0);
	/*HWND hwnd = FindWindow(L"WeChatMainWndForPC", L"微信");
	if (!hwnd) {
		hwnd = FindWindow(L"WeChatLoginWndForPC", L"登录");
	}
	if (hwnd) {
		RECT rect;
		GetWindowRect(hwnd, &rect);
		return rect.top;
	}*/
	HWND hwnd = GetHwndByProcessId(pId);
	if (hwnd) {
		RECT rect;
		GetWindowRect(hwnd, &rect);
		return rect.top;
	}
	return 0;
}

extern "C" __declspec(dllexport) int GetWndActiveState(DWORD pId) {
	//MessageBox(NULL, std::to_wstring(pId).c_str(), NULL, 0);
	HWND hwnd = GetHwndByProcessId(pId);
	if (hwnd == GetForegroundWindow()) {
		return 1;
	}
	else if (hwnd == GetForegroundWindow()){
		return 1;
	}
	return 0;
}