#pragma once
#include "TicketCollection.h"
#include "Ticket.h"
#include "Seller.h"

// Class : SearchRegisteredTicket
// Description: controll class�� ������ Ƽ���ݷ������κ��� vector<Ticket*>�� �޾ƿ´�.
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
// mail: minseob17@naver.com
class SearchRegisteredTicket
{
private:
	SearchRegisteredTicket();
	static SearchRegisteredTicket* searchRegisteredTicketinst;
public:
	static SearchRegisteredTicket* getInstance();
	vector<Ticket*> listTIcket(Seller *s);
};

