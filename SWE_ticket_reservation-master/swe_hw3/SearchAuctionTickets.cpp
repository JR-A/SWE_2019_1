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

// Function : SearchAuctionTickets* SearchAuctionTickets::getInstance() 
// Description: �̱��� ������ ���� �Լ� 
// Parameters :   None
// Return Value :  SearchTickets�� ���� ������
// Created: 2019/06/29  
// Author: �����
SearchAuctionTickets* SearchAuctionTickets::getInstance() {
	SearchAuctionTickets *newInstance;
	if (instance == nullptr) {
		instance = new SearchAuctionTickets();
	}
	newInstance = instance;
	return newInstance;
}

// Function : vector<AuctionTicket*> SearchAuctionTickets::showHomeTeamAuctionTickets(string name)
// Description: Ȩ���� �̸��� �ð��� �޾� ����Ƽ�ϵ��� �˻��ϴ��Լ�
// Parameters :  string name - Ȩ���� �̸�
// Return Value :  vector<AuctionTicket*> ����Ƽ�� ������ ����
// Created: 2019/06/29  
// Author: �����
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
