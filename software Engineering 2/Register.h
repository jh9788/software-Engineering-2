#pragma once
#include <iostream>
#include <string>

using namespace std;

class RegisterUI;

// ȸ������ Control
class Register {
private:
	RegisterUI* boundary;
public:
	// ȸ�� ȸ�� ����
	void registerCompanyMember(MemberCollection& memberCollection,
		const char* name, const char* num, const char* id, const char* pwd, int memberType);
	// �Ϲ� ȸ�� ����
	void registerGeneralMember(MemberCollection& memberCollection,
		const char* name, const char* num, const char* id, const char* pwd, int memberType);
};