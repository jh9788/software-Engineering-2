#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class CancelApplicationUI;

/*
Ŭ���� �̸� : CancelApplication
��� : ���� ��� Control
*/
class CancelApplication {
private:
	CancelApplicationUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
public:
	CancelApplication(ApplicationInfoCollection* inputApplicationInfoCollection);	// ������
	CancelApplicationUI* getCancelApplicationUI();	// Boundary�� ȣ���ϱ� ���� �Լ�

	string viewCancelApplication(string currentLoginId, string inputBusinessNum);		
};