#include "stdafx.h"
#include "login.h"

//Function: Login()
//Description: Login class�� �⺻ ������. MemberManagement ��ü�� �����Ѵ�.
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Login::Login() {
	memberManagement = new MemberManagement();

}

//Function: Login(MemberManagement*mm)
//Description: Login class�� ������, ���ο� memberManagement ��ü�� �Ҵ��Ѵ�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
Login::Login(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: bool login(string id, string password)
//Description: memberManagement ��� ��ü ������ login�Լ��� �θ���.
//Parameters: string id, string password
//Return Value: bool
//Created: 2019/06/02
bool Login::login(string id, string password) {
	return memberManagement->login(id, password);
}