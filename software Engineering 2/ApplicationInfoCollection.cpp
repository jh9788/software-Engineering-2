#include "ApplicationInfoCollection.h"


/* 제출 시 삭제할 함수 !! 현재 지원한 정보 조회 */
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
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
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
    // applicationInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedApplicationinfo.begin(); it != ownedApplicationinfo.end(); it++) {

        
        string targetCompanyMemberId = memberCollection->findIdByBusinessNum(inputBusinessNum);
        RecruitInfo* targetRecruitInfo = recruitInfoCollection->findByCompanyId(targetCompanyMemberId);

        // 만약 id가 같은 애가 검색되면 그 애를 삭제
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
