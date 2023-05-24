#include "SearchRecruitInfoUI.h"
#include "SearchRecruitInfo.h"


/*
    함수 이름 : SearchRecruitInfo
    기능: 생성자
    매개변수: RecruitInfoCollection* inputRecruitInfoCollection, MemberCollection* inputMemberCollection
    반환값: X
*/
SearchRecruitInfo::SearchRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection) 
{
    recruitInfoCollection = inputRecruitInfoCollection;
    memberCollection = inputMemberCollection;

    SearchRecruitInfoUI* boundary = new SearchRecruitInfoUI(this);
    this->boundary = boundary;
}

/*
    함수 이름 : getSearchRecruitInfoUI
    기능: Boundary를 호출하기 위한 함수
    매개변수: X
    반환값: X
*/
SearchRecruitInfoUI* SearchRecruitInfo:: getSearchRecruitInfoUI() 
{
    return boundary;
}



/*
membercollection.cpp에서 회사이름, 사업자번호 나오게하는 함수를 만든다
recruitinfocollection.cpp에서 업무, 인원수, 마감일을 가져오는 함수를 만든다.
회사이름 + 사업자 번호 + 업무 + 인원수 + 마감일을 해서 for문을 하는 기능을수행한다.
recruitinfocollection에서 얻은 string의 개행의 수만큼 반복?
*/


string SearchRecruitInfo::searchRecruitInfo(string name) 
{
    string targetId = memberCollection->findIdByName(name);
    string businessNum = memberCollection->findBusinessNumByName(name);
    string returnString = recruitInfoCollection->getRecruitInfoWithoutSign(targetId);  // recruitInfoCollection class가 갖고 있는 addRecruitInfo함수 호출하여 RecruitInfo 추가
    
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