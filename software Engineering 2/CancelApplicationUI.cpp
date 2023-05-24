#include "CancelApplicationUI.h"
#include "CancelApplication.h"

/*
	�Լ� �̸� : CancelApplicationUI
	���: ������
	�Ű�����: CancelApplication* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
CancelApplicationUI::CancelApplicationUI(CancelApplication* inputControl) 
{
	control = inputControl;
}
/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
	��ȯ��: X
*/
void CancelApplicationUI::init(ofstream* inputFout) 
{
	fout = inputFout;
}
/*
	�Լ� �̸� : startInterface
	���: ������ �Է��� ���� ȭ�鿡 ����
	�Ű�����: X
	��ȯ��: X
*/
void CancelApplicationUI::startInterface() 
{
	*fout << "4.4. ���� ���" << endl;
}

/*
	�Լ� �̸� : showCancelApplication
	���: �Ϲ� ȸ���� ������Ҹ� �ϰ� ��Ұ���� ���Ͽ� �Է��ϱ�
	�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID, string inputEvent ->  �Է��� �� ���� ���ڿ�
	��ȯ��: X
*/
void CancelApplicationUI::showCancelApplication(string currentLoginId, string inputEvent) 
{
	
	stringstream input(inputEvent);
	string num1, num2, businessNum;

	input >> num1 >> num2 >> businessNum;

	string returnString = control->viewCancelApplication(currentLoginId, businessNum);

	*fout << returnString << endl;

}

