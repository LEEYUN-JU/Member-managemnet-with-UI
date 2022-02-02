//member.h
//이름, 학교, 학과, 학번, 전화번호
typedef struct tagMEMBER
{
	TCHAR name[20];
	TCHAR uniname[30];
	TCHAR major[20];
	int number;
	TCHAR phone[20];
}MEMBER;

int member_select(vector<MEMBER> memberlist, TCHAR* tname);
void member_update(MEMBER *pmem, MEMBER mem);
void member_delete(vector<MEMBER>* pmemberlist, int idx);
