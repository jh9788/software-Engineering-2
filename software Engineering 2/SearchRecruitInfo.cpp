#include "SearchRecruitInfoUI.h"
#include "SearchRecruitInfo.h"


/*
    �Լ� �̸� : SearchRecruitInfo
    ���: ������
    �Ű�����: RecruitInfoCollection* inputRecruitInfoCollection, MemberCollection* inputMemberCollection
    ��ȯ��: X
*/
SearchRecruitInfo::SearchRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection) 
{
    recruitInfoCollection = inputRecruitInfoCollection;
    memberCollection = inputMemberCollection;

    SearchRecruitInfoUI* boundary = new SearchRecruitInfoUI(this);
    this->boundary = boundary;
}

/*
    �Լ� �̸� : getSearchRecruitInfoUI
    ���: Boundary�� ȣ���ϱ� ���� �Լ�
    �Ű�����: X
    ��ȯ��: SearchRecruitInfoUI* Ÿ���� �ٿ����
*/
SearchRecruitInfoUI* SearchRecruitInfo:: getSearchRecruitInfoUI() 
{
    return boundary;
}



/*
    �Լ� �̸� : searchRecruitInfo
    ���: ä�� ���� �˻��� ���� �Լ�, �� ���α׷� ���� ��¥ �������� �������� ������ ���� ä�� ������ ȣ���Ѵ�.
    �Ű�����: string name -> ȸ���̸��� �Ű������� ����
    ��ȯ��: ȸ�� �̸��� �������� �������� ������ ���� ä�� ������ str�� ����
*/
string SearchRecruitInfo::searchRecruitInfo(string name) 
{
    string targetId = memberCollection->findIdByName(name); // ȸ�� ID
    string businessNum = memberCollection->findBusinessNumByName(name); // ȸ�� ����ڹ�ȣ
    string returnString = recruitInfoCollection->getRecruitInfoWithoutSign(targetId);  // ȸ�� ID�� �̿��Ͽ� returnString�� ä�� ������ ���� 
    
    int lineNum = count(returnString.begin(), returnString.end(), '\n');
    
    string newString = "> " + name + " " + businessNum + " ";
    stringstream temp(returnString);
    string line;

    vector<string> lines;
    // ȸ�� ID �������� ����� ä�� ���� �� �������� ������ ���� ä�� ������ str�� ����
    while (getline(temp, line)) 
    {
        lines.push_back(newString + line);
    }
    stringstream result;
    for (size_t i = 0; i < lines.size(); ++i)
    {
        result << lines[i];
        if (i < lines.size())
        {
            result << "\n";
        }
    }
    return result.str();
}