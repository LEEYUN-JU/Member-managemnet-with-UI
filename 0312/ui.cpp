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
	CreateWindow(TEXT("static"), TEXT("▶ 회원 리스트"),WS_CHILD | WS_VISIBLE,
		10, 10, 150, 25, hwnd, (HMENU)0, 0, 0);

	g_hList1 = CreateWindow(WC_LISTVIEW, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		LVS_REPORT, 10, 30, 300, 400, hwnd, (HMENU)IDC_LIST1, 0, 0);

	LVCOLUMN COL;
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("인덱스");				// 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(g_hList1, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.cx = 200;
	COL.pszText = (LPWSTR)TEXT("이름");			// 두 번째 헤더
	COL.iSubItem = 1;
	SendMessage(g_hList1, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

	// 한줄이 모두 선택되도록 한다.
	//ListView_SetExtendedListViewStyle(g_hList1, LVS_EX_FULLROWSELECT);

	// 셀 사이에 격자를 보여준다.
	//ListView_SetExtendedListViewStyle(g_hList1, LVS_EX_GRIDLINES);

	// 체크 박스 이미지를 항목의 왼쪽에 보여준다.
	//ListView_SetExtendedListViewStyle(hList, LVS_EX_CHECKBOXES);

	// 헤더를 드래그해서 순서를 바꿀 수 있도록 한다.
	//ListView_SetExtendedListViewStyle(hList, LVS_EX_HEADERDRAGDROP);

	// 위 4 개의 확장 스타일 모두 지정
	ListView_SetExtendedListViewStyle(g_hList1, LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
}

void CreateMemberInfoList(HWND hwnd)
{
	CreateWindow(TEXT("static"), TEXT("▶ 회원 상세 리스트"), WS_CHILD | WS_VISIBLE,
		350, 10, 150, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("인덱스"), WS_CHILD | WS_VISIBLE,
		350, 40, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("이름"), WS_CHILD | WS_VISIBLE,
		350, 70, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("학교"), WS_CHILD | WS_VISIBLE,
		350, 100, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("학과"), WS_CHILD | WS_VISIBLE,
		350, 130, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("학번"), WS_CHILD | WS_VISIBLE,
		350, 160, 70, 25, hwnd, (HMENU)0, 0, 0);

	CreateWindow(TEXT("static"), TEXT("전화번호"), WS_CHILD | WS_VISIBLE,
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
	g_hUpdate = CreateWindow(TEXT("button"), TEXT("회원 정보 수정"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		350, 230, 110, 25, hwnd, (HMENU)IDC_BUTTON_UPDATE, 0, 0);

	g_hDelete = CreateWindow(TEXT("button"), TEXT("회원 정보 삭제"),
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
	//리스트뷰에 저장된 데이틀 삭제 
	ListView_DeleteAllItems(g_hList1);

	// 텍스트와 이미지를 가진 아이템들을 등록한다.
	for (int i = 0; i<(int)memberlist.size(); i++) 
	{
		MEMBER mem = memberlist[i];

		LVITEM LI;
		LI.mask = LVIF_TEXT;
		LI.iItem = i;			//행
		LI.iSubItem = 0;		//열
		TCHAR temp[10];
		wsprintf(temp, TEXT("%d"), i);
		LI.pszText = temp;
		ListView_InsertItem(g_hList1, &LI);	//행을 만들어서 저장

		//만들어진 행에 정보를 추가 
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
			//* 선택된 항목을 보여준다.
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


