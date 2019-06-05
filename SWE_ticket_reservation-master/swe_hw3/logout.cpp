#include "stdafx.h"
#include "logout.h"

//Function: Logout()
//Description: Logout class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Logout::Logout() {
	memberManagement = new MemberManagement();
}

//Function: Logout(MemberManagement*mm)
//Description: Logout class�� ������, ���ο� memberManagement ��ü�� �Ҵ��Ѵ�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
Logout::Logout(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: void logout(string id)
//Description: memberManagement �ɹ� ��ü ������ logout �Լ��� �θ���.
//Parameters: string id
//Return Value: void
//Created: 2019/06/02
void Logout::logout(string id) {
	memberManagement->logout(id);
}