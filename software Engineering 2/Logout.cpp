#include "Logout.h"
#include "LogoutUI.h"
using namespace std;

/*
	�Լ� �̸� : Logout
	���: ������
	�Ű�����: X
	��ȯ��: X
*/
Logout::Logout()
{
    LogoutUI* boundary = new LogoutUI(this);
    this->boundary = boundary;
}

/*
	�Լ� �̸� : getLogoutUI
	���: Boundary�� ȣ���ϱ� ���� �Լ� ����
	�Ű�����: X
	��ȯ��: LogoutUI* Ÿ���� boundary
*/
LogoutUI* Logout::getLogoutUI()
{
    return boundary;
}

/*
    �Լ� �̸� : logoutMember
    ���: �α׾ƿ��� ������ �����ϴ� ����
    �Ű�����: string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű� ����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void Logout::logoutMember(string& loginId, int& memberType) 
{
    loginId = "";   // �α׾ƿ� �� nowLogin = ""�� �ǵ����ֱ�
    memberType = 0; // �α׾ƿ� �� memberType�� ȸ�� ȸ���� �Ϲ� ȸ���� �ƴϹǷ� 0���� �ٲ��ֱ�
}