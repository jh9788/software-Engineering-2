
/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void LogoutUI::startInterface() {
    fout << "2.2. �α׾ƿ�" << endl;  // ������ �Է��� ���� ȭ�鿡 ����
}

/*
    �Լ� �̸� : requestLogout
    ���: �α׾ƿ� Boundary�� �Լ��ν�, �α׾ƿ��� Control�� �α׾ƿ��� ��û�ϴ� ����
    �Ű�����: string& loginId -> ���� login�� ID�� ""�� �������� ���� �Ű�����
              int memberType -> memberType�� 0���� �������� ���� �Ű�����
    ��ȯ��: X
*/
void LogoutUI::requestLogout(string& loginId, int& memberType) {
    Logout logout = Logout();   // logout ��ü ����

    logout.logoutMember(loginId, memberType);   // logoutMember �Լ� ȣ��
}

/*
    �Լ� �̸� : showLogoutId
    ���: �α׾ƿ� ���� �� ���Ͽ� ���� ���� ����
    �Ű�����: string logoutId -> ���Ͽ� ������ id�� ���� �Ű�����
    ��ȯ��: X
*/
void LogoutUI::showLogoutId(string logoutId) {
    fout << "> " << logoutId << endl << endl;    // ���Ͽ� ���� ����.
}
