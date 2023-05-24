#include "ApplicationInfoCollection.h"


ApplicationInfoCollection::ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection) 
{
	memberCollection = inputMemberCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
}


string ApplicationInfoCollection::getApplicationInfo(string currentLoginId)
{

    //string returnString = "";
    string id;
    string name;
    string work;
    string targetNum;
    string deadline;
    string returnString = "";
    
    sort(ownedApplicationInfo.begin(), ownedApplicationInfo.end());

    vector <string> forSort;

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end(); it++) {
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
    ownedApplicationInfo.push_back(applicationInfo);
}

//지원 취소
string ApplicationInfoCollection::removeApplicationInfo(string currentLoginId, string inputBusinessNum) 
{
    
    string returnString = "";
    string id;
    // applicationInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end(); it++) {

        
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
            ownedApplicationInfo.erase(it);
            break;
        }
    }
    
    return returnString;
}

//회원 탈퇴 시 일반 회원의 모든 지원 정보 삭제
void ApplicationInfoCollection::removeAllApplicationInfo(string currentLoginId) 
{
    // applicationInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    
    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end();) {
        cout << "\n-------------------------\n";
        cout << (*it)->getGeneralId() << "\n";
        cout << currentLoginId << "\n";

        // 만약 id가 같은 애가 검색되면 그 애를 삭제
        if ((*it)->getGeneralId() == currentLoginId) {
            delete *it;      
            it = ownedApplicationInfo.erase(it);
        }
        else {
            it++;
        }
    }

    return;
}

map<string, int> ApplicationInfoCollection::calcAppliedRecruitInfoStats(string currentLoginId)
{
    map<string, int> recruitInfoStats;

    for (auto it = ownedApplicationInfo.begin(); it != ownedApplicationInfo.end(); ++it) {
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
