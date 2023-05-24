#include "ApplicationInfoCollection.h"


/* ���� �� ������ �Լ� !! ���� ������ ���� ��ȸ */
void ApplicationInfoCollection::getAllApplicationInfoCollection()
{
    for (int i = 0; i < applicationInfoCollection.size(); i++) {
        applicationInfoCollection[i]->showApplicationInfo();
    }
}

ApplicationInfoCollection::ApplicationInfoCollection(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection) {
	memberCollection = inputMemberCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
}

string ApplicationInfoCollection::getApplicationInfo(string currentLoginId){

    string returnString = "";
    string id;
    
    
    
    for (auto it = applicationInfoCollection.begin(); it != applicationInfoCollection.end(); it++) {
        // ���� id�� ���� �ְ� �˻��Ǹ� �� �ֵ��� returnString�� �߰�
        if ((*it)->getGeneralId() == currentLoginId) {

            id = (*it)->getRecruitInfo()->getCompanyId();
            Member* member = memberCollection->findMemberById(id);

            returnString = returnString + "> " + member->getName() + " ";
           // returnString = returnString + member->getBusinessNum() + " "; //�̺κ� �� �ȵ� �� �� ���� �������̵� ����� �ƴ��� Ȯ���Ұ�
            returnString = returnString + (*it)->getRecruitInfo()->getWork() + " ";
            returnString = returnString + (*it)->getRecruitInfo()->getTargetNum() + " ";
            returnString = returnString + (*it)->getRecruitInfo()->getDeadline() + "\n";
        }
    }

    return returnString;

	
}


void ApplicationInfoCollection::addApplicationInfo(RecruitInfo* inputRecruitInfo, string currentLoginId)
{ 
	ApplicationInfo* applicationInfo = new ApplicationInfo(inputRecruitInfo, currentLoginId);
	applicationInfoCollection.push_back(applicationInfo);
}


string ApplicationInfoCollection::removeApplicationInfo(string currentLoginId, string inputBusinessNum) {
    
    string returnString = "";
    string id;
    // applicationInfoCollection�� �ִ� �ֵ��� �� ó������ ���������� ����
    for (auto it = applicationInfoCollection.begin(); it != applicationInfoCollection.end(); it++) {

        
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
            applicationInfoCollection.erase(it);
            break;
        }
    }
    
    return returnString;
}