#pragma once
#include <fstream>
#include<map>
#include <string>
using namespace std;

class ViewRecruitInfoStats;
class ViewRecruitInfoStatsUI
{
private:
	ViewRecruitInfoStats* control;
	ofstream* fout;

	void _showRecruitInfoStatsInterface(map<string, int> recruitInfoStats);

public:
	ViewRecruitInfoStatsUI(ViewRecruitInfoStats* inputControl);
	void init(ofstream* inputFout);

	//control -> 1 -> boundary
	void startInterface(); //�������̽� ����
	
	//actor -> 2 [currentMemberType == 1] -> boundary
	void requestAddedRecruitInfoStats(string currentLoginId); //ȸ��ȸ���� ����� ä�� ���� ��� ��û 
	//actor -> 3 [currentMemberType == 2] -> boundary
	void requestAppliedRecruitInfoStats(string currentLoginId); //�Ϲ�ȸ���� ������ ä�� ���� ��� ��û
};

