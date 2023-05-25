#include "Withdraw.h"
#include "WithdrawUI.h"

/*
    �Լ� �̸� : Withdraw
    ��� : ������
    �Ű����� : 
    ��ȯ�� : X
*/
Withdraw::Withdraw(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection,
                   ApplicationInfoCollection* inputApplicationInfoCollection)
{
    memberCollection = inputMemberCollection;
    applicationInfoCollection = inputApplicationInfoCollection;
    recruitInfoCollection = inputRecruitInfoCollection;

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
    int tempMemberType = currentMemberType;

    // ȸ��ȸ���� Ż���� ���, ������ �÷ȴ� ��� ä�� ���� ����
    if (tempMemberType == 1) {
        // ȸ��ȸ���� Ż���ϴ� ��� applicationInfo collection���� ȸ�� ȸ�� ID�� ���� ������ ã��, ����
        applicationInfoCollection->removeAllApplicationInfoCompany(currentLoginId);
        recruitInfoCollection->removeAllRecruitInfo(currentLoginId);
    }
    else if (tempMemberType == 2) {
        // �Ϲ�ȸ���� Ż���ϴ� ��� applicationInfo collection���� ȸ�� ȸ�� ID�� ���� ������ ã��, ����
        applicationInfoCollection->removeAllApplicationInfo(currentLoginId);
    }

    memberCollection->removeMember(currentLoginId);      // �ش� id ����

    currentLoginId = "";           // ȸ�� Ż�� �� �α׾ƿ� ���·� �ǵ�����
    currentMemberType = 0;         // ȸ�� Ż�� �� ȸ�� ȸ���� �Ϲ� ȸ���� �ƴϹǷ� memberType = 0
}
