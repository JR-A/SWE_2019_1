#include "stdafx.h"
#include "signUp.h"

//Function: SignUp()
//Description: SignUp class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
SignUp::SignUp() {}

//Function: SignUp(MemberManagement *mm)
//Description: SignUp class�� ������. ���ο� memberManagement ��ü�� �Ҵ��Ѵ�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
SignUp::SignUp(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: void createAccount(string id, string password, string name, string identificationNumber, string type)
//Description: ��� �׷쿡 ����� �߰��ϴ� �Լ��̴�. memberManagement Ŭ������ createAccount �Լ��� �θ���.
//Parameters: string id, string password, string name, string identificationNumber, string type
//Return Value: void
//Created: 2019/06/02
void SignUp::createAccount(string id, string password, string name, string identificationNumber, string type) {
	memberManagement->createAccount(type, id, password, name, identificationNumber);
}