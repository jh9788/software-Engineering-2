#include <string>
#include "ViewAddedRecruitList.h"
#include "ViewAddedRecruitListUI.h"
using namespace std;


/*
    �Լ� �̸� : ViewAddedRecruitListUI
    ���: ������
    �Ű�����: AddRecruitInfo* inputControl -> ��Ʈ�� ������
    ��ȯ��: X
*/
ViewAddedRecruitListUI::ViewAddedRecruitListUI(ViewAddedRecruitList* inputControl) {
    control = inputControl;
}


/*
    �Լ� �̸� : init
    ���: ���� ���⸦ ���� ofstream ���� ����
    �Ű�����: ofstream* inputFout -> ofstream ������
    ��ȯ��: X
*/
void ViewAddedRecruitListUI::init(ofstream* inputFout) {
    fout = inputFout;
}


/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void ViewAddedRecruitListUI::startInterface() {
    *fout << "3.2. ��ϵ� ä�� ���� ��ȸ" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}



/*
    �Լ� �̸� : showRecruitInfo
    ���: ȸ�� ȸ���� ����� ä�� ������ ��� ȭ�鿡 ����
    �Ű�����: string currentLoginId -> ���� �α��� �� ����� ID
    ��ȯ��: X
*/
void ViewAddedRecruitListUI::showRecruitInfo(string currentLoginId) {
    string returnString = control->viewAddedRecruitList(currentLoginId);       // recruitInfo�� ��� ������ returnString�� ��� ����

    *fout << returnString << endl;       // ä�� ���� ��� ���� ��, ���Ͽ� ����
}

