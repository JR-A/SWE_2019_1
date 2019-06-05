#pragma once
#include "stdafx.h"
class Ticket;

// Class : TicketCollection
// Description: Ƽ�ϵ��� �����͸� ��Ƴ��� �ݷ��� Ŭ�����Դϴ�
// Created: 2019/5/28 20:30 pm
// Author: �赵��
// mail: donsdevko@gmail.com
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
