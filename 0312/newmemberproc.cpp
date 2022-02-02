//newmemberproc.cpp
#include "std.h"

BOOL IsCheckInputData(const MEMBER *pmem)
{
	if (_tcslen(pmem->name) == 0)			return FALSE;
	if (_tcslen(pmem->uniname) == 0)		return FALSE;
	if (_tcslen(pmem->major) == 0)			return FALSE;
	if (pmem->number <= 0)					return FALSE;
	if (_tcslen(pmem->phone) == 0)			return FALSE;

	return TRUE;
}

BOOL CALLBACK NewMemberProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{	
	static MEMBER *pmember;		

	switch (msg)
	{
	case WM_INITDIALOG:
	{
		pmember = (MEMBER*)lParam;
		return TRUE;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			GetDlgItemText(hDlg, IDC_EDIT1, pmember->name, sizeof(pmember->name));
			GetDlgItemText(hDlg, IDC_EDIT2, pmember->uniname, sizeof(pmember->uniname));
			GetDlgItemText(hDlg, IDC_EDIT3, pmember->major, sizeof(pmember->major));
			pmember->number = GetDlgItemInt(hDlg, IDC_EDIT4, 0, 0);
			GetDlgItemText(hDlg, IDC_EDIT5, pmember->phone, sizeof(pmember->phone));
			if (IsCheckInputData(pmember) == TRUE)
				EndDialog(hDlg, IDOK);
			else
				MessageBox(hDlg, TEXT("모든 정보를 입력하세요"), TEXT("알림"), MB_OK);
			return TRUE;
		}
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		}
	}
	return FALSE;
}