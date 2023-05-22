#include "AddRecruitInfo.h"
#include "AddRecruitInfoUI.h"

AddRecruitInfo::AddRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection) {
    recruitInfoCollection = inputRecruitInfoCollection;

    AddRecruitInfoUI* boundary = new AddRecruitInfoUI(this);
    this->boundary = boundary;
}

AddRecruitInfoUI* AddRecruitInfo::getAddRecruitInfoUI(){
    return boundary;
}

void AddRecruitInfo::addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId) {
    recruitInfoCollection->addRecruitInfo(work, targetNum, deadline, currentLoginId);  // recruitInfoCollection class�� ���� �ִ� addRecruitInfo�Լ� ȣ���Ͽ� RecruitInfo �߰�
}