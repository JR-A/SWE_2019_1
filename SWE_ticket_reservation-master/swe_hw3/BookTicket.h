#pragma once
#include "stdafx.h"
class HomeTeam;
class Buyer;
class Ticket;

// Class : BookTicket
// Description: Ƽ�� ������ �� �κ��� ����ϴ� ��Ʈ�� Ŭ����
// Created: 2019/5/28 21:30 pm
// Author: �赵��, 
// mail: donsdevko@gmail.com
class BookTicket
{
private:
	static BookTicket * inst;
	BookTicket();
	~BookTicket();
public:
	Ticket * bookTicket(HomeTeam *, Buyer *, map<string, string>, string);
	static BookTicket * getInstance() { return inst; }
};

