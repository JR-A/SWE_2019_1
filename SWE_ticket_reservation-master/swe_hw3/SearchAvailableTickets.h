#pragma once
#include "stdafx.h"
class HomeTeam;
class Buyer;
class Ticket;

// Class : SearchAvailableTickets
// Description: Ƽ�� �˻��� �����ϴ� ��Ʈ�� Ŭ����
// Created: 2019/5/28 22:10 pm
// Author: �赵��, 
// mail: donsdevko@gmail.com
class SearchAvailableTickets
{
private:
	static SearchAvailableTickets * inst;
	SearchAvailableTickets();
public:
	static SearchAvailableTickets * getInstance() { return inst; }
	vector<Ticket *> showAvailableTickets(HomeTeam *);
	~SearchAvailableTickets();
};

