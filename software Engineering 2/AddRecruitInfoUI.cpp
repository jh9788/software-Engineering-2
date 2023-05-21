

/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void AddRecruitInfoUI::startInterface() {
    fout << "3.1. ä�� ���� ���" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

void AddRecruitInfoUI::requestRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string inputEvent, string nowLogin) {
    // ������ ���� �Լ��� �Ű������� char* type�� �ֱ� ���� string �ڸ���
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, work, targetNum, deadline;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // ������ �������� ������ string�� ������ ���

    const char* cwork = work.c_str();   // string type�� const char* type���� ��ȯ
    const char* ctargetnum = targetNum.c_str();
    const char* cdeadline = deadline.c_str();
    const char* cnowlogin = nowLogin.c_str();

    AddRecruitInfo addRecruitInfor;            // Control class���� addRecruitInfo ��ü ����
    addRecruitInfor.addRecruitInfo(recruitInfoCollection, cwork, ctargetnum, cdeadline, cnowlogin);
}

void AddRecruitInfoUI::showAddedRecruitInfo(string inputEvent) {
    stringstream input(inputEvent);      // ���� (" ")�� ������ ���ڿ��� �� ���ڷ� �ڸ��� ���� stringstream ���
    string num1, num2, work, targetNum, deadline;     // ������ �������� ������ string�� ����� ������ ����

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // ������ �������� ������ string�� ������ ���

    cout << "work : " << work << endl;
    cout << "targetNum : " << targetNum << endl;
    cout << "deadline : " << deadline << endl;

    fout << "> " << work << " " << targetNum << " " << deadline << endl << endl;       // ä�� ���� ��� ���� ��, ���Ͽ� ����
}
