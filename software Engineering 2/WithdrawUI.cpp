

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void WithdrawUI::startInterface() {
    fout << "1.2. ȸ��Ż��" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : requestWithdraw
    ���: ȸ��Ż�� Boundary�� �Լ��ν�, ȸ��Ż���� Control�� ȸ��Ż�� ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� Ż�� ��û�� ȸ���� ã��, ������ �����ϱ� ���� �Ű������� ����
              string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void WithdrawUI::requestWithdraw(MemberCollection& memberCollection, string& loginId, int& memberType) {
    Withdraw withdraw = Withdraw();     // withdraw ��ü ����
    withdraw.withdrawMember(memberCollection, loginId, memberType);     // ȸ�� Ż�� ���� �Լ� ȣ��
}

/*
    �Լ� �̸� : showWithdrawId
    ���: ȸ�� Ż�� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string withdrawId -> ���Ͽ� ������ id�� ���� �Ű�����
    ��ȯ��: X
*/
void WithdrawUI::showWithdrawId(string withdrawId) {
    fout << "> " << withdrawId << endl << endl;        // ���Ͽ� ���� ����
}
