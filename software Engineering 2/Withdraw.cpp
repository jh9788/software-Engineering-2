
/*
    �Լ� �̸� : withdrawMember
    ���: ȸ��Ż�� ������ �����ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� Ż�� ��û�� ȸ���� ã��, ������ �����ϱ� ���� �Ű������� ����
              string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void Withdraw::withdrawMember(MemberCollection& memberCollection, string& loginId, int& memberType) {
    const char* id = loginId.c_str();       // const char*�� type ��ȯ

    memberCollection.removeMember(id);      // �ش� id ����

    loginId = "";           // ȸ�� Ż�� �� �α׾ƿ� ���·� �ǵ�����
    memberType = 0;         // ȸ�� Ż�� �� ȸ�� ȸ���� �Ϲ� ȸ���� �ƴϹǷ� memberType = 0
}
