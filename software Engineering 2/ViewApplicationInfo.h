#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class ViewApplicationInfoUI;

// ����� ä�� ���� ��ȸ Control
class ViewApplicationInfo {
private:
	ViewApplicationInfoUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
public:
	ViewApplicationInfo(ApplicationInfoCollection* inputApplicationInfoCollection);	// ������
	ViewApplicationInfoUI* getViewApplicationInfoUI();	// Boundary�� ȣ���ϱ� ���� �Լ�

	string viewApplicationList(string currentLoginId);		// ��ϵ� ä�� ������ ��� Ȯ���ϴ� �Լ�
};