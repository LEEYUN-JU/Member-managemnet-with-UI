//Start.cpp
#include "std.h"

#define TITLESTRING TEXT("0312 관리프로그램")


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_NOTIFY:		return OnNotify(hwnd, wParam, lParam);
	case WM_APPLY:		return OnApply(hwnd, wParam, lParam);
	case WM_COMMAND:	return OnCommand(hwnd, wParam, lParam);
	case WM_CREATE:		return OnCreate(hwnd, wParam, lParam);
	case WM_DESTROY:	return OnDestroy(hwnd, wParam, lParam);
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine, int nShowCmd)
{
	// 1. 윈도우 클래스 만들기 
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;			// DefWindowProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName =  MAKEINTRESOURCE(IDR_MENU1);
	wc.style = 0;

	// 2. 등록(레지스트리에)
	RegisterClass(&wc);

	// 3. 윈도우 창 만들기 
	HWND hwnd = CreateWindowEx(0,					// WS_EX_TOPMOST
		TEXT("first"),				// 클래스 명
		TITLESTRING,				// 캡션바 내용
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	// 초기 위치 
		0, 0,			// 부모 윈도우 핸들, 메뉴 핸들
		hInstance,		// WinMain의 1번째 파라미터 (exe 주소)
		0);			// 생성 인자



	// 4. 윈도우 보여주기
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);


	// 5. Message 
	//5.1 기본적인 메시지루프
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//5.2 유휴시간 활용 가능한 메시지 루프
	/*
	MSG msg;
	while (true)
	{
	if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
	if (msg.message == WM_QUIT)
	break;
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	}
	else //유휴시간(idle)
	{
	HDC hdc = GetDC(0);
	SetPixel(hdc, rand() % 500, rand() % 400,
	RGB(rand() % 256, rand() % 256, rand() % 256));
	ReleaseDC(hwnd, hdc);
	}
	}
	*/
	return 0;
}