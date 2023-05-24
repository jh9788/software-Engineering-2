#include "AddRecruitInfo.h"
#include "AddRecruitInfoUI.h"


/*
    �Լ� �̸� : AddRecruitInfo
    ���: ������
    �Ű�����: RecruitInfoCollection* inputRecruitInfoCollection
    ��ȯ��: X
*/
AddRecruitInfo::AddRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection) 
{
    recruitInfoCollection = inputRecruitInfoCollection;

    // Boundary ����
    AddRecruitInfoUI* boundary = new AddRecruitInfoUI(this);
    this->boundary = boundary;
}


/*
    �Լ� �̸� : getAddRecruitInfoUI
    ���: Boundary�� ȣ���ϱ� ���� �Լ�
    �Ű�����: X
    ��ȯ��: AddRecruitInfoUI* Ÿ���� Boundary
*/
AddRecruitInfoUI* AddRecruitInfo::getAddRecruitInfoUI()
{
    return boundary;
}


/*
    �Լ� �̸� : addRecruitInfo
    ���: ä�� ���� ����� ���� �Լ�
    �Ű�����: string work -> ����, string targetNum -> �ο� ��, string deadline -> ��û ������, string currentLoginId -> ���� �α��� �� ����� ID�� �Ű������� ����
    ��ȯ��: X
*/
void AddRecruitInfo::addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId) 
{
    recruitInfoCollection->addRecruitInfo(work, targetNum, deadline, currentLoginId);  // recruitInfoCollection class�� ���� �ִ� addRecruitInfo�Լ� ȣ���Ͽ� RecruitInfo �߰�
}