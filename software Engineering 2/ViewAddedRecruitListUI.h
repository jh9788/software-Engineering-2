#pragma once

// 채용 정보 추가 UI
class ViewAddedRecruitListUI {
private:
public:
	void startInterface();		// 인터페이스 시작
	void showRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string nowLogin);		// 추가가 완료되면 파일에 기록
};