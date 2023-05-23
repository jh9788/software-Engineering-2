#include "ApplicationInfoCollection.h"

ApplicationInfoCollection::ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection) {
	memberCollection = inputMemberCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
}

string ApplicationInfoCollection::getApplicationInfo(string currentLoginId){

    string returnString = "";
    string id;
    
    
    
    for (auto it = applicationInfoCollection.begin(); it != applicationInfoCollection.end(); it++) {
        // 만약 id가 같은 애가 검색되면 그 애들을 returnString에 추가
        if ((*it)->getGeneralId() == currentLoginId) {

            id = (*it)->getRecruitInfo()->getCompanyId();
            Member* member = memberCollection->findMemberById(id);

            returnString = returnString + "> " + member->getName() + " ";
            returnString = returnString + member->getBusinessNum() + " "; //이부분 잘 안될 수 도 있음 오버라이딩 제대로 됐는지 확인할것
            returnString = returnString + (*it)->getRecruitInfo()->getWork() + " ";
            returnString = returnString + (*it)->getRecruitInfo()->getTargetNum() + " ";
            returnString = returnString + (*it)->getRecruitInfo()->getDeadline() + "\n";
        }
    }

    return returnString;

	
}


void ApplicationInfoCollection::addApplicationInfo(string currentLoginId) {

}


string ApplicationInfoCollection::removeApplicationInfo(string currentLoginId, string inputBusinessNum) {
    
    string returnString = "";
    string id;
    // applicationInfoCollection에 있는 애들을 맨 처음부터 순차적으로 살핌
    for (auto it = applicationInfoCollection.begin(); it != applicationInfoCollection.end(); it++) {

        
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
            applicationInfoCollection.erase(it);
            break;
        }
    }
    
    return returnString;
}