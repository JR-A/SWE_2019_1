#pragma once
#include "stdafx.h"
class Buyer; 
class Ticket;

// Class : SearchBookedTickets
// Description: ���̾ ������ Ƽ���� ���� �ֵ��� �ϴ� ��Ʈ�� Ŭ����
// Created: 2019/6/2 20:10 pm
// Author: �赵��, 
// mail: donsdevko@gmail.com
class SearchBookedTickets
{
private:
	static SearchBookedTickets * inst;
	SearchBookedTickets();
	~SearchBookedTickets();
public:
	static SearchBookedTickets * getInstance() { return inst; }
	vector<Ticket *> listBookedTickets(Buyer *);
};

