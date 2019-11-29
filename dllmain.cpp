// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) long GetWndLeft() {
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

extern "C" __declspec(dllexport) long GetWndTop() {
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