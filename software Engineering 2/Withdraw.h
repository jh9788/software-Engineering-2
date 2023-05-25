#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"

using namespace std;

class WithdrawUI;


/*
Ŭ���� �̸� : Withdraw
��� : ȸ��Ż�� Control
*/
class Withdraw 
{
private:
	WithdrawUI* boundary;
	MemberCollection* memberCollection;
	ApplicationInfoCollection* applicationInfoCollection;
	RecruitInfoCollection* recruitInfoCollection;

public:
	Withdraw(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection,
			 ApplicationInfoCollection* inputApplicationInfoCollection);	// ������
	WithdrawUI* getWithdrawUI();	// �ٿ���� ȣ��
	void withdrawMember(string& loginId, int& memberType);// ȸ�� ����
};