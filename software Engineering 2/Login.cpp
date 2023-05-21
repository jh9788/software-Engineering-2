

/*
    �Լ� �̸� : verifyLogin
    ���: �α��� �� �� �ִ� �ڰ��� ���߾����� Ȯ���ϴ� �Լ�
    �Ű�����: MemberCollection& memberCollection -> memberCollection�� ����Ǿ��ִ� ������ Ȯ���ϱ� ���� ������ argument
              const char* name -> �̸�
              const char* num -> �ֹε�Ϲ�ȣ
              const char* id -> ID
              const char* pwd -> Password
              string& loginId -> ���� login�� ID�� ������ ���� ���� ����
              int memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� ���� memberType���� ������ ���� ���� ����
    ��ȯ��: bool
*/
bool Login::verifyLogin(MemberCollection& memberCollection, const char* id, const char* pwd, string& loginId, int& memberType) {
    // ȸ���� �´� ���
    if (memberCollection.isMember(id, pwd)) {
        loginId = id;           // loginId�� ��� �α����� �õ��ߴ� id�� ����
        memberType = memberCollection.getMemberType(id, pwd);       // memberType�� ���� �α��� �� member�� type�� ����
        return true;
    }
    // ȸ���� �ƴ� ���
    else
        return false;
}