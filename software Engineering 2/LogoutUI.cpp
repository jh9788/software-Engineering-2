#include "LogoutUI.h"
#include "Logout.h"

/*
	�Լ� �̸� : LogoutUI
	���: ������
	�Ű�����: Logout* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
LogoutUI::LogoutUI(Logout* inputControl)
{
	control = inputControl;
}


/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
	��ȯ��: X
*/
void LogoutUI::init(ofstream* inputFout)
{
	fout = inputFout;
}


/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void LogoutUI::startInterface() 
{
    *fout << "2.2. �α׾ƿ�" << endl;  // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : requestLogout
    ���: �α׾ƿ� Boundary�� �Լ��ν�, �α׾ƿ��� Control�� �α׾ƿ��� ��û�ϴ� ����
    �Ű�����: string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void LogoutUI::requestLogout(string& loginId, string tempId, int& memberType) 
{
    Logout logout = Logout();   // logout ��ü ����

    logout.logoutMember(loginId, memberType);   // logoutMember �Լ� ȣ��

    _showLogoutId(tempId);
}

/*
    �Լ� �̸� : showLogoutId
    ���: �α׾ƿ� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string logoutId -> ���Ͽ� ������ id�� ���� �Ű�����
    ��ȯ��: X
*/
void LogoutUI::_showLogoutId(string logoutId)
{
    *fout << "> " << logoutId << endl << endl;    // ���Ͽ� ���� ����.
}
