#include "stdafx.h"
#include "deleteUI.h"

//Function: DeleteUI()
//Description: DeleteUI class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
DeleteUI::DeleteUI() {
	deletes = new Delete();
}

//Function: DeleteUI(MemberManagement *mm)
//Description: DeleteUI class�� ������. deletes ��� ��ü ������ ���ο� ������ �Ҵ����ش�.
//Parameters: MemberManagement *mm
//Return Value: None
//Created: 2019/06/02
DeleteUI::DeleteUI(MemberManagement *mm) {
	deletes = new Delete(mm);
}

//Function: bool deleteAccount(string line)
//Description: deletes�� deleteAccount �Լ��� �θ���.
//Parameters: string line
//Return Value: bool
//Created: 2019/06/02
bool DeleteUI::deleteAccount(string line) {
	return deletes->deleteAccount(line);

}