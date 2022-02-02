//handler.cpp
#include "std.h"

vector<MEMBER> g_memberlist;

//모달리스(검색다이얼로그========================================
HWND g_hSelectMemberDlg;
TCHAR g_selectname[20];
//===============================================================

void OnMenuCloseWindow(HWND hwnd)
{
	SendMessage(hwnd, WM_CLOSE, 0, 0);
}

void OnMenuAddMember(HWND hwnd)
{
	MEMBER mem;
	if (ui_AddMember(hwnd, &mem) == TRUE)
	{
		g_memberlist.push_back(mem);
		ui_ListViewUpdate(hwnd, g_memberlist);
	}
	else
	{
		MessageBox(hwnd, TEXT("회원등록기능취소"), TEXT("알림"), MB_OK);
	}
}

void OnMenuSelectMember(HWND hwnd)
{
	if (g_hSelectMemberDlg == 0)
	{
		g_hSelectMemberDlg = CreateDialogParam(GetModuleHandle(0),
			MAKEINTRESOURCE(IDD_DIALOG2), hwnd, 
			SelectMemberProc, (LPARAM)g_selectname);
		ShowWindow(g_hSelectMemberDlg, SW_SHOW);
	}
	else
	{
		SetFocus(g_hSelectMemberDlg);
	}
}

void OnButtonUpdateMember(HWND hwnd)
{
	MEMBER mem;
	if (ui_GetInputUpdateMember(hwnd, &mem) == TRUE)
	{
		int idx = member_select(g_memberlist, mem.name);
		if (idx >= 0)
		{
			member_update(&g_memberlist[idx], mem);
		}
	}
}

void OnButtonDeleteMember(HWND hwnd)
{
	MEMBER mem;
	if (ui_GetInputUpdateMember(hwnd, &mem) == TRUE)
	{
		int idx = member_select(g_memberlist, mem.name);
		if (idx >= 0)
		{
			member_delete(&g_memberlist, idx);
			ui_ListViewUpdate(hwnd, g_memberlist);
		}
	}
}

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case ID_40001: OnMenuCloseWindow(hwnd);					break;
	case ID_40002: OnMenuAddMember(hwnd);					break;
	case ID_40003: OnMenuSelectMember(hwnd);				break;
	case IDC_BUTTON_UPDATE: OnButtonUpdateMember(hwnd);		break;
	case IDC_BUTTON_DELETE:	OnButtonDeleteMember(hwnd);		break;
	}
	return 0;
}

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	ui_CreateControl(hwnd);
	return 0;
}

LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT OnApply(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	int idx = member_select(g_memberlist, g_selectname);
	if (idx == -1)
	{
		SetDlgItemText(hwnd, IDC_EDIT_IDX, TEXT(""));
		SetDlgItemText(hwnd, IDC_EDIT_NAME, TEXT(""));
		SetDlgItemText(hwnd, IDC_EDIT_UNINAME, TEXT(""));
		SetDlgItemText(hwnd, IDC_EDIT_MAJOR, TEXT(""));
		SetDlgItemText(hwnd, IDC_EDIT_NUMBER, TEXT(""));
		SetDlgItemText(hwnd, IDC_EDIT_PHONE, TEXT(""));

		MessageBox(hwnd, TEXT("해당정보가 없습니다."), TEXT("알림"), MB_OK);
		return 0;
	}

	MEMBER mem = g_memberlist[idx];
	SetDlgItemInt(hwnd, IDC_EDIT_IDX, idx, 0);
	SetDlgItemText(hwnd, IDC_EDIT_NAME, mem.name);
	SetDlgItemText(hwnd, IDC_EDIT_UNINAME, mem.uniname);
	SetDlgItemText(hwnd, IDC_EDIT_MAJOR, mem.major);
	SetDlgItemInt(hwnd, IDC_EDIT_NUMBER, mem.number, 0);
	SetDlgItemText(hwnd, IDC_EDIT_PHONE, mem.phone);
	return 0;
}

LRESULT OnNotify(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	TCHAR name[20];
	if (ui_GetClickName(hwnd, lParam, name) == TRUE)
	{
		int idx = member_select(g_memberlist, name);
		if (idx == -1)
		{
			SetDlgItemText(hwnd, IDC_EDIT_IDX, TEXT(""));
			SetDlgItemText(hwnd, IDC_EDIT_NAME, TEXT(""));
			SetDlgItemText(hwnd, IDC_EDIT_UNINAME, TEXT(""));
			SetDlgItemText(hwnd, IDC_EDIT_MAJOR, TEXT(""));
			SetDlgItemText(hwnd, IDC_EDIT_NUMBER, TEXT(""));
			SetDlgItemText(hwnd, IDC_EDIT_PHONE, TEXT(""));

			MessageBox(hwnd, TEXT("해당정보가 없습니다."), TEXT("알림"), MB_OK);
			return 0;
		}

		MEMBER mem = g_memberlist[idx];
		SetDlgItemInt(hwnd, IDC_EDIT_IDX, idx, 0);
		SetDlgItemText(hwnd, IDC_EDIT_NAME, mem.name);
		SetDlgItemText(hwnd, IDC_EDIT_UNINAME, mem.uniname);
		SetDlgItemText(hwnd, IDC_EDIT_MAJOR, mem.major);
		SetDlgItemInt(hwnd, IDC_EDIT_NUMBER, mem.number, 0);
		SetDlgItemText(hwnd, IDC_EDIT_PHONE, mem.phone);
	}
	
	return 0;
}