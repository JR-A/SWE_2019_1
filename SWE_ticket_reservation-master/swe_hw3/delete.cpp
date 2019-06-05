#include "stdafx.h"
#include "delete.h"
#include "memberManagement.h"

//Function: Delete()
//Description: Delete class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Delete::Delete() {}

//Function: Delete((MemberManagement *mm)
//Description: Delete class�� ������.���ο� memberManagement ��ü�� �Ҵ��Ѵ�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
Delete::Delete(MemberManagement *mm) {
	memberManagement = new MemberManagement();
	memberManagement = mm;
}

//Function: bool deleteAccount(string id)
//Description: memberManagement�� deleteAccount �Լ��� �θ���.
//Parameters: string id
//Return Value: bool
//Created: 2019/06/02
bool Delete::deleteAccount(string id) {
	return memberManagement->deleteAccount(id);
}