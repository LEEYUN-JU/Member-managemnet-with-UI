//member.h
//�̸�, �б�, �а�, �й�, ��ȭ��ȣ
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
