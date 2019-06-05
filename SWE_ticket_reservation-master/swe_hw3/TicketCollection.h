#pragma once
#include "stdafx.h"
class Ticket;

// Class : TicketCollection
// Description: collection class�� Ticket �ν��Ͻ����� �����ϰ� �����Ѵ�.
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
// mail: minseob17@naver.com
class TicketCollection {

private:
	vector<Ticket *> tickets;

public:
	TicketCollection();
	virtual ~TicketCollection();
	void add(Ticket *);
	void deleteTicket(Ticket *);
	bool existTicket();
	void setAvailability(Ticket* ticket, bool availability);
	vector<Ticket *> getTickets();
};
