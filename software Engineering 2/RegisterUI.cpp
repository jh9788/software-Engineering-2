/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void RegisterUI::startInterface() {
    fout << "1.1. ȸ������" << endl;  // ������ �Է��� ���� ȭ�鿡 ����. �̿� ���� ������ boundary���� ����
}

/*
    �Լ� �̸� : selectMemberType
    ���: ������ �� ���� �а�, ȸ���� Type�� �°� ���� ��ȯ
    �Ű�����: string inputEvent -> ���Ͽ��� ��� �о���� �� ���� ����
    ��ȯ��: ȸ�� ȸ���̸� 1, �Ϲ� ȸ���̸� 2�� ��ȯ
*/
int RegisterUI::selectMemberType(string inputEvent) {
    int thirdEvent = inputEvent[4] - '0';

    if (thirdEvent == 1)
        return 1;
    else if (thirdEvent == 2)
        return 2;
}

/*
    �Լ� �̸� : requestRegister
    ���: ȸ������ Boundary�� �Լ��ν�, ȸ�� ���� Control���� ȸ�� ������ ��û�ϴ� ����
    �Ű�����: MemberCollection& memberCollection -> ȸ�� ���� �Ϸ� ��, memberCollection�� ����
              string inputEvent -> ���Ͽ��� ��� �о���� �� ���� ����
              int memberType -> 1: ȸ�� ȸ��, 2: �Ϲ� ȸ��
    ��ȯ��: X
*/
void RegisterUI::requestRegister(MemberCollection& memberCollection, string inputEvent, int memberType) {
    // ������ ���� �Լ��� �Ű������� char* type�� �ֱ� ���� string �ڸ���
    stringstream input(inputEvent);     // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, num3, name, num, id, pwd;    // ������ �������� �߶��� �ֵ��� ���� string ���� ����

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // ������ �������� �� ������ string�� �־���

    const char* cname = name.c_str();   // string type�� const char* type���� ��ȯ
    const char* cnum = num.c_str();
    const char* cid = id.c_str();
    const char* cpwd = pwd.c_str();

    Register regist;            // Control class���� regist ��ü ���� (register�� ������̹Ƿ� regist��� ���� ������ ��ü)

    // 1.1.1���� 1.1.2������ �� switch case������ ����
    switch (memberType) {
    case 1:             // ȸ�� ȸ���� ���
        regist.registerCompanyMember(memberCollection, cname, cnum, cid, cpwd, 1);     // Control�� �Լ��� registerCompanyMember ȣ��
        break;
    case 2:             // �Ϲ� ȸ���� ���
        regist.registerGeneralMember(memberCollection, cname, cnum, cid, cpwd, 2);     // Control�� �Լ��� registerGeneralMember ȣ��
        break;
    }
}

/*
    �Լ� �̸� : showRegisterSuccessInterface
    ���: ȸ�� ���� �Ϸ� �� ���Ͽ� ���� ���� ����
    �Ű�����: string inputEvent -> ���Ͽ� ������ name, num, id, pwd�� �Ľ��ϱ� ���� �Ű�����
              memberType -> ȸ�� ȸ��, �Ϲ� ȸ���� �´� ��ȣ�� ���Ͽ� �����ϱ� ���� �Ű�����
    ��ȯ��: X
*/
void RegisterUI::showRegisterSuccessInterface(string inputEvent, int memberType) {
    // ���Ͽ� ������ �����ϱ� ���� string �ڸ���
    stringstream input(inputEvent);     // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, num3, name, num, id, pwd;    // ������ �������� �߶��� �ֵ��� ���� string ���� ����

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // ������ �������� �� ������ string�� �־���

    fout << "> " << memberType << " " << name << " " << num << " " << id << " " << pwd << endl << endl;    // ���Ͽ� ȸ�� ���� ���� ����
}
