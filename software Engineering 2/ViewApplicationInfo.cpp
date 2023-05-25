#include "ViewApplicationInfo.h"
#include "ViewApplicationInfoUI.h"


/*
	�Լ� �̸� : ViewApplicationInfo
	���: ������
	�Ű�����: ApplicationInfoCollection* inputApplicationInfoCollection
	��ȯ��: X
*/
ViewApplicationInfo::ViewApplicationInfo(ApplicationInfoCollection* inputApplicationInfoCollection) 
{

	applicationInfoCollection = inputApplicationInfoCollection;

	ViewApplicationInfoUI* boundary = new ViewApplicationInfoUI(this);
	this->boundary = boundary;
}

/*
	�Լ� �̸� : getViewApplicationInfoUI
	���: Boundary�� ȣ���ϱ� ���� �Լ�
	�Ű�����: X
	��ȯ��: ViewApplicationInfoUI* Ÿ���� �ٿ����
*/
ViewApplicationInfoUI* ViewApplicationInfo::getViewApplicationInfoUI() 
{
	return boundary;
}

/*
	�Լ� �̸� : viewApplicationList
	���: currentLoginId�� ���� ApplicationInfo�� ��ȯ�ϱ� ���� �Լ�
	�Ű�����: string currentLoginId
	��ȯ��: string Ÿ���� returnString
*/
string ViewApplicationInfo::viewApplicationList(string currentLoginId) 
{
	string retrunString = applicationInfoCollection->getApplicationInfo(currentLoginId);
	return retrunString;
}