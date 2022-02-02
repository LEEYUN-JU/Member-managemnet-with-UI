//ui.h

/*******************************************************************************
기  능 : 윈도우 폼에 컨트롤 생성 및 초기화 
사용처 : handler의 OnCreate
호  출 : CreateMemberList, CreateMemberInfoList, CreateMemberButton
********************************************************************************/
void ui_CreateControl(HWND hwnd);

//리스트뷰 컨트롤 생성 및 초기화
void CreateMemberList(HWND hwnd);

//에디트 컨트롤 생성 및 초기화
void CreateMemberInfoList(HWND hwnd);

//수정, 삭제 버튼 생성
void CreateMemberButton(HWND hwnd);


/*******************************************************************************
기  능 : 사용자로부터 정보를 입력받아 맴버를 저장
사용처 : handler의 OnMenuAddMember
호  출 : 
********************************************************************************/
BOOL ui_AddMember(HWND hwnd, MEMBER *pmem);

/*******************************************************************************
기  능 : 전달된 memberlist의 모든 정보를 리스트뷰에 출력
사용처 : handler의 OnMenuAddMember
호  출 :
********************************************************************************/
void ui_ListViewUpdate(HWND hwnd, vector<MEMBER> memberlist);


/*******************************************************************************
기  능 : 회원정보 중 이름 및 수정 정보를 획득하여 반환하는 기능
사용처 : handler의 OnButtonUpdateMember
호  출 :
********************************************************************************/
BOOL ui_GetInputUpdateMember(HWND hwnd, MEMBER *pmember);

BOOL ui_GetClickName(HWND hwnd, LPARAM lParam, TCHAR* name);