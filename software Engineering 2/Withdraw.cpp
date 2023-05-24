#include "Withdraw.h"
#include "WithdrawUI.h"

/*
    �Լ� �̸� : Withdraw
    ��� : ������
    �Ű����� : 
    ��ȯ�� : X
*/
Withdraw::Withdraw(MemberCollection* inputMemberCollection, ApplicationInfoCollection* inputApplicationInfoCollection)
{
    memberCollection = inputMemberCollection;
    applicationInfoCollection = inputApplicationInfoCollection;

	WithdrawUI* boundary = new WithdrawUI(this);
    this->boundary = boundary;
}

/*
	�Լ� �̸� : getWithdrawUI
	��� : 
	�Ű����� : X
	��ȯ�� : WithdrawUI* Ÿ���� boundary
*/
WithdrawUI* Withdraw::getWithdrawUI() 
{
	return boundary;
}

/*
    �Լ� �̸� : withdrawMember
    ���: ȸ��Ż�� ������ �����ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� Ż�� ��û�� ȸ���� ã��, ������ �����ϱ� ���� �Ű������� ����
              string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void Withdraw::withdrawMember(string& currentLoginId, int& currentMemberType) 
{
    applicationInfoCollection->removeAllApplicationInfo(currentLoginId);
    memberCollection->removeMember(currentLoginId);      // �ش� id ����

    currentLoginId = "";           // ȸ�� Ż�� �� �α׾ƿ� ���·� �ǵ�����
    currentMemberType = 0;         // ȸ�� Ż�� �� ȸ�� ȸ���� �Ϲ� ȸ���� �ƴϹǷ� memberType = 0
}
