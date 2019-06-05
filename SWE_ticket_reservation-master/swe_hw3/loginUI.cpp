#include "stdafx.h"
#include "loginUI.h"

//Function: LoginUI()
//Description: LoginUI class�� �⺻ ������. Login ��ü�� �����Ѵ�.
//Parameters: None
//Return Value: None
//Created: 2019/06/02
LoginUI::LoginUI() {
	logins = new Login();
}

//Function: LoginUI(MemberManagement*mm)
//Description: LoginUI class�� ������, Login�� memberManagement�� �Ѱ��־� ���ο� ��ü�� �����.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
LoginUI::LoginUI(MemberManagement *mm) {
	logins = new Login(mm);
}

//Function: bool login(string id, string password)
//Description: logins ��� ��ü ������ login�Լ��� �θ���.
//Parameters: string id, string password
//Return Value: bool
//Created: 2019/06/02
bool LoginUI::login(string id, string password) {

	return logins->login(id, password);
}