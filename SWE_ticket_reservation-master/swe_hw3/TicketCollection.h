#pragma once
#include "stdafx.h"
class Ticket;

class TicketCollection {

private:
	vector<Ticket *> tickets;

public:
	TicketCollection();
	virtual ~TicketCollection();
	void add(Ticket *);
	bool existTicket();
	vector<Ticket *> getTickets();
};
