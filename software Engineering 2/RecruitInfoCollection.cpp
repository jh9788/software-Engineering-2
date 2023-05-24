#include <iostream>
#include <string>
#include "RecruitInfo.h"
#include "RecruitInfoCollection.h"


/* ���� �� ������ �Լ� !! ���� ��ϵ� ��� ȸ�� ��ȸ */
void RecruitInfoCollection::getAllRecruitInfoCollection()
{
    for (int i = 0; i < ownedRecruitInfo.size(); i++) {
        ownedRecruitInfo[i]->showRecruitInfo();
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
    ownedRecruitInfo.push_back(recruitInfo);
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
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
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

	// ���� �ð��� �޾ƿɴϴ�.
	auto now = chrono::system_clock::now();
	time_t now_time_t = chrono::system_clock::to_time_t(now);
	tm now_tm = {};
	localtime_s(&now_tm, &now_time_t);

	// memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
	for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
		// ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
		if ((*it)->getCompanyId() == currentLoginId) {
			// �Էµ� ���ڿ��� �ð����� ��ȯ�մϴ�.
			istringstream dateDeadline(((*it)->getDeadline()));
			tm input_tm = {};
			dateDeadline >> get_time(&input_tm, "%Y/%m/%d"); // ������ "YYYY/MM/DD"
			// �Էµ� ��¥�� ���纸�� �������� Ȯ���մϴ�.
			if (input_tm.tm_year > now_tm.tm_year) {
				returnString = returnString + (*it)->getWork() + " ";
				returnString = returnString + (*it)->getTargetNum() + " ";
				returnString = returnString + (*it)->getDeadline() + "\n";
				return returnString;
			}
			else if (input_tm.tm_year == now_tm.tm_year) {
				if (input_tm.tm_mon > now_tm.tm_mon) {
					returnString = returnString + (*it)->getWork() + " ";
					returnString = returnString + (*it)->getTargetNum() + " ";
					returnString = returnString + (*it)->getDeadline() + "\n";
					return returnString;
				}
				else if (input_tm.tm_mon == now_tm.tm_mon) {
					if (input_tm.tm_mday >= now_tm.tm_mday) {
						returnString = returnString + (*it)->getWork() + " ";
						returnString = returnString + (*it)->getTargetNum() + " ";
						returnString = returnString + (*it)->getDeadline() + "\n";
						return returnString;
					}
				}
			}
		}
	}

	return returnString;

}

RecruitInfo* RecruitInfoCollection::findRecruitInfoById(string companyId)
{
    for (auto& recruitInfo : ownedRecruitInfo) {
        if (recruitInfo->getCompanyId() == companyId) {
            return recruitInfo;
        }
    }
    return nullptr;
}

string RecruitInfoCollection::findWorkById(string companyId)
{
    // memberCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        if ((*it)->getCompanyId() == companyId) {
            return (*it)->getWork();
        }
    }

    return "";
}

RecruitInfo* RecruitInfoCollection::findByCompanyId(string companyId) {
    for (auto it = ownedRecruitInfo.begin(); it != ownedRecruitInfo.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        if ((*it)->getCompanyId() == companyId) {
            return *it;
        }
    }

    return NULL; //�߰����� ��������
}

/*
�Լ� �̸�: ~RecruitInfoCollection
���: �Ҹ���
�Ű�����: X
��ȯ��: X
*/
RecruitInfoCollection::~RecruitInfoCollection()
{
    for (int i = 0; i < ownedRecruitInfo.size(); i++)
        ownedRecruitInfo.pop_back();
}
