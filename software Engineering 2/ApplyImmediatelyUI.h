#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class ApplyImmediately;

/*
Ŭ���� �̸� : ApplyImmediatelyUI
��� : ä�� ���� Boundary
*/
class ApplyImmediatelyUI
{
private:
	ApplyImmediately* control;
	ofstream* fout;
public:
	ApplyImmediatelyUI(ApplyImmediately* inputControl); // ������
	void init(ofstream* inputFout); // ���� ������� ���� �Լ�

	void startInterface(); // �������̽� ����
	void showApplyImmediately(string inputEvent, string currentLoginId); // ä�� ������ �Ϸ��ϴ� �Լ�
};
