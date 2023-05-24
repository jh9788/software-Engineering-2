#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"
using namespace std;

class RegisterUI;

// ȸ������ Control
class Register 
{
private:
	RegisterUI* boundary;
	MemberCollection* memberCollection;

public:
	Register(MemberCollection* inputMemberCollection);
	RegisterUI* getRegisterUI();

	// ȸ�� ȸ�� ����
	void registerCompanyMember(string name, string num, string id, string pwd, int memberType);
	// �Ϲ� ȸ�� ����
	void registerGeneralMember(string name, string num, string id, string pwd, int memberType);
};