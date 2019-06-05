#include "stdafx.h"
#include "signUpUI.h"

//Function: SignUpUI()
//Description: SignUpUI class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
SignUpUI::SignUpUI() {}

//Function: SignUpUI(MemberManagement *mm)
//Description: SignUpUI class�� ������. ���ο� memberManagement ��ü�� �Ҵ��Ѵ�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
SignUpUI::SignUpUI(MemberManagement *mm) {
	signUp = new SignUp(mm);
}

//Function: void createAccount(string id, string password, string name, string identificationNumber, string type)
//Description: ��� �׷쿡 ����� �߰��ϴ� �Լ��̴�. SignUp Ŭ������ createAccount �Լ��� �θ���.
//Parameters: string id, string password, string name, string identificationNumber, string type
//Return Value: void
//Created: 2019/06/02
void SignUpUI::createAccount(string id, string password, string name, string identificationNumber, string type) {
	signUp->createAccount(id, password, name, identificationNumber, type);
}