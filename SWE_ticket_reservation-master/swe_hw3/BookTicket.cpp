#include "stdafx.h"
#include "BookTicket.h"
#include "Ticket.h"
#include "HomeTeam.h"
#include "SearchAvailableTicketsUI.h"

BookTicket::BookTicket()
{
}


BookTicket::~BookTicket()
{
}

// Function : Ticket * BookTicket::bookTicket(HomeTeam * homeTeam, Buyer * buyer, map<string, string> ticketInfo, string currentTime)
// Description:
// Ƽ�� ������ ����ð� ������� Ƽ���� �����ϴ� �Լ��Դϴ�
// Parameters : HomeTeam * homeTeam - �����ϰ� ���� Ȩ��
// Buyer * buyer // ������
// map<string, string> ticketInfo // �����ϰ���� Ƽ�� ����
// string currentTime // ����ð�
// Return Value : ����� TIcket �����͸� ��ȯ�մϴ�.
//
// Created: 2019/05/28 21:10 pm
// Author: �赵��
// Revisions :
// 1. �赵�� 2019/06/03 19:10 pm
// currentTime �Ķ���� �߰��Ǿ����ϴ�.
Ticket * BookTicket::bookTicket(HomeTeam * homeTeam, Buyer * buyer, map<string, string> ticketInfo, string currentTime) {
	vector<Ticket *> homeTeamTickets = homeTeam->getTicketCollection()->getTickets();

	// Ȩ�� Ƽ���� ������ ��ġ�ϴ� Ƽ�� ������ ���� ��
	for (int i = 0; i < homeTeamTickets.size(); i++) {
		if (homeTeamTickets[i]->getAvailability() && ticketInfo["matchDate"] == homeTeamTickets[i]->getMatchDate() && ticketInfo["awayTeam"] == homeTeamTickets[i]->getAwayTeam() && ticketInfo["seat"] == homeTeamTickets[i]->getSeat()) {
			homeTeamTickets[i]->bookTicket(buyer, currentTime);
			return homeTeamTickets[i];
		}
	}

	return NULL;
}

BookTicket * BookTicket::inst;