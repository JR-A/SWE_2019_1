//SearchAuctionTicketsUI.cpp
#include "SearchAuctionTicketsUI.h"
#include "SearchAuctionTickets.h"
#include "ParticipateAuction.h"
#include "HomeTeam.h"
#include "AuctionTicket.h"
#include <iostream>


SearchAuctionTicketsUI* SearchAuctionTicketsUI::instance;

SearchAuctionTicketsUI::SearchAuctionTicketsUI() {

}

SearchAuctionTicketsUI::~SearchAuctionTicketsUI() {

}

SearchAuctionTicketsUI* SearchAuctionTicketsUI::getInstance() {
	SearchAuctionTicketsUI *newInstance;
	if (instance == nullptr) {
		instance = new SearchAuctionTicketsUI();
	}
	newInstance = instance;
	return newInstance;
}

void SearchAuctionTicketsUI::startInterface(vector<HomeTeam*> homeTeams) {

}

string SearchAuctionTicketsUI::selectHomeTeam(string teamName) {

	vector<AuctionTicket*> auctionTickets = SearchAuctionTickets::getInstance()->showHomeTeamAuctionTickets(teamName);
	string out;

	int i = 0;
	cout << "\n===================================================================" << endl;
	while (i < (int)auctionTickets.size()) {
		
		AuctionTicket *ticket = auctionTickets[i];
		cout << "�� �� | ��¥-�ð� | Ȩ   �� | �� �� �� �� | �¼� | �������� ���� �ð�" << endl;
		cout << to_string(ticket->getPrice()) + " | " + ticket->getMatchDate() + " | " + ticket->getHomeTeam() + " | " + ticket->getAwayTeam() + " | " + ticket->getSeat()+ " | " + ticket->getClosingTime() << endl;
		
		
		out.append(to_string(ticket->getPrice())); out.append(" ");
		out.append(ticket->getMatchDate()); out.append(" ");
		out.append(ticket->getHomeTeam()); out.append(" ");
		out.append(ticket->getAwayTeam()); out.append(" ");
		out.append(ticket->getSeat()); out.append(" ");
		out.append(ticket->getClosingTime());
		if (i != auctionTickets.size()-1) {
			out.append("\n");
		}	
		i++;
	}
	cout << "\n===================================================================" << endl;
	return out;
}

void SearchAuctionTicketsUI::selectParticipateAuction(AuctionTicket *auctionTicket) {
	int bidAmount;

	cout << "���� ���� �ݾ� : " << auctionTicket->getBidAmount() << endl;

	cout << "��� �������� �Է��ϼ���(��) : " << endl;
	cin >> bidAmount;

	ParticipateAuction::getInstance()->participateAuction(auctionTicket, bidAmount);
}