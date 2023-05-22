#include <iostream>
#include "Member.h"
#include "CompanyMember.h"
#include "GeneralMember.h"
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
void MemberCollection::addMember(string name, string number, string id, string password, int memType)
{
    Member* member;
    if(memType == 1){
        member = new CompanyMember(name, number, id, password, memType);
    }
    else{
        member = new GeneralMember(name, number, id, password, memType);
    }
	memberCollection.push_back(member);
}


/*
�Լ� �̸�: removeMember
���: ȸ���� memberCollection ���Ϳ� �����ϴ��� Ȯ���ϰ�, ���� �����Ѵٸ� �ش� ��ü�� �����Ѵ�.
�Ű�����: string memberId -> MemberId char �����Ͱ�
��ȯ��: X
*/
void MemberCollection::removeMember(string memberId) {
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ָ� ����
        if ((*it)->getId() == memberId) {
            delete* it;
            memberCollection.erase(it);
            break;
        }
    }
}


 
/*
�Լ� �̸�: isMember
���: �α��� ��, ������ ��ϵǾ��ִ� ȸ������ Ȯ���Ѵ�.
�Ű�����: string memberId -> MemberId char �����Ͱ�, string memberPassword -> MemberPassword char ������ ��
��ȯ��: bool
*/
bool MemberCollection::isMember(string memberId, string memberPassword) {
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId() == memberId && (*it)->getPassword() == memberPassword) {
            return true;  // �ش� ����� ã�� ���, true return
        }
    }
    return false;  // ã�� ����� ���� ���, false return
}



/*
�Լ� �̸�: getMemberType
���: �α��� ��, ���� �α��� �� ����� member type�� Ȯ���Ѵ�.
�Ű�����: string memberId -> MemberId char �����Ͱ�, string memberPassword -> MemberPassword char ������ ��
��ȯ��: int
*/
int MemberCollection::getMemberType(string memberId, string memberPassword) {
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        if ((*it)->getId()== memberId  && (*it)->getPassword() == memberPassword) {
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





///*
//�Լ� �̸�: getRecruitInfo
//���: �α��� �� ����� ����� ��� ä�� ������ ��� ��ȯ�Ѵ�.
//�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID
//��ȯ��: string
//*/
//string MemberCollection::findMemberByName(string targetName)
//{
//    string returnString = "";
//    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
//        if ((*it)->getName() == targetName) {
//            (*it)->
//        }
//
//        return returnString;
//    }

string MemberCollection::findBusinessNumByName(string memberName)
{
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� name�� ���� ȸ���� ã����
        if ((*it)->getName() == memberName) {
            CompanyMember* companyMember = static_cast<CompanyMember*>(*it);
            return companyMember->getBusinessNum();
            }
    }
}

string MemberCollection::findIdByName(string memberName)
{
    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
        // ���� name�� ���� ȸ���� ã����
        if ((*it)->getName() == memberName) {
            Member* member = (*it);
            return member->getId();
        }
    }
}

