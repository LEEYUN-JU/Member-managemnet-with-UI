//member.cpp
#include "std.h"

int member_select(vector<MEMBER> memberlist, TCHAR* tname)
{
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		MEMBER mem = memberlist[i];
		if (_tcscmp(mem.name, tname)==0)
			return i;
	}
	return -1;
}

void member_update(MEMBER *pmem, MEMBER mem)
{
	_tcscpy_s(pmem->uniname, mem.uniname);
	_tcscpy_s(pmem->major, mem.major);
	_tcscpy_s(pmem->phone, mem.phone);
}

void member_delete(vector<MEMBER>* pmemberlist, int idx)
{
	//vector 컨테이너가 갖고있는 배열의 첫번째 인덱스 주소
	vector<MEMBER>::iterator begin = pmemberlist->begin();

	//삭제(삭제할 주소로 이동하여 전달)
	pmemberlist->erase(begin + idx);
}