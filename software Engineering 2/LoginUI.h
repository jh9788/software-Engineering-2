#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h" // �ʿ�����
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Login;

/*
Ŭ���� �̸� : LoginUI
��� : �α��� Boundary
*/
class LoginUI 
{
private:
	Login* control;
	ofstream* fout;

	void _showLoginSuccessInterface(string inputEvent);	// �α��� ���� ȭ�� ���Ͽ� ����
	void _showLoginFailInterface();		// �α��� ���� ȭ�� ���Ͽ� ����
public:
	LoginUI(Login* inputControl);	// ������
	void init(ofstream* inputFout);	// ���� ������� ���� �Լ�

	void startInterface();		// �������̽� ����
	void verifyLogin(string inputEvent, string& currentLoginId, int& currentMemberType);	// �α��� ��û
	
};