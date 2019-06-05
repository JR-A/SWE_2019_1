#include "stdafx.h"
#include "TicketCollection.h"
#include "Ticket.h"

TicketCollection::TicketCollection() {
	// TODO Auto-generated constructor stub

}

TicketCollection::~TicketCollection() {
	// TODO Auto-generated destructor stub
}

// Function : vector<Ticket *> TicketCollection::getTickets()
// Description:
// ���� �ݷ����� ��� Ƽ�� ������ ���͸� ��ȯ�մϴ�
// Return Value : Ƽ���� �����Ͱ� ��� ����
//
// Created: 2019/05/28 21:10 pm
// Author: �赵��
vector<Ticket *> TicketCollection::getTickets() {
	return tickets;
}

// Function : void TicketCollection::add(Ticket * ticket)
// Description:
// Ƽ���ݷ��� �ν��Ͻ��� Ƽ���� �߰��մϴ�.
// Parameter : Ticket * ticket - �߰��� Ƽ�� ������
// Return Value : Ȩ���� �����Ͱ� ��� ����
//
// Created: 2019/05/28 21:13 pm
// Author: �赵��
void TicketCollection::add(Ticket * ticket) {
	tickets.push_back(ticket);
}

// Function : void TicketCollection::deleteTicket(Ticket* ticket)
// Description : Ƽ�� �����Ͱ� ����� ���� �߿�, �Ű������� ���� ticket�� ���� ���Ҹ� ����
// Parameters : Ticket * ticket - ������ Ƽ�� ������
// Return Value : None
// Created: 2019/06/2 21:00 pm
// Author: ���μ�
void TicketCollection::deleteTicket(Ticket* ticket) {
	// TicketCollection�� ����Ǿ� �ִ� tickets vector�� iterator�� �ݺ�
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		// vector ���� �Ű������� ���� ticket�� ���� ���Ұ� �ִ� ��츦 üũ
		if ((*it) == ticket) {
			// �ش� vector���Ҹ� vector.erase()�� ����
			//cout << (*it)->getMatchDate() << endl;
			tickets.erase(it);
			break;
		}
	}
}

void TicketCollection::setAvailability(Ticket* ticket, bool availability) {
	for (vector<Ticket*>::iterator it = tickets.begin(); it != tickets.end();it++) {
		if ((*it) == ticket) {
			(*it)->setAvailability(availability);
		}
	}
}

bool TicketCollection::existTicket() {
	if (tickets.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

