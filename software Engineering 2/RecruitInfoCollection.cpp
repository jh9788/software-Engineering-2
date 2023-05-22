#include <iostream>
#include <string>
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"


/* ���� �� ������ �Լ� !! ���� ��ϵ� ��� ȸ�� ��ȸ */
void RecruitInfoCollection::getAllRecruitInfoCollection()
{
    for (int i = 0; i < recruitInfoCollection.size(); i++) {
        recruitInfoCollection[i]->showRecruitInfo();
    }
}


/*
�Լ� �̸�: getRecruitInfoCollectionSize
���: recruitInfoCollection�� ������ size�� ��ȯ
�Ű�����: X
��ȯ��: int
*/
int RecruitInfoCollection::getRecruitInfoCollectionSize() {
    return recruitInfoCollection.size();
}


/*
�Լ� �̸�: isMemberInRecruitInfoCollection
���: ȸ�� ȸ���� �ø� �Խù��� recruitInfoCollectin �ȿ� �ִ��� Ȯ��
�Ű�����: X
��ȯ��: bool
*/
bool RecruitInfoCollection::isMemberInRecruitInfoCollection(string companyId) {
    for (const auto& recruitInfo : recruitInfoCollection) {
        if (recruitInfo->getCompanyId() == companyId) {
            return true;
        }
    }
    return false;
}

/*
�Լ� �̸�: addRecruitInfo
���: recruitInfo ��ü�� �Ű������� �޾Ƽ� ���Ϳ� ���������� �ִ´�.
�Ű�����: string work -> ����, string targetNum -> �ο� ��, string deadline -> ��û ������, string currentLoginId -> ���� �α����� ID
��ȯ��: X
*/
void RecruitInfoCollection::addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId)
{
    RecruitInfo* recruitInfo = new RecruitInfo(work, targetNum, deadline, currentLoginId);
    recruitInfoCollection.push_back(recruitInfo);
}


/*
�Լ� �̸�: getRecruitAllInfo
���: Ư�� ä�� ������ ����, ��� ���� �����´�.
�Ű�����: RecruitInfo* recruitInfo -> RecruitInfo ��ü �����Ͱ�
��ȯ��: X
*/
string RecruitInfoCollection::getRecruitAllInfo(int index)
{
    string work = recruitInfoCollection[index]->getWork();
    string targetNum = recruitInfoCollection[index]->getTargetNum();
    string deadline = recruitInfoCollection[index]->getDeadline();

    return work + " " + targetNum + " " + deadline;
}



/*
�Լ� �̸�: removeMember
���: ȸ���� memberCollection ���Ϳ� �����ϴ��� Ȯ���ϰ�, ���� �����Ѵٸ� �ش� ��ü�� �����Ѵ�.
�Ű�����: const char* memberId -> MemberId char �����Ͱ�
��ȯ��: X
*/
//void MemberCollection::removeMember(const char* memberId) {
//    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ָ� ����
//        if (strcmp((*it)->getId(), memberId) == 0) {
//            delete* it;
//            memberCollection.erase(it);
//            break;
//        }
//    }
//}



/*
�Լ� �̸�: isMember
���: �α��� ��, ������ ��ϵǾ��ִ� ȸ������ Ȯ���Ѵ�.
�Ű�����: const char* memberId -> MemberId char �����Ͱ�, const char* memberPassword -> MemberPassword char ������ ��
��ȯ��: bool
*/
//bool MemberCollection::isMember(const char* memberId, const char* memberPassword) {
//    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        if (strcmp((*it)->getId(), memberId) == 0 && strcmp((*it)->getPassword(), memberPassword) == 0) {
//            return true;  // �ش� ����� ã�� ���, true return
//        }
//    }
//    return false;  // ã�� ����� ���� ���, false return
//}



/*
�Լ� �̸�: getMemberType
���: �α��� ��, ���� �α��� �� ����� member type�� Ȯ���Ѵ�.
�Ű�����: const char* memberId -> MemberId char �����Ͱ�, const char* memberPassword -> MemberPassword char ������ ��
��ȯ��: int
*/
//int MemberCollection::getMemberType(const char* memberId, const char* memberPassword) {
//    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
//    for (auto it = memberCollection.begin(); it != memberCollection.end(); it++) {
//        if (strcmp((*it)->getId(), memberId) == 0 && strcmp((*it)->getPassword(), memberPassword) == 0) {
//            return (*it)->getMemberType();  // �ش� ����� ã�� ���, memberType return
//        }
//    }
//    return 0;  // ã�� ����� ���� ���
//}



/*
�Լ� �̸�: ~RecruitInfoCollection
���: �Ҹ���
�Ű�����: X
��ȯ��: X
*/
RecruitInfoCollection::~RecruitInfoCollection()
{
    for (int i = 0; i < recruitInfoCollection.size(); i++)
        recruitInfoCollection.pop_back();
}
