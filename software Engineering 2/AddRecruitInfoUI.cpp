

/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void AddRecruitInfoUI::startInterface() {
    fout << "3.1. 채용 정보 등록" << endl;     // 유저가 입력한 내용 화면에 띄우기
}

void AddRecruitInfoUI::requestRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string inputEvent, string nowLogin) {
    // 다음에 사용될 함수의 매개변수에 char* type을 넣기 위해 string 자르기
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, work, targetNum, deadline;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // 공백을 기준으로 각각의 string을 변수에 담기

    const char* cwork = work.c_str();   // string type을 const char* type으로 변환
    const char* ctargetnum = targetNum.c_str();
    const char* cdeadline = deadline.c_str();
    const char* cnowlogin = nowLogin.c_str();

    AddRecruitInfo addRecruitInfor;            // Control class에서 addRecruitInfo 객체 생성
    addRecruitInfor.addRecruitInfo(recruitInfoCollection, cwork, ctargetnum, cdeadline, cnowlogin);
}

void AddRecruitInfoUI::showAddedRecruitInfo(string inputEvent) {
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, work, targetNum, deadline;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // 공백을 기준으로 각각의 string을 변수에 담기

    cout << "work : " << work << endl;
    cout << "targetNum : " << targetNum << endl;
    cout << "deadline : " << deadline << endl;

    fout << "> " << work << " " << targetNum << " " << deadline << endl << endl;       // 채용 정보 등록 성공 시, 파일에 저장
}
