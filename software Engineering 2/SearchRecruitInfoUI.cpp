#include <string>
#include "SearchRecruitInfo.h"
#include "SearchRecruitInfoUI.h"

using namespace std;

/*
	�Լ� �̸� : SeacrhRecruitInfoUI
	���: ������
	�Ű�����: SearchRecruitInfo* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
SearchRecruitInfoUI::SearchRecruitInfoUI(SearchRecruitInfo* inputControl) {
	control = inputControl;
}

/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
	��ȯ��: X
*/
void SearchRecruitInfoUI::init(ofstream* inputFout) {
	fout = inputFout;
}

/*
	�Լ� �̸� : startInterface
	���: ������ �Է��� ���� ȭ�鿡 ����
	�Ű�����: X
	��ȯ��: X
*/
void SearchRecruitInfoUI::startInterface() {
	*fout << "4.1. ä�� ���� �˻�" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

/*
	�Լ� �̸� : requestSearchRecruitInfo
	���: �Ϲ� ȸ���� ä�� ���� �˻��� ��û
	�Ű�����: string inputEvent -> �Է��� �� ���� ���ڿ�, string currentLoginId -> ���� �α��� �� ����� ID�� �Ű������� ����
	��ȯ��: X
*/
void SearchRecruitInfoUI::requestSearchRecruitInfo(string inputEvent) {
	stringstream input(inputEvent);
	string num1, num2, name;

	input >> num1 >> num2 >> name;

	
	string returnString = control->searchRecruitInfo(name);
	*fout << returnString << endl;
}

//void SearchRecruitInfoUI::showSearchRecruitInfo(string inputEvent)
//{
//	*fout << inputEvent << endl;
//}

