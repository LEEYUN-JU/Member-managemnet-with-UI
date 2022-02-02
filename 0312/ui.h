//ui.h

/*******************************************************************************
��  �� : ������ ���� ��Ʈ�� ���� �� �ʱ�ȭ 
���ó : handler�� OnCreate
ȣ  �� : CreateMemberList, CreateMemberInfoList, CreateMemberButton
********************************************************************************/
void ui_CreateControl(HWND hwnd);

//����Ʈ�� ��Ʈ�� ���� �� �ʱ�ȭ
void CreateMemberList(HWND hwnd);

//����Ʈ ��Ʈ�� ���� �� �ʱ�ȭ
void CreateMemberInfoList(HWND hwnd);

//����, ���� ��ư ����
void CreateMemberButton(HWND hwnd);


/*******************************************************************************
��  �� : ����ڷκ��� ������ �Է¹޾� �ɹ��� ����
���ó : handler�� OnMenuAddMember
ȣ  �� : 
********************************************************************************/
BOOL ui_AddMember(HWND hwnd, MEMBER *pmem);

/*******************************************************************************
��  �� : ���޵� memberlist�� ��� ������ ����Ʈ�信 ���
���ó : handler�� OnMenuAddMember
ȣ  �� :
********************************************************************************/
void ui_ListViewUpdate(HWND hwnd, vector<MEMBER> memberlist);


/*******************************************************************************
��  �� : ȸ������ �� �̸� �� ���� ������ ȹ���Ͽ� ��ȯ�ϴ� ���
���ó : handler�� OnButtonUpdateMember
ȣ  �� :
********************************************************************************/
BOOL ui_GetInputUpdateMember(HWND hwnd, MEMBER *pmember);

BOOL ui_GetClickName(HWND hwnd, LPARAM lParam, TCHAR* name);