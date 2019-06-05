#pragma once
#include "stdafx.h"
#include "TicketCollection.h"
#include "Ticket.h"
#include "Seller.h"
#include "MemberCollection.h"
#include "MemberManagement.h"
using namespace std;

// Class : RegisterTicket
// Description: controll class�� ���� Ƽ���� ������ Ƽ���� �����Ѵ�. �׸��� �ΰ��� ticketcollection�� Ƽ���� �߰��Ѵ�.
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
// mail: minseob17@naver.com
class RegisterTicket
{
private:
	RegisterTicket();
	static RegisterTicket* registerTicketinst;
public:
	static RegisterTicket* getInstance();
	void registerNewTicket(int _price,
		string _matchDate,
		string _homeTeam,
		string _awayTeam,
		string _seat,
		bool _limitedTimeAuction,
		Seller* s);
	~RegisterTicket();
};

