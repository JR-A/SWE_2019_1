//AuctionTicketCollection.cpp
#include "AuctionTicketCollection.h"
#include "Ticket.h"
#include "AuctionTicket.h"
#include <vector>
#include <iostream>
using namespace std;

AuctionTicketCollection::AuctionTicketCollection() {
}

AuctionTicketCollection::~AuctionTicketCollection() {
}

// Function : void AuctionTicketCollection::add(AuctionTicket *ticket)
// Description: AuctionTicketCollection�� ����Ƽ�Ϻ��Ϳ� ����Ƽ���� �߰��ϴ� �Լ�.
// Parameters : AuctionTicket *ticket - ����Ƽ���� ������
// Return Value :  None
// Created: 2019/06/29  
// Author: �����
void AuctionTicketCollection::add(AuctionTicket *ticket) {
	this->tickets.push_back(ticket);
}

// Function : void AuctionTicketCollection::deleteTicket(AuctionTicket* ticket) 
// Description: AuctionTicketCollection�� ����Ƽ�Ϻ��Ϳ��� ����Ƽ���� �����ϴ� �Լ�
// Parameters : AuctionTicket *ticket - ����Ƽ���� ������
// Return Value :  None
// Created: 2019/06/29  
// Author: �����
void AuctionTicketCollection::deleteTicket(AuctionTicket* ticket) {
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end();) {
		if ((*it) == ticket) {
			it = tickets.erase(it);
		}
		else {
			it++;
		}
	}
}

// Function : void AuctionTicketCollection::updateBidAmount(AuctionTicket* ticket, int bidAmount) 
// Description: AuctionTicketCollection�� ����Ƽ�Ϻ��Ϳ��� ����Ƽ���� �������� ������Ʈ�ϴ� �Լ�
// Parameters : AuctionTicket *ticket - ����Ƽ���� ������
//					int BidAmount - ���� �ݾ�
// Return Value :  None
// Created: 2019/06/29  
// Author: �����
void AuctionTicketCollection::updateBidAmount(AuctionTicket* ticket, int bidAmount) {
	int i = 0;
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		if ((*it) == ticket) {
			(*it)->updateBidAmount(bidAmount);
		}
	}
}

// Function : void AuctionTicketCollection::updateBuyerID(AuctionTicket* ticket, string buyerID)
// Description: AuctionTicketCollection�� ����Ƽ�Ϻ��Ϳ��� ����Ƽ���� �����ھ��̵� ������Ʈ�ϴ� �Լ�
// Parameters : AuctionTicket *ticket - ����Ƽ���� ������
//					string buyerID - ������ ���̵� (������ ������)
// Return Value :  None
// Created: 2019/06/29  
// Author: �����
void AuctionTicketCollection::updateBuyerID(AuctionTicket* ticket, string buyerID) {
	int i = 0;
	for (vector<AuctionTicket*>::iterator it = tickets.begin(); it != tickets.end(); it++) {
		if ((*it) == ticket) {
			(*it)->updateBuyerID(buyerID);
		}
	}
}

vector<AuctionTicket*> AuctionTicketCollection::getTickets() { return tickets; }

int AuctionTicketCollection::getSize() {
	return this->tickets.size();

}