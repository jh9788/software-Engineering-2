#pragma once
#include "Member.h"
#include <string>
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

	void addMember(string name, string number, string id, string password, int memType);	// ȸ�� ���� ��, ȸ�� �߰�
	void removeMember(string memberId); // ȸ�� Ż�� ��, ȸ�� ����
	bool isMember(string memberId, string memberPassword); // ��ϵ� ȸ������ Ȯ�� (�α���)
	int getMemberType(string memberId, string memberPassword);	// ȸ�� ȸ������, �Ϲ� ȸ������ ������ �� �ִ� memberType�� ��������
	//void findMemberByName();
	Member* findMemberById(string memberId);
	string findBusinessNumByName(string memberName);
	string findIdByName(string memberName);
	~MemberCollection();
};