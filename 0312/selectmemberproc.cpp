//selectmemberproc.cpp
#include "std.h"

extern HWND g_hSelectMemberDlg;

BOOL CALLBACK SelectMemberProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static TCHAR *pname;

	switch (msg)
	{
	case WM_INITDIALOG:
	{
		pname = (TCHAR*)lParam;
		return TRUE;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			GetDlgItemText(hDlg, IDC_EDIT1, pname, sizeof(TCHAR)*20);
			if (_tcslen(pname) > 0)
			{
				SendMessage(GetParent(hDlg), WM_APPLY, 0, 0);
			}
			else
			{
				MessageBox(hDlg, TEXT("�̸��� �Է��ϼ���"), TEXT("�˸�"), MB_OK);
			}
		    return TRUE;
		}
		case IDCANCEL:
			g_hSelectMemberDlg = 0;
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
	}
	return FALSE;
}