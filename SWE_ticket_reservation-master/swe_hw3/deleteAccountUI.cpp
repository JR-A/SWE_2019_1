#include "stdafx.h"
#include "deleteAccountUI.h"

//Function: DeleteAccountUI()
//Description: DeleteAccountUI class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
DeleteAccountUI::DeleteAccountUI() {
	deletes = new DeleteAccount();
}

//Function: DeleteAccountUI(MemberManagement *mm)
//Description: DeleteAccountUI class�� ������. deletes ��� ��ü ������ ���ο� ������ �Ҵ����ش�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
DeleteAccountUI::DeleteAccountUI(MemberManagement *mm) {
	deletes = new DeleteAccount(mm);
}

//Function: bool deleteAccount(string line)
//Description: deletes�� deleteAccount �Լ��� �θ���.
//Parameters: string line
//Return Value: bool
//Created: 2019/06/02
bool DeleteAccountUI::deleteAccount(string line) {
	return deletes->deleteAccount(line);

}