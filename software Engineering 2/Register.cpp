
/*
    함수 이름 : registerCompanyMember
    기능: 회사 회원을 새로 등록함
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              const char* name -> 이름
              const char* num -> 사업자 번호
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 1 (회사 회원)
    반환값: X
*/
void Register::registerCompanyMember(MemberCollection& memberCollection,
    const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type의 새로운 객체 생성
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // 그 객체에 CompanyMember 생성자 만들어 넣기
    memberCollection.addMember(newMember);  // memberCollection class가 갖고 있는 addMember함수 호출하여 Member 추가
}

/*
    함수 이름 : registerGeneralMember
    기능: 일반 회원을 새로 등록함
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              const char* name -> 이름
              const char* num -> 주민등록번호
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 2 (일반 회원)
    반환값: X
*/
void Register::registerGeneralMember(MemberCollection& memberCollection,
    const char* name, const char* num, const char* id, const char* pwd, int memberType)
{
    Member* newMember = NULL;       // Member Type의 새로운 객체 생성
    newMember = new CompanyMember(name, num, id, pwd, memberType);  // 그 객체에 GeneralMember 생성자 만들어 넣기
    memberCollection.addMember(newMember);  // memberCollection class가 갖고 있는 addMember함수 호출하여 Member 추가
}