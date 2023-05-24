#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;

class LoginUI;

/*
Ŭ���� �̸� : Login
��� : �α��� Control
*/
class Login 
{
private:
	LoginUI* boundary;
	MemberCollection* memberCollection;
public:
	Login(MemberCollection* memberCollection);	// ������
	LoginUI* getLoginUI();	// Boundary ȣ��
	bool isLoginVerified(string id, string pwd, string& loginId, int& memberType);	// �α��� �� �� �ִ� �ڰ��� ���߾����� Ȯ���ϴ� �Լ�
};
