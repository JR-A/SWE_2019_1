#pragma once
#include "stdafx.h"
class Buyer;
class Ticket;

// Class : SearchBookedTicketUI
// Description: �ڽ��� ������ Ƽ���� Ȯ���Ҽ� �ִ� �ٿ���� Ŭ����
// Created: 2019/6/2 19:20 pm
// Author: �赵��, 
// mail: donsdevko@gmail.com
class SearchBookedTicketsUI
{
private:
	static SearchBookedTicketsUI * inst;
	SearchBookedTicketsUI();
public:
	~SearchBookedTicketsUI();
	vector<Ticket *> showBookedList(Buyer *);
	static SearchBookedTicketsUI * getInstance() { return inst; }
};

