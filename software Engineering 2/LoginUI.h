#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h" // �ʿ�����
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Login;

// �α��� UI
class LoginUI 
{
private:
	Login* control;
	ofstream* fout;
public:
	LoginUI(Login* inputControl);
	void init(ofstream* inputFout);

	void startInterface();		// �������̽� ����
	bool isLoginValid(string inputEvent, string& currentLoginId, int& currentMemberType);	// �α��� ��û, ID�� PW�� ��ġ�Ѵٸ� true ��ȯ
	void showLoginSuccessInterface(string inputEvent);		// �α��� ���� ȭ�� ���Ͽ� ����
	void showLoginFailInterface();		// �α��� ���� ȭ�� ���Ͽ� ����
};