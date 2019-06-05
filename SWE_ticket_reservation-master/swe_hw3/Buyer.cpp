#include "stdafx.h"
#include "Buyer.h"
#include "memberManagement.h"

//Function: Buyer()
//Description : Buyer class�� �⺻ ������
//Parameters : None
//Return Value : None
//Created : 2019 / 06 / 02
Buyer::Buyer()
{
}

//Function: Buyer(string id, string password, string name, string identificationNumber)
//Description: Buyer class�� ������. ��� ������ �ʱ�ȭ�Ѵ�.
//Parameters: string id, string password, string name, string identificationNumber
//Return Value: None
//Created: 2019/06/02
Buyer::Buyer(string id, string password, string name, string identificationNumber)
{
	this->id = id;
	this->password = password;
	this->name = name;
	this->identificationNumber = identificationNumber;
	bookedTickets = new TicketCollection();
}

//Function: ~Buyer()
//Description: Buyer class�� �Ҹ���
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Buyer::~Buyer()
{
}

//Function: TicketCollection * getBookedTickets()
//Description: bookedTickets ��ü�� ��ȯ�Ѵ�.
//Parameters: None
//Return Value: TicketCollection*
//Created: 2019/06/02
TicketCollection* Buyer::getBookedTickets() {
	return bookedTickets;
}

//Function: string getType()
//Description: "buyer" ���ڿ��� ��ȯ�Ѵ�.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Buyer::getType() {
	return "buyer";
}

/* virtual existTicket() ���� �ʿ� */