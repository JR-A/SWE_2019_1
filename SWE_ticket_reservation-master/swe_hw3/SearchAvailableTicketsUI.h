#pragma once
#include "stdafx.h"
class HomeTeam;
class HomeTeamCollection;
class Buyer;
class Ticket;

// Class : SearchAvailableTicketsUI
// Description: ���� ���డ���� Ƽ���� ���� extend�� Ƽ�� ������ ���� UI Ŭ����
// Created: 2019/5/29 23:10 pm
// Author: �赵��
// mail: donsdevko@gmail.com
class SearchAvailableTicketsUI
{
private:
	static SearchAvailableTicketsUI * inst;
	SearchAvailableTicketsUI();
public:
	~SearchAvailableTicketsUI();
	static SearchAvailableTicketsUI * getInstance() { return inst; }
	vector<Ticket *> startInterface(Buyer *, string);
	Ticket * buyTicketInterface(Buyer *, HomeTeam *, string, string, string, string);
};

