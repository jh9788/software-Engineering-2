#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;

void run();
void program_exit();

// ��ü�� ���� �ּ� ����� �߰��ؾ���!!
// ȸ������ UI
class RegisterUI {
private:
public:
	void startInterface();		// �������̽� ����
	int selectMemberType(string inputEvent);		// ȸ�� ȸ������, �Ϲ� ȸ������ member type ����
	void requestRegister(MemberCollection& memberCollection, string inputEvent, int memberType);		// ȸ�� ���� ��û
	void showRegisterSuccessInterface(string inputEvent, int memberType);		// ȸ�� ���� ���� ȭ�� ���Ͽ� ����
};

// ȸ������ Control
class Register {
private:
public:
	// ȸ�� ȸ�� ����
	void registerCompanyMember(MemberCollection& memberCollection,
							   const char* name, const char* num, const char* id, const char* pwd, int memberType);
	// �Ϲ� ȸ�� ����
	void registerGeneralMember(MemberCollection& memberCollection,
							   const char* name, const char* num, const char* id, const char* pwd, int memberType);
};

// �α��� UI
class LoginUI {
private:
public:
	void startInterface();		// �������̽� ����
	bool requestLogin(MemberCollection& memberCollection, string inputEvent, string& loginId, int& memberType);	// �α��� ��û, ID�� PW�� ��ġ�Ѵٸ� true ��ȯ
	void showLoginSuccessInterface(string inputEvent);		// �α��� ���� ȭ�� ���Ͽ� ����
	void showLoginFailInterface();		// �α��� ���� ȭ�� ���Ͽ� ����
};

// �α��� Control
class Login {
private:
public:
	bool verifyLogin(MemberCollection& memberCollection, const char* id, const char* pwd, string& loginId, int& memberType);
};

// �α׾ƿ� UI
class LogoutUI {
private:
public:
	void startInterface();		// �������̽� ����
	void requestLogout(string& loginId, int& memberType);	// �α׾ƿ� ��û
	void showLogoutId(string logoutId);		// �α׾ƿ� ���� ȭ�� ���Ͽ� ����
};

// �α׾ƿ� Control
class Logout {
private:
public:
	void logoutMember(string& loginId, int& memberType);  	// �α׾ƿ� ����, loginId�� ""�� �������, memberType�� 0���� ��������
};

// ȸ��Ż�� UI
class WithdrawUI {
private:
public:
	void startInterface();		// �������̽� ����
	void requestWithdraw(MemberCollection& memberCollection, string& loginId, int& memberType);		// ȸ�� ���� ��û
	void showWithdrawId(string withdrawId);		// ȸ�� Ż���� ID ���
};

// ȸ��Ż�� Control
class Withdraw {
private:
public:
	void withdrawMember(MemberCollection& memberCollection, string& loginId, int& memberType);			// ȸ�� ����
};

// ä�� ���� �߰� UI
class AddRecruitInfoUI {
private:
public:
	void startInterface();		// �������̽� ����
	void requestRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string inputEvent, string nowLogin);		// recruitInfoCollection�� recruitInfo�� �߰��ϴ� �Լ� ȣ��
	void showAddedRecruitInfo(string inputEvent);		// �߰��� �Ϸ�Ǹ� ���Ͽ� ���
};

// ä�� ���� �߰� Control
class AddRecruitInfo {
private:
public:
	void addRecruitInfo(RecruitInfoCollection& recruitInfoCollection,
						const char* work, const char* targetNum, const char* deadline, const char* nowLogin);
};

// ä�� ���� �߰� UI
class ViewAddedRecruitListUI {
private:
public:
	void startInterface();		// �������̽� ����
	void showRecruitInfo(RecruitInfoCollection& recruitInfoCollection, string nowLogin);		// �߰��� �Ϸ�Ǹ� ���Ͽ� ���
};

// ä�� ���� �߰� Control
class ViewAddedRecruitList {
private:
public:
};