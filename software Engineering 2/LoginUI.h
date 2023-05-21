#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



class Login;

// �α��� UI
class LoginUI {
private:
	Login* control;
	ofstream* fout;
public:
	LoginUI(Login* inputControl);
	void init(ofstream* inputFout);

	void startInterface();		// �������̽� ����
	bool requestLogin(MemberCollection& memberCollection, string inputEvent, string& loginId, int& memberType);	// �α��� ��û, ID�� PW�� ��ġ�Ѵٸ� true ��ȯ
	void showLoginSuccessInterface(string inputEvent);		// �α��� ���� ȭ�� ���Ͽ� ����
	void showLoginFailInterface();		// �α��� ���� ȭ�� ���Ͽ� ����
};