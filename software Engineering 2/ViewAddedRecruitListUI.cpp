
/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void ViewAddedRecruitListUI::startInterface() {
    fout << "3.2. 등록된 채용 정보 조회" << endl;     // 유저가 입력한 내용 화면에 띄우기
}

void ViewAddedRecruitListUI::showRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string nowLogin) {
    const char* cnowlogin = nowLogin.c_str();

    ViewAddedRecruitList viewAddedRecruitList = ViewAddedRecruitList();


    // 컨트롤로 보내고, 컨트롤이 대답할 객체를 생성해야 할텐데..
    for (int i = 0; i < recruitInfoCollection.getRecruitInfoCollectionSize(); i++) {
        if (recruitInfoCollection.isMemberInRecruitInfoCollection(cnowlogin)) {
            fout << "> " << recruitInfoCollection.getRecruitAllInfo(i);
        }
    }
}

