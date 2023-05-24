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
�Լ� �̸�: getRecruitInfo
���: �α��� �� ����� ����� ��� ä�� ������ ��� ��ȯ�Ѵ�.
�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID
��ȯ��: string
*/
string RecruitInfoCollection::getRecruitInfo(string currentLoginId)
{
    string returnString = "";
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = recruitInfoCollection.begin(); it != recruitInfoCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        if ((*it)->getCompanyId() == currentLoginId) {
            returnString = returnString + "> " + (*it)->getWork() + " ";
            returnString = returnString + (*it)->getTargetNum() + " ";
            returnString = returnString + (*it)->getDeadline() + "\n";
        }
    }
    
    return returnString;
}

/*
�Լ� �̸�: getRecruitInfoWithoutSign
���: �α��� �� ����� ����� ��� ä�� ������ ��� ">" ��ȣ�� �����ϰ� ��ȯ�Ѵ�.
�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID
��ȯ��: string
*/
string RecruitInfoCollection::getRecruitInfoWithoutSign(string currentLoginId)
{
    string returnString = "";
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = recruitInfoCollection.begin(); it != recruitInfoCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        if ((*it)->getCompanyId() == currentLoginId) {
            returnString = returnString + (*it)->getWork() + " ";
            returnString = returnString + (*it)->getTargetNum() + " ";
            returnString = returnString + (*it)->getDeadline() + "\n";
        }
    }

    return returnString;

}

RecruitInfo* RecruitInfoCollection::findRecruitInfoById(string companyId)
{
    for (auto& recruitInfo : recruitInfoCollection) {
        if (recruitInfo->getCompanyId() == companyId) {
            return recruitInfo;
        }
    }
    return nullptr;
}

string RecruitInfoCollection::findWorkById(string companyId)
{
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = recruitInfoCollection.begin(); it != recruitInfoCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        if ((*it)->getCompanyId() == companyId) {
            return (*it)->getWork();
             
        }
    }

    return 0;
}

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


}


RecruitInfo* RecruitInfoCollection::findByCompanyId(string companyId) {
    for (auto it = recruitInfoCollection.begin(); it != recruitInfoCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        if ((*it)->getCompanyId() == companyId) {
            return *it;
        }
    }

    return NULL; //�߰����� ��������


}