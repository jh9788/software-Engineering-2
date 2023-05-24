#include "ApplicationInfoCollection.h"


/* ���� �� ������ �Լ� !! ���� ������ ���� ��ȸ */
void ApplicationInfoCollection::getAllApplicationInfoCollection()
{
    for (int i = 0; i < ownedApplicationinfo.size(); i++) {
        ownedApplicationinfo[i]->showApplicationInfo();
    }
}

ApplicationInfoCollection::ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection) {
	memberCollection = inputMemberCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
}


string ApplicationInfoCollection::getApplicationInfo(string currentLoginId){

    //string returnString = "";
    string id;
    string name;
    string work;
    string targetNum;
    string deadline;
    string returnString = "";
    
    sort(ownedApplicationinfo.begin(), ownedApplicationinfo.end());

    vector <string> forSort;

    for (auto it = ownedApplicationinfo.begin(); it != ownedApplicationinfo.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        cout << "currentLoginId : " << currentLoginId << endl;
        cout << "General ID : " << (*it)->getGeneralId();

        if ((*it)->getGeneralId() == currentLoginId) {
            string tempStr = "";

            id = (*it)->getRecruitInfo()->getCompanyId();
            Member* member = memberCollection->findMemberById(id);

            tempStr = tempStr + "> " + member->getName() + " ";
            tempStr = tempStr + member->getBusinessNum() + " ";
            tempStr = tempStr + (*it)->getRecruitInfo()->getWork() + " ";
            tempStr = tempStr + (*it)->getRecruitInfo()->getTargetNum() + " ";
            tempStr = tempStr + (*it)->getRecruitInfo()->getDeadline();

            forSort.push_back(tempStr);

            cout << "id : " << id << ", name : " << member->getName() << ", work: " << (*it)->getRecruitInfo()->getWork() << ", targetNum : " <<
                (*it)->getRecruitInfo()->getTargetNum() << ", Deadline : " << (*it)->getRecruitInfo()->getDeadline() << ", name : " << (*it)->getGeneralId();
        }
    }
    
    sort(forSort.begin(), forSort.end());
    for(int i = 0; i<forSort.size(); ++i){
        returnString += forSort[i];
        returnString += '\n';
    }

    return returnString;
}


void ApplicationInfoCollection::addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId)
{ 
	ApplicationInfo* applicationInfo = new ApplicationInfo(inputRecruitInfo, currentLoginId);
    ownedApplicationinfo.push_back(applicationInfo);
}


string ApplicationInfoCollection::removeApplicationInfo(string currentLoginId, string inputBusinessNum) {
    
    string returnString = "";
    string id;
    // applicationInfoCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = ownedApplicationinfo.begin(); it != ownedApplicationinfo.end(); it++) {

        
        string targetCompanyMemberId = memberCollection->findIdByBusinessNum(inputBusinessNum);
        RecruitInfo* targetRecruitInfo = recruitInfoCollection->findByCompanyId(targetCompanyMemberId);

        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ָ� ����
        if ((*it)->getGeneralId() == currentLoginId && (*it)->getRecruitInfo() == targetRecruitInfo) {

            id = (*it)->getRecruitInfo()->getCompanyId();
            Member* member = memberCollection->findMemberById(id);

            returnString =  returnString + "> " + member->getName() + " ";
            returnString = returnString + member->getBusinessNum() + " ";
            returnString = returnString + (*it)->getRecruitInfo()->getWork() + "\n";

            delete* it;
            ownedApplicationinfo.erase(it);
            break;
        }
    }
    
    return returnString;
}
map<string, int> ApplicationInfoCollection::calcAppliedRecruitInfoStats(string currentLoginId)
{
    map<string, int> recruitInfoStats;

    for (auto it = applicationInfoVec.begin(); it != applicationInfoVec.end(); ++it) {
        if ((*it)->getGeneralId() == currentLoginId) {
            string work = (*it)->getRecruitInfoWork();

            if (recruitInfoStats.find(work) == recruitInfoStats.end()) {
                recruitInfoStats[work] = 1;
            }
            else {
                recruitInfoStats[work] += 1;
            }
        }
    }

    return recruitInfoStats;
}
