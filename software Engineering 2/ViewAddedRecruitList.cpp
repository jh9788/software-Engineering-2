#include "ViewAddedRecruitList.h"
#include "ViewAddedRecruitListUI.h"


/*
    �Լ� �̸� : ViewAddedRecruitList
    ���: ������
    �Ű�����: RecruitInfoCollection* inputRecruitInfoCollection
    ��ȯ��: X
*/
ViewAddedRecruitList::ViewAddedRecruitList(RecruitInfoCollection* inputRecruitInfoCollection) {
    recruitInfoCollection = inputRecruitInfoCollection;

    ViewAddedRecruitListUI* boundary = new ViewAddedRecruitListUI(this);
    this->boundary = boundary;
}


/*
    �Լ� �̸� : getViewAddedRecruitListUI
    ���: Boundary�� ȣ���ϱ� ���� �Լ�
    �Ű�����: X
    ��ȯ��: X
*/
ViewAddedRecruitListUI* ViewAddedRecruitList::getViewAddedRecruitListUI() {
    return boundary;
}



/*
    �Լ� �̸� : viewAddedRecruitList
    ���: currentLoginId�� ���� RecruitInfo�� ��ȯ�ϱ� ���� �Լ�
    �Ű�����: string currentLoginId
    ��ȯ��: string
*/
string ViewAddedRecruitList::viewAddedRecruitList(string currentLoginId) {
    string returnString = recruitInfoCollection->getRecruitInfo(currentLoginId);  // recruitInfoCollection���� �ش��ϴ� ���� ��� ��ȯ
    return returnString;
}