#include "stdafx.h"
#include "HomeTeam.h"
#include "Ticket.h"
#include "TicketCollection.h"
#include "AuctionTicketCollection.h"

HomeTeam::HomeTeam() {

}

HomeTeam::~HomeTeam() {

}

//constructor overloading
HomeTeam::HomeTeam(string name, string city) {
	this->name = name;
	this->city = city;
}


HomeTeam HomeTeam::getHomeTeam() {
	return * this;
}

string HomeTeam::getName() {
	return this->name;
}

string HomeTeam::getCity() {
	return this->city;
}

// Function : TicketCollection * HomeTeam::getTicketCollection()
// Description:
// Ȩ���� Ƽ�� �ݷ��� �ν��Ͻ� �����͸� ��ȯ�մϴ�
// Return Value : Ȩ���� Ƽ�� �ݷ��� �ν��Ͻ� ������
//
// Created: 2019/05/29 21:15 pm
// Author: �赵��
TicketCollection * HomeTeam::getTicketCollection() {
	return ticketCollection;
}

AuctionTicketCollection* HomeTeam::getAuctionTicketCollection() { 
	return this->auctionTicketCollection; 
}

// Function : void HomeTeam::setTicketCollection(TicketCollection * ticketCollection)
// Description:
// Ȩ������ Ƽ�� �ݷ����� �����ϴ� �Լ��Դϴ�
// Parameter : TicketCollection * ticketCollection - ������ Ƽ�� �ݷ��� �ν��Ͻ�
//
// Created: 2019/05/29 21:20 pm
// Author: �赵��
void HomeTeam::setTicketCollection(TicketCollection * ticketCollection) {
	this->ticketCollection = ticketCollection;
}

void HomeTeam::setAuctionTicketCollection(AuctionTicketCollection * ticketCollection) {

	this->auctionTicketCollection = ticketCollection;

}

// Function : vector<Ticket *> HomeTeam::listAvailableTickets()
// Description:
// Ȩ������ ���� ���� ������ Ƽ���� ��ȯ�մϴ�
// Return: ���� ������ Ƽ�� ������ ����
// Created: 2019/05/29 21:40 pm
// Author: �赵��
vector<Ticket *> HomeTeam::listAvailableTickets() {
	return ticketCollection->getTickets();
}