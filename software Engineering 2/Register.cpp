
/*
    �Լ� �̸� : registerCompanyMember
    ���: ȸ�� ȸ���� ���� �����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� ���� �Ϸ� ��, memberCollection�� ����
              const char* name -> �̸�
              const char* num -> ����� ��ȣ
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 1 (ȸ�� ȸ��)
    ��ȯ��: X
*/
void Register::registerCompanyMember(MemberCollection& memberCollection,
    const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type�� ���ο� ��ü ����
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // �� ��ü�� CompanyMember ������ ����� �ֱ�
    memberCollection.addMember(newMember);  // memberCollection class�� ���� �ִ� addMember�Լ� ȣ���Ͽ� Member �߰�
}

/*
    �Լ� �̸� : registerGeneralMember
    ���: �Ϲ� ȸ���� ���� �����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� ���� �Ϸ� ��, memberCollection�� ����
              const char* name -> �̸�
              const char* num -> �ֹε�Ϲ�ȣ
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 2 (�Ϲ� ȸ��)
    ��ȯ��: X
*/
void Register::registerGeneralMember(MemberCollection& memberCollection,
    const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type�� ���ο� ��ü ����
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // �� ��ü�� GeneralMember ������ ����� �ֱ�
    memberCollection.addMember(newMember);  // memberCollection class�� ���� �ִ� addMember�Լ� ȣ���Ͽ� Member �߰�
}