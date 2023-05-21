#include <iostream>
#include "Member.h"
#include "MemberCollection.h"


/* ���� �� ������ �Լ� !! ���� ��ϵ� ��� ȸ�� ��ȸ */
void MemberCollection::getAllMemberCollection()
{
    for (int i = 0; i < memberCollection.size(); i++) {
        memberCollection[i]->showMemberInfo();
    }
}


/*
�Լ� �̸�: addMember
���: Member ��ü�� �Ű������� �޾Ƽ� ���Ϳ� ���������� �ִ´�.
�Ű�����: Member* member -> Member ��ü �����Ͱ�
��ȯ��: X
*/
void MemberCollection::addMember(Member* member)
{
	memberCollection.push_back(member);
}


/*
�Լ� �̸�: removeMember
���: ȸ���� memberCollection ���Ϳ� �����ϴ��� Ȯ���ϰ�, ���� �����Ѵٸ� �ش� ��ü�� �����Ѵ�.
�Ű�����: const char* memberId -> MemberId char �����Ͱ�
��ȯ��: X
*/
void MemberCollection::removeMember(const char* memberId) {
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ָ� ����
        if (strcmp((*it)->getId(), memberId) == 0) {
            delete* it;
            memberCollection.erase(it);
            break;
        }
    }
}


 
/*
�Լ� �̸�: isMember
���: �α��� ��, ������ ��ϵǾ��ִ� ȸ������ Ȯ���Ѵ�.
�Ű�����: const char* memberId -> MemberId char �����Ͱ�, const char* memberPassword -> MemberPassword char ������ ��
��ȯ��: bool
*/
bool MemberCollection::isMember(const char* memberId, const char* memberPassword) {
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if (strcmp((*it)->getId(), memberId) == 0 && strcmp((*it)->getPassword(), memberPassword) == 0) {
            return true;  // �ش� ����� ã�� ���, true return
        }
    }
    return false;  // ã�� ����� ���� ���, false return
}



/*
�Լ� �̸�: getMemberType
���: �α��� ��, ���� �α��� �� ����� member type�� Ȯ���Ѵ�.
�Ű�����: const char* memberId -> MemberId char �����Ͱ�, const char* memberPassword -> MemberPassword char ������ ��
��ȯ��: int
*/
int MemberCollection::getMemberType(const char* memberId, const char* memberPassword) {
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if (strcmp((*it)->getId(), memberId) == 0 && strcmp((*it)->getPassword(), memberPassword) == 0) {
            return (*it)->getMemberType();  // �ش� ����� ã�� ���, memberType return
        }
    }
    return 0;  // ã�� ����� ���� ���
}



/*
�Լ� �̸�: ~MemberCollection
���: �Ҹ���
�Ű�����: X
��ȯ��: X
*/
MemberCollection::~MemberCollection()
{
	for (int i = 0; i < memberCollection.size(); i++)
		memberCollection.pop_back();
}
