#pragma once
#include "Member.h"
#include <vector>

using namespace std;

/*
Ŭ���� �̸� : MemberCollection
��� : ��� ����Ʈ�� ���� �Ʒ� ����� ������
	   ����� ȸ�� ����, �α���, �α׾ƿ�, ȸ�� Ż�� �����Ѵ�.
	   ����� Ÿ���� Ȯ���Ѵ�.
*/
class MemberCollection
{
private:
	vector <Member*> memberCollection;

public:
	void getAllMemberCollection(); /* ���� �� ������ �Լ� !! */ // ���� ��ϵ� ȸ�� ��� ��� ��ȸ

	void addMember(Member* member);	// ȸ�� ���� ��, ȸ�� �߰�
	void removeMember(const char* memberId); // ȸ�� Ż�� ��, ȸ�� ����
	bool isMember(const char* memberId, const char* memberPassword); // ��ϵ� ȸ������ Ȯ�� (�α���)
	int getMemberType(const char* memberId, const char* memberPassword);	// ȸ�� ȸ������, �Ϲ� ȸ������ ������ �� �ִ� memberType�� ��������
	//void removeMember();
	//void findMemberByName();
	~MemberCollection();
};