#include <string>
#include "AddRecruitInfoUI.h"
#include "AddRecruitInfo.h"
using namespace std;


/*
	�Լ� �̸� : AddRecruitInfoUI
	���: ������
	�Ű�����: AddRecruitInfo* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
AddRecruitInfoUI::AddRecruitInfoUI(AddRecruitInfo* inputControl) {
	control = inputControl;
}

/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
	��ȯ��: X
*/
void AddRecruitInfoUI::init(ofstream* inputFout) {
	fout = inputFout;
}


/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void AddRecruitInfoUI::startInterface() {
    *fout << "3.1. ä�� ���� ���" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}


/*
    �Լ� �̸� : requestRecruitInfo
    ���: ������ ä������ ��� ��û�ϱ�
    �Ű�����: string inputEvent -> �Է��� �� ���� ���ڿ�, string currentLoginId -> ���� �α��� �� ����� ID�� �Ű������� ����
    ��ȯ��: X
*/
void AddRecruitInfoUI::requestRecruitInfo(string inputEvent, string currentLoginId) {
    // ������ ���� �Լ��� �Ű������� char* type�� �ֱ� ���� string �ڸ���
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, work, targetNum, deadline;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // ������ �������� ������ string�� ������ ���

    control->addRecruitInfo(work, targetNum, deadline, currentLoginId);     // Control�� �Լ��� addRecruitInfo ȣ��
}


/*
    �Լ� �̸� : showAddedRecruitInfo
    ���: ��ϵ� ä������ �����ֱ�
    �Ű�����: string inputEvent -> �Է��� �� ���� ���ڿ�
    ��ȯ��: X
*/
void AddRecruitInfoUI::showAddedRecruitInfo(string inputEvent) {
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, work, targetNum, deadline;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // ������ �������� ������ string�� ������ ���

    *fout << "> " << work << " " << targetNum << " " << deadline << endl << endl;       // ä�� ���� ��� ���� ��, ���Ͽ� ����
}
