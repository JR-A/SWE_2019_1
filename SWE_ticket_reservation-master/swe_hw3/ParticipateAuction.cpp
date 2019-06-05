//ParticipateAuction.cpp
#include "ParticipateAuction.h"
#include "AuctionTicket.h"
#include "HomeTeamCollection.h"
#include "HomeTeam.h"

ParticipateAuction* ParticipateAuction::instance;

ParticipateAuction::ParticipateAuction() {
	homeTeamCollection = HomeTeamCollection::getInstance();
}

ParticipateAuction::~ParticipateAuction() {
}

// Function : ParticipateAuction* ParticipateAuction::getInstance()
// Description: �̱��� ������ ���� �Լ� 
// Parameters :   None
// Return Value :  ParticipateAuction�� ������
// Created: 2019/06/29  
// Author: �����
ParticipateAuction* ParticipateAuction::getInstance() {
	ParticipateAuction *newInstance;
	if (instance == nullptr) {
		instance = new ParticipateAuction();
	}
	newInstance = instance;
	return newInstance;
}

// Function : void ParticipateAuction::participateAuction(string teamName, AuctionTicket *auctionTicket, string buyerID, int bidAmount)
// Description: ��ſ� �����ϱ� ���� ���� Ƽ���� �˻��� ���� �ݾװ� ������ ���̵� ������Ʈ�ϴ� �Լ�.(��ȿ�� �˻� ���� - ���� �����׺��� ���� �ݾ׸��� �Է��Ѵٰ� ����)
// Parameters :  string teamName - Ȩ���� �̸�
//					AuctionTicket *auctionTicket - ����Ƽ�� ��ü ������
//					string buyerID - ��ſ� �����ϴ� ��������ID
//					int bidAmount - �����ݾ�
// Return Value :  None
// Created: 2019/06/29
// Author: �����
void ParticipateAuction::participateAuction(string teamName, AuctionTicket *auctionTicket, string buyerID, int bidAmount) {
	vector<HomeTeam*> homeTeams = this->homeTeamCollection->getHomeTeams();

	int i = 0;
	while (i < homeTeams.size() && teamName.compare(homeTeams.at(i)->getName()) != 0) {		//Ȩ�� �̸����� �˻�
		i++;
	}

	homeTeams.at(i)->getAuctionTicketCollection()->updateBidAmount(auctionTicket, bidAmount);
	homeTeams.at(i)->getAuctionTicketCollection()->updateBuyerID(auctionTicket, buyerID);
}

HomeTeamCollection* ParticipateAuction::getHomeTeamCollection() { return this->homeTeamCollection; }