//ui.cpp
#include "std.h"

HWND g_hList1;
HWND g_hIdx, g_hName, g_Uniname, g_hMajor, g_hNumber, g_hPhone;
HWND g_hUpdate, g_hDelete;

void ui_CreateControl(HWND hwnd)
{
	InitCommonControls();
	CreateMemberList(hwnd);
	CreateMemberInfoList(hwnd);
	CreateMemberButton(hwnd);
}

void CreateMemberList(HWND hwnd)
{
	CreateWindow(TEXT("static"), TEXT("�� ȸ�� ����Ʈ"),WS_CHILD | WS_VISIBLE,
		10, 10, 150, 25, hwnd, (HMENU)0, 0, 0);

	g_hList1 = CreateWindow(WC_LISTVIEW, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		LVS_REPORT, 10, 30, 300, 400, hwnd, (HMENU)IDC_LIST1, 0, 0);

	LVCOLUMN COL;
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("�ε���");				// ù ��° ���
	COL.iSubItem = 0;
	SendMessage(g_hList1, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.cx = 200;
	COL.pszText = (LPWSTR)TEXT("�̸�");			// �� ��° ���
	COL.iSubItem = 1;
	SendMessage(g_hList1, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

	// ������ ��� ���õǵ��� �Ѵ�.
	//ListView_SetExtendedListViewStyle(g_hList1, LVS_EX_FULLROWSELECT);

	// �� ���̿� ���ڸ� �����ش�.
	//ListView_SetExtendedListViewStyle(g_hList1, LVS_EX_GRIDLINES);

	// üũ �ڽ� �̹����� �׸��� ���ʿ� �����ش�.
	//ListView_SetExtendedListViewStyle(hList, LVS_EX_CHECKBOXES);

	// ����� �巡���ؼ� ������ �ٲ� �� �ֵ��� �Ѵ�.
	//ListView_SetExtendedListViewStyle(hList, LVS_EX_HEADERDRAGDROP);

	// �� 4 ���� Ȯ�� ��Ÿ�� ��� ����
	ListView_SetExtendedListViewStyle(g_hList1, LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
}

void CreateMemberInfoList(HWND hwnd)
{
	CreateWindow(TEXT("static"), TEXT("�� ȸ�� �� ����Ʈ"), WS_CHILD | WS_VISIBLE,
		350, 10, 150, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("�ε���"), WS_CHILD | WS_VISIBLE,
		350, 40, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("�̸�"), WS_CHILD | WS_VISIBLE,
		350, 70, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("�б�"), WS_CHILD | WS_VISIBLE,
		350, 100, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("�а�"), WS_CHILD | WS_VISIBLE,
		350, 130, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("�й�"), WS_CHILD | WS_VISIBLE,
		350, 160, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("��ȭ��ȣ"), WS_CHILD | WS_VISIBLE,
		350, 190, 70, 25, hwnd, (HMENU)0, 0, 0);

	//Edit
	g_hIdx = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER |ES_READONLY,
		420, 40, 150, 25, hwnd, (HMENU)IDC_EDIT_IDX, 0, 0);

	g_hName = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY,
		420, 70, 150, 25, hwnd, (HMENU)IDC_EDIT_NAME, 0, 0);

	g_Uniname = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
		420, 100, 150, 25, hwnd, (HMENU)IDC_EDIT_UNINAME, 0, 0);

	g_hMajor = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
		420, 130, 150, 25, hwnd, (HMENU)IDC_EDIT_MAJOR, 0, 0);

	g_hNumber = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY,
		420, 160, 150, 25, hwnd, (HMENU)IDC_EDIT_NUMBER, 0, 0);

	g_hPhone = CreateWindow(TEXT("edit"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_BORDER,
		420, 190, 150, 25, hwnd, (HMENU)IDC_EDIT_PHONE, 0, 0);


}

void CreateMemberButton(HWND hwnd)
{
	g_hUpdate = CreateWindow(TEXT("button"), TEXT("ȸ�� ���� ����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		350, 230, 110, 25, hwnd, (HMENU)IDC_BUTTON_UPDATE, 0, 0);

	g_hDelete = CreateWindow(TEXT("button"), TEXT("ȸ�� ���� ����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		460, 230, 110, 25, hwnd, (HMENU)IDC_BUTTON_DELETE, 0, 0);
}

BOOL ui_AddMember(HWND hwnd, MEMBER *pmem)
{
	UINT ret = DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1), hwnd, NewMemberProc,
		(LPARAM)pmem);
	if (ret == IDOK)
	{
		return TRUE;
	}
	return FALSE;
}

void ui_ListViewUpdate(HWND hwnd, vector<MEMBER> memberlist)
{
	//����Ʈ�信 ����� ����Ʋ ���� 
	ListView_DeleteAllItems(g_hList1);

	// �ؽ�Ʈ�� �̹����� ���� �����۵��� ����Ѵ�.
	for (int i = 0; i<(int)memberlist.size(); i++) 
	{
		MEMBER mem = memberlist[i];

		LVITEM LI;
		LI.mask = LVIF_TEXT;
		LI.iItem = i;			//��
		LI.iSubItem = 0;		//��
		TCHAR temp[10];
		wsprintf(temp, TEXT("%d"), i);
		LI.pszText = temp;
		ListView_InsertItem(g_hList1, &LI);	//���� ���� ����

		//������� �࿡ ������ �߰� 
		ListView_SetItemText(g_hList1, i, 1, mem.name);
	}
}


BOOL ui_GetInputUpdateMember(HWND hwnd, MEMBER *pmember)
{
	GetDlgItemText(hwnd, IDC_EDIT_NAME, pmember->name, sizeof(TCHAR)* 20);
	if (_tcslen(pmember->name) > 0)
	{
		GetDlgItemText(hwnd, IDC_EDIT_UNINAME, pmember->uniname, sizeof(TCHAR)* 30);
		GetDlgItemText(hwnd, IDC_EDIT_MAJOR, pmember->major, sizeof(TCHAR)* 20);
		GetDlgItemText(hwnd, IDC_EDIT_PHONE, pmember->phone, sizeof(TCHAR)* 20);
		return TRUE;
	}
	else
		return FALSE;
}

BOOL ui_GetClickName(HWND hwnd, LPARAM lParam, TCHAR* name)
{
	LPNMHDR hdr;
	LPNMLISTVIEW nlv;
	hdr = (LPNMHDR)lParam;
	nlv = (LPNMLISTVIEW)lParam;
	if (hdr->hwndFrom == g_hList1)
	{
		switch (hdr->code)
		{
			//* ���õ� �׸��� �����ش�.
		case LVN_ITEMCHANGED:
			if (nlv->uChanged == LVIF_STATE && nlv->uNewState ==
				(LVIS_SELECTED | LVIS_FOCUSED))
			{
				ListView_GetItemText(g_hList1, nlv->iItem, 1, name, sizeof(name));
				return TRUE;
			}
			break;
		}
	}
	return FALSE;
}


