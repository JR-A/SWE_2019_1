#include "stdafx.h"
#include "Member.h"
#include "memberManagement.h"

//Function: Member()
//Description: Member class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Member::Member()
{
}

//Function: ~Member()
//Description: Member class�� �Ҹ���
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Member::~Member()
{
}

//Function: string getID()
//Description: id ���� �����Ѵ�.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Member::getID() {
	return id;
}

//Function: string getPassword()
//Description: password ���� �����Ѵ�.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Member::getPassword() {
	return password;
}