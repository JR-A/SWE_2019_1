#include "stdafx.h"
#include "logoutUI.h"

//Function: LogoutUI()
//Description: LogoutUI class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
LogoutUI::LogoutUI() {
	logOut = new Logout();

}

//Function: LogoutUI(MemberManagement*mm)
//Description: LogoutUI class�� ������, Logout�� memberManagement�� �Ѱ��־� ���ο� ��ü�� �Ҵ��Ѵ�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
LogoutUI::LogoutUI(MemberManagement *mm) {
	logOut = new Logout(mm);
}

//Function: void logout(string id)
//Description: logOut �ɹ� ��ü ������ logout �Լ��� �θ���.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void LogoutUI::logout(string id) {
	logOut->logout(id);
}