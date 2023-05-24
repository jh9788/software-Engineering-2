#include "CancelApplication.h"
#include "CancelApplicationUI.h"

/*
	�Լ� �̸� : CancelApplication
	���: ������
	�Ű�����: ApplicationInfoCollection* inputApplicationInfoCollection
	��ȯ��: X
*/
CancelApplication::CancelApplication(ApplicationInfoCollection* inputApplicationInfoCollection) 
{

	applicationInfoCollection = inputApplicationInfoCollection;

	CancelApplicationUI* boundary = new CancelApplicationUI(this);
	this->boundary = boundary;

}
/*
	�Լ� �̸� : getCancelApplicationUI
	���: Boundary�� ȣ���ϱ� ���� �Լ�
	�Ű�����: X
	��ȯ��: CancelApplication* Ÿ���� Boundary
*/
CancelApplicationUI* CancelApplication::getCancelApplicationUI() 
{
	return boundary;
}

/*
	�Լ� �̸� : viewCancelApplication
	���: currentLoginId�� inputBusinessNum�� ������ ����ϰ� ��������� ��ȯ�ϱ� ���� �Լ�
	�Ű�����: string currentLoginId, string inputBusinessNum
	��ȯ��: ���� ��Ҹ� �Ϸ��� ���� ������ returnString�� ����
*/
string CancelApplication::viewCancelApplication(string currentLoginId, string inputBusinessNum) 
{
	string returnString;

	returnString = applicationInfoCollection->removeApplicationInfo(currentLoginId, inputBusinessNum);

	return returnString;
}