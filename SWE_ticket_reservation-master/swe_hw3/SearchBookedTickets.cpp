#include "stdafx.h"
#include "SearchBookedTickets.h"
#include "Buyer.h"
#include "Ticket.h"
#include "TicketCollection.h"

SearchBookedTickets::SearchBookedTickets()
{
}


SearchBookedTickets::~SearchBookedTickets()
{
}

// Function : vector<Ticket *> SearchBookedTickets::listBookedTickets(Buyer * buyer)
// Description:
// ����� ��� Ƽ�� ������ ���͸� ��ȯ�մϴ�
// Parameter : Buyer * buyer - ��ȸ�� ��û�� ���̾�
// Return Value : ����� Ƽ���� �����Ͱ� ��� ����
//
// Created: 2019/06/02 19:15 pm
// Author: �赵��
vector<Ticket *> SearchBookedTickets::listBookedTickets(Buyer * buyer) {
	return buyer->getBookedTickets()->getTickets();
}

SearchBookedTickets * SearchBookedTickets::inst;