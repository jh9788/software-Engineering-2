#include "ViewApplicationInfoUI.h"
#include "ViewApplicationInfo.h"

/*
	�Լ� �̸� : ViewApplicationInfoUI
	���: ������
	�Ű�����: ViewApplicationInfo* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
ViewApplicationInfoUI::ViewApplicationInfoUI(ViewApplicationInfo* inputControl) 
{
	control = inputControl;
}
/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
	��ȯ��: X
*/
void ViewApplicationInfoUI::init(ofstream* inputFout) 
{
	fout = inputFout;
}
/*
	�Լ� �̸� : startInterface
	���: ������ �Է��� ���� ȭ�鿡 ����
	�Ű�����: X
	��ȯ��: X
*/
void ViewApplicationInfoUI::startInterface() 
{
	*fout << "4.3. ���� ���� ��ȸ" << endl;
}

/*
	�Լ� �̸� : showApplicationInfo
	���: �Ϲ� ȸ���� ���������� ��� ȭ�鿡 ����
	�Ű�����: string currentLoginId -> ���� �α��� �� ����� ID
	��ȯ��: X
*/
void ViewApplicationInfoUI::showApplicationInfo(string currentLoginId) 
{

	string returnString = control->viewApplicationList(currentLoginId);

	*fout << returnString << endl;

}