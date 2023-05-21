

void AddRecruitInfo::addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
    const char* work, const char* targetNum, const char* deadline, const char* nowLogin) {
    RecruitInfo* newRecruitInfo = NULL;       // RecruitInfo Type�� ���ο� ��ü ����
    newRecruitInfo = new RecruitInfo(work, targetNum, deadline, nowLogin);  // �� ��ü�� RecruitInfo ������ ����� �ֱ�
    recruitInfoCollection.addRecruitInfo(newRecruitInfo);  // recruitInfoCollection class�� ���� �ִ� addRecruitInfo�Լ� ȣ���Ͽ� RecruitInfo �߰�
}