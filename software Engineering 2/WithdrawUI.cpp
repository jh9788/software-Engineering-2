#include "WithdrawUI.h"
#include "Withdraw.h"

/*
	�Լ� �̸� : WithdrawUI
	���: ������
	�Ű�����: Withdraw* inputControl -> ��Ʈ�� ������
	��ȯ��: X
*/
WithdrawUI::WithdrawUI(Withdraw* inputControl)
{
    control = inputControl;
}

/*
	�Լ� �̸� : init
	���: ���� ���⸦ ���� ofstream ���� ����
	�Ű�����: ofstream* inputFout -> ofstream ������
    ��ȯ��: X
*/
void WithdrawUI::init(ofstream* inputFout)
{
	fout = inputFout;
}

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void WithdrawUI::startInterface() 
{
    *fout << "1.2. ȸ��Ż��" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : requestWithdraw
    ���: ȸ��Ż�� Boundary�� �Լ��ν�, ȸ��Ż���� Control�� ȸ��Ż�� ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� Ż�� ��û�� ȸ���� ã��, ������ �����ϱ� ���� �Ű������� ����
              string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void WithdrawUI::requestWithdraw(string& loginId, int& memberType) 
{
    control->withdrawMember( loginId, memberType);     // ȸ�� Ż�� ���� �Լ� ȣ��
}

/*
    �Լ� �̸� : showWithdrawId
    ���: ȸ�� Ż�� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string withdrawId -> ���Ͽ� ������ id�� ���� �Ű�����
    ��ȯ��: X
*/
void WithdrawUI::showWithdrawId(string withdrawId) 
{
    *fout << "> " << withdrawId << endl << endl;        // ���Ͽ� ���� ����
}
