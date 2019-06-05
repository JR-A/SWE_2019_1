#include "stdafx.h"
#include "SearchAvailableTicketsUI.h"
#include "SearchAvailableTickets.h"
#include "Buyer.h"
#include "Ticket.h"
#include "BookTicket.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"

SearchAvailableTicketsUI::SearchAvailableTicketsUI()
{
}


SearchAvailableTicketsUI::~SearchAvailableTicketsUI()
{
}

// Function : vector<Ticket *> SearchAvailableTicketsUI::startInterface(Buyer * buyer, string teamName)
// Description:
// ���డ���� Ƽ���� �˻��ϴ� UI�� ������ ��û�ϴ� �Լ�
// Parameters : Buyer * buyer - ������ ������
// string teamName - �� �̸�
// Return Value : ���� ������ Ƽ�� ������ ����
// Created: 2019/05/30 21:30 pm
// Author: �赵��
vector<Ticket *> SearchAvailableTicketsUI::startInterface(Buyer * buyer, string teamName){ 
	HomeTeam * homeTeam = HomeTeamCollection::getInstance()->getHomeTeamByName(teamName);
	return SearchAvailableTickets::getInstance()->showAvailableTickets(homeTeam);
}

// Function : Ticket * SearchAvailableTicketsUI::buyTicketInterface(Buyer * buyer, HomeTeam * homeTeam, string matchDate, string awayTeam, string seat, string currentTime)
// Description:
// Ƽ���� �����ҋ� ��ġ�� �Լ�
// Parameters : Buyer * buyer - ������ ������
// HomeTeam * homeTeam - ������ ���ϴ� Ȩ��
// string matchDate - ����Ͻ�
// string awayTeam - ������� �̸�
// string seat - �¼���ġ
// Return Value : ����� Ƽ�� ������
// Created: 2019/05/30 22:30 pm
// Author: �赵��
Ticket * SearchAvailableTicketsUI::buyTicketInterface(Buyer * buyer, HomeTeam * homeTeam, string matchDate, string awayTeam, string seat, string currentTime) {
	map<string, string> ticketInfo;
	ticketInfo.insert(make_pair("matchDate", matchDate));
	ticketInfo.insert(make_pair("awayTeam", awayTeam));
	ticketInfo.insert(make_pair("seat", seat));
	return BookTicket::getInstance()->bookTicket(homeTeam, buyer, ticketInfo, currentTime);
}

SearchAvailableTicketsUI * SearchAvailableTicketsUI::inst;