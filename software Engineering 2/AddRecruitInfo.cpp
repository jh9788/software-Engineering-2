

void AddRecruitInfo::addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
    const char* work, const char* targetNum, const char* deadline, const char* nowLogin) {
    RecruitInfo* newRecruitInfo = NULL;       // RecruitInfo Type의 새로운 객체 생성
    newRecruitInfo = new RecruitInfo(work, targetNum, deadline, nowLogin);  // 그 객체에 RecruitInfo 생성자 만들어 넣기
    recruitInfoCollection.addRecruitInfo(newRecruitInfo);  // recruitInfoCollection class가 갖고 있는 addRecruitInfo함수 호출하여 RecruitInfo 추가
}