#pragma once
#include <string>
using namespace std;

class Withdraw;
// 회원탈퇴 UI
class WithdrawUI {
private:
	Withdraw* control;
public:
	void startInterface();// 인터페이스 시작
	void requestWithdraw(string& loginId, int& memberType);// 회원 삭제 요청
	void showWithdrawId(string withdrawId);// 회원 탈퇴한 ID 기록
};