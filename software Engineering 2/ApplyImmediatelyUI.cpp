#include <string>
#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

using namespace std;

/*
	�Լ� �̸� : ApplyImmediatelyUI
	���: ������
	�Ű�����: ApplyImmediately* inputControl -> Control ������
	��ȯ��: X
*/
ApplyImmediatelyUI::ApplyImmediatelyUI(ApplyImmediately* inputControl)
{
	control = inputControl;
}

/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
	��ȯ��: X
*/
void ApplyImmediatelyUI::init(ofstream* inputFout)
{
	fout = inputFout;
}

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void ApplyImmediatelyUI::startInterface()
{
	*fout << "4.2. ä�� ����" << endl;
}

/*
    �Լ� �̸� : showApplyImmediately
    ���: ä�� ���� �Ϸ� �����ֱ�
    �Ű�����: string inputEvent -> �Է��� �� ���� ���ڿ�, string currentLoginId -> ���� �α����� ID
    ��ȯ��: X
*/
void ApplyImmediatelyUI::showApplyImmediately(string inputEvent,string currentLoginId)
{
	stringstream input(inputEvent); // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
	string num1, num2, businessNum; // ������ �������� ������ string�� ����� ������ ����

	input >> num1 >> num2 >> businessNum; // ������ �������� ������ string�� ������ ���

	string returnString = control->applyImmediately(businessNum, currentLoginId); // Control�� �Լ��� applyImmediately ȣ�� 

	*fout <<  returnString << endl << endl; // ä�� ���� ���� ��, ���Ͽ� ����
}

