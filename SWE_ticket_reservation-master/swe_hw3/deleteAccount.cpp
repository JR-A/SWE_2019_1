#include "stdafx.h"
#include "deleteAccount.h"
#include "memberManagement.h"

//Function: DeleteAccount()
//Description: DeleteAccount class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
DeleteAccount::DeleteAccount() {}

//Function: DeleteAccount((MemberManagement *mm)
//Description: Delete class�� ������.���ο� memberManagement ��ü�� �Ҵ��Ѵ�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
DeleteAccount::DeleteAccount(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: bool deleteAccount(string id)
//Description: memberManagement�� deleteAccount �Լ��� �θ���.
//Parameters: string id
//Return Value: bool
//Created: 2019/06/02
bool DeleteAccount::deleteAccount(string id) {
	return memberManagement->deleteAccount(id);
}