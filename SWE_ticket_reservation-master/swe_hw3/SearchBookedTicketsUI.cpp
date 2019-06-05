#include "stdafx.h"
#include "SearchBookedTicketsUI.h"
#include "SearchBookedTickets.h"
#include "Buyer.h"
#include "Ticket.h"

SearchBookedTicketsUI::SearchBookedTicketsUI()
{
}


SearchBookedTicketsUI::~SearchBookedTicketsUI()
{
}

// Function : vector<Ticket *> SearchBookedTicketsUI::showBookedList(Buyer * buyer)
// Description:
// ����� ����Ʈ�� ��ȯ�ޱ� ���� �ٿ���� Ŭ������ �Լ�
// Parameter : Buyer * buyer - Ƽ�� ���̾�
// Return Value : ���̾ ������ Ticket ������ ���͸� �����մϴ�.
//
// Created: 2019/06/02 21:10 pm
// Author: �赵��
vector<Ticket *> SearchBookedTicketsUI::showBookedList(Buyer * buyer) {
	return SearchBookedTickets::getInstance()->listBookedTickets(buyer);
}

SearchBookedTicketsUI * SearchBookedTicketsUI::inst;