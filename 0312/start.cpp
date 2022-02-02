//Start.cpp
#include "std.h"

#define TITLESTRING TEXT("0312 �������α׷�")


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
	// 1. ������ Ŭ���� ����� 
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

	// 2. ���(������Ʈ����)
	RegisterClass(&wc);

	// 3. ������ â ����� 
	HWND hwnd = CreateWindowEx(0,					// WS_EX_TOPMOST
		TEXT("first"),				// Ŭ���� ��
		TITLESTRING,				// ĸ�ǹ� ����
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	// �ʱ� ��ġ 
		0, 0,			// �θ� ������ �ڵ�, �޴� �ڵ�
		hInstance,		// WinMain�� 1��° �Ķ���� (exe �ּ�)
		0);			// ���� ����



	// 4. ������ �����ֱ�
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);


	// 5. Message 
	//5.1 �⺻���� �޽�������
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//5.2 ���޽ð� Ȱ�� ������ �޽��� ����
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
	else //���޽ð�(idle)
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