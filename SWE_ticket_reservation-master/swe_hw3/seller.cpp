#include "stdafx.h"
#include "seller.h"

//Function: Seller()
//Description: Seller class�� �⺻ ������
//Parameters: None
//Return Value: None
//Created: 2019/06/02
Seller::Seller() {

}

//Function: Seller(string id, string password, string name, string identificationNumber)
//Description: Seller class�� ������. ��� ������ �ʱ�ȭ�Ѵ�.
//Parameters: string id, string password, string name, string identificationNumber
//Return Value: None
//Created: 2019/06/02
Seller::Seller(string id, string password, string name, string identificationNumber) {
	this->id = id;
	this->password = password;
	this->name = name;
	this->identificationNumber = identificationNumber;
	registeredTickets = new TicketCollection();
}

//Function: bool existTicket()
//Description: registeredTickets�� existTicket �Լ��� �θ���.
//Parameters: None
//Return Value: bool
//Created: 2019/06/02
bool Seller::existTicket() {
	return registeredTickets->existTicket();
}

//Function: string getType()
//Description: "seller" ���ڿ��� ��ȯ�Ѵ�.
//Parameters: None
//Return Value: string
//Created: 2019/06/02
string Seller::getType() {
	return "seller";
}

//Function: TicketCollection * getRegisteredTickets()
//Description: registeredTickets ��ü�� ��ȯ�Ѵ�.
//Parameters: None
//Return Value: TicketCollection*
//Created: 2019/06/02
TicketCollection* Seller::getRegisteredTickets()
{
	return registeredTickets;
}