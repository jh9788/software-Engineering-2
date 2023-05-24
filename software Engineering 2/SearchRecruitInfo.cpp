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
    ��ȯ��: X
*/
SearchRecruitInfoUI* SearchRecruitInfo:: getSearchRecruitInfoUI() 
{
    return boundary;
}



/*
membercollection.cpp���� ȸ���̸�, ����ڹ�ȣ �������ϴ� �Լ��� �����
recruitinfocollection.cpp���� ����, �ο���, �������� �������� �Լ��� �����.
ȸ���̸� + ����� ��ȣ + ���� + �ο��� + �������� �ؼ� for���� �ϴ� ����������Ѵ�.
recruitinfocollection���� ���� string�� ������ ����ŭ �ݺ�?
*/


string SearchRecruitInfo::searchRecruitInfo(string name) 
{
    string targetId = memberCollection->findIdByName(name);
    string businessNum = memberCollection->findBusinessNumByName(name);
    string returnString = recruitInfoCollection->getRecruitInfoWithoutSign(targetId);  // recruitInfoCollection class�� ���� �ִ� addRecruitInfo�Լ� ȣ���Ͽ� RecruitInfo �߰�
    
    int lineNum = count(returnString.begin(), returnString.end(), '\n');
    
    string newString = "> " + name + " " + businessNum + " ";
    stringstream temp(returnString);
    string line;

    vector<string> lines;

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