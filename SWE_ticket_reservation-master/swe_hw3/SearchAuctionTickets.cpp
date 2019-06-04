//SearchAuctionTickets.cpp
#include "SearchAuctionTickets.h"
#include "HomeTeam.h"
#include "HomeTeamCollection.h"
#include "AuctionTicketCollection.h"
#include "Ticket.h"
#include "AuctionTicket.h"
#include <algorithm>


SearchAuctionTickets* SearchAuctionTickets::instance;

SearchAuctionTickets::SearchAuctionTickets() {
	homeTeamCollection = HomeTeamCollection::getInstance();
}

SearchAuctionTickets::~SearchAuctionTickets() {
}

SearchAuctionTickets* SearchAuctionTickets::getInstance() {
	SearchAuctionTickets *newInstance;
	if (instance == nullptr) {
		instance = new SearchAuctionTickets();
	}
	newInstance = instance;
	return newInstance;
}

vector<AuctionTicket*> SearchAuctionTickets::showHomeTeamAuctionTickets(string name) {
	vector<HomeTeam*> homeTeams = this->homeTeamCollection->getHomeTeams();

	int i = 0;
	while (i < homeTeams.size() && name.compare(homeTeams.at(i)->getName()) != 0) {		//Ȩ�� �̸����� �˻�
		i++;
	}

	//����Ƽ�� �޾ƿ���
	vector<AuctionTicket*> auctionTickets = homeTeams.at(i)->getAuctionTicketCollection()->getTickets();

	//��⳯¥ �� �ð��� ���� Ƽ�Ϻ��� ����
	sort(auctionTickets.begin(), auctionTickets.end(), AuctionTicket::compareAuction);

	return auctionTickets;
}

HomeTeamCollection* SearchAuctionTickets::getHomeTeamCollection() { return this->homeTeamCollection; }
