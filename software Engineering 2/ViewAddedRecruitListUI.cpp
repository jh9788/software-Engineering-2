
/*
    �Լ� �̸� : startInterface
    ���: ������ �Է��� ���� ȭ�鿡 ����
    �Ű�����: X
    ��ȯ��: X
*/
void ViewAddedRecruitListUI::startInterface() {
    fout << "3.2. ��ϵ� ä�� ���� ��ȸ" << endl;     // ������ �Է��� ���� ȭ�鿡 ����
}

void ViewAddedRecruitListUI::showRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string nowLogin) {
    const char* cnowlogin = nowLogin.c_str();

    ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList();


    // ��Ʈ�ѷ� ������, ��Ʈ���� ����� ��ü�� �����ؾ� ���ٵ�..
    for (int i = 0; i < recruitInfoCollection.getRecruitInfoCollectionSize(); i++) {
        if (recruitInfoCollection.isMemberInRecruitInfoCollection(cnowlogin)) {
            fout << "> " << recruitInfoCollection.getRecruitAllInfo(i);
        }
    }
}

