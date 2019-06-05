#include "stdafx.h"
#include "RegisterTicket.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"

RegisterTicket* RegisterTicket::registerTicketinst;

RegisterTicket::RegisterTicket()
{
}

RegisterTicket::~RegisterTicket()
{
}

// Function : static RegisterTicket* getInstance()
// Description: �̱����� ���� �ϳ��� instance�� �Ѱ��ִ� �Լ�
// Parameters : ����
// Return Value : registerTicketinst (RegisterTicket�� instance)
// Created: 2019/5/29 12:00 pm
// Author: ��μ�

RegisterTicket* RegisterTicket::getInstance()
{
	if (registerTicketinst == nullptr)
		registerTicketinst = new RegisterTicket();
	return registerTicketinst;
}

// Function : void RegisterTicketUI::putTicketInfo(string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,Seller *s)
// Description: UI�κ��� ���� Ƽ���� ������ Ƽ���� �����ϰ� Ƽ���� seller�� ticketcollection�� hometeam�� ticketcollection�� �߰��Ѵ�.
// Parameters : string _price,string _matchDate,string _homeTeam,string _awayTeam,string _seat,bool _limitedTimeAuction,Seller *s
// Return Value : ����
// Created: 2019/5/29 12:00 pm
// Author: ��μ�
void RegisterTicket::registerNewTicket(int _price,
	string _matchDate,
	string _homeTeam,
	string _awayTeam,
	string _seat,
	bool _limitedTimeAuction,
	Seller *s)
{
	string sellerID = s->getID();
	Ticket *newTicket = new Ticket(_price, _matchDate, _homeTeam, _awayTeam, _seat, _limitedTimeAuction, sellerID, "", _matchDate);
	s->getRegisteredTickets()->add(newTicket);
	// Seller�� �ִ� ticketcollection�� �߰�
	HomeTeam * hometeam = HomeTeamCollection::getInstance()->getHomeTeamByName(_homeTeam);
	hometeam->getTicketCollection()->add(newTicket);
	// HomeTeam�� �ִ� ticketcollection�� �߰�
}


