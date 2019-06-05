#include "stdafx.h"
#include "SearchRegisteredTicket.h"

SearchRegisteredTicket* SearchRegisteredTicket::searchRegisteredTicketinst;

SearchRegisteredTicket::SearchRegisteredTicket() {}

// Function : SearchRegisteredTicket* SearchRegisteredTicket::getInstance()
// Description: �̱����� ���� �ϳ��� instance�� �Ѱ��ִ� �Լ�
// Parameters : ����
// Return Value : searchRegisteredTicketinst (SearchRegisteredTicket�� instance)
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
SearchRegisteredTicket* SearchRegisteredTicket::getInstance()
{
	if (searchRegisteredTicketinst == nullptr)
		searchRegisteredTicketinst = new SearchRegisteredTicket;
	return searchRegisteredTicketinst;
}

// Function : vector<Ticket*> SearchRegisteredTicket::listTIcket(Seller* s)
// Description: seller�� �ִ� ticketcollection���� vector<Ticket*>�� �����ͼ� �����Ѵ�.
// Parameters : Seller* s
// Return Value : vector<Ticket*> (s->getRegisteredTickets()->getTickets()�� ����)
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
vector<Ticket*> SearchRegisteredTicket::listTIcket(Seller* s)
{
	return s->getRegisteredTickets()->getTickets();
}

