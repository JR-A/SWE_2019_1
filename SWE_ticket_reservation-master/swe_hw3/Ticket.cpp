#include "stdafx.h"
#include "Ticket.h"
#include "Buyer.h"

Ticket::Ticket() {
	// TODO Auto-generated constructor stub
}

// price / matchDate / homeTeam / awayTeam / seat / limitedTimeAuction
Ticket::Ticket(int price, string matchDate, string homeTeam, string awayTeam, string seat, bool limitedTimeAuction, string sellerID, string buyerID, string currentTime) {
	this->price = price;
	this->matchDate = matchDate;
	this->limitedTimeAuction = limitedTimeAuction;
	this->homeTeam = homeTeam;
	this->awayTeam = awayTeam;
	this->seat = seat;
	this->availability = true;
	// TODO : ����ð����� �ٲ�� ��
	this->registrationDate = currentTime;
	this->sellerID = sellerID;
	this->buyerID = buyerID;
}

// getter / setter
int Ticket::getPrice() {
	return price;
}

string Ticket::getMatchDate() {
	return matchDate;
}

string Ticket::getHomeTeam() {
	return homeTeam;
}

string Ticket::getAwayTeam() {
	return awayTeam;
}

string Ticket::getSeat() {
	return seat;
}

bool Ticket::getLimitedTimeAuction() {
	return limitedTimeAuction;
}

bool Ticket::getAvailability() {
	return availability;
}

string Ticket::getRegistrationDate() {
	return registrationDate;
}

string Ticket::getTimeSold() {
	return timeSold;
}

string Ticket::getSellerID() {
	return sellerID;
}

string Ticket::getBuyerID() {
	return buyerID;
}

Ticket::~Ticket() {
	// TODO Auto-generated destructor stub
}

// Function : Ticket * Ticket::getTicket()
// Description:
// �ش� �ν��Ͻ��� ������ ��ȯ
// Return Value : Ticket Pointer
// Created: 2019/05/29 21:30 pm
// Author: �赵��
Ticket * Ticket::getTicket() {
	return this;
}

void Ticket::updateBuyerID(string buyerID) {
	this->buyerID = buyerID;
}

// Function : bool Ticket::bookTicket(Buyer * buyer, string currentTime)
// Description:
// Ƽ���� �����ϰ� availability ����
// Parameters : Buyer * buyer - ������
// string currentTime - ����ð�
// Return Value : ���� ���� ����
// Created: 2019/05/29 21:30 pm
// Author: �赵��
bool Ticket::bookTicket(Buyer * buyer, string currentTime) {
	// [�������] [��¥-�ð�] [Ȩ��] [�������] [�¼���ġ]
	buyer->getBookedTickets()->add(this);
	timeSold = currentTime; // TODO : ����ð����� �ٲ�� ��
	availability = false;
	this->buyerID = buyer->getID();
	return true;
}

void Ticket::setAvailability(bool availability) {
	this->availability = availability;
}

// Function : bool Ticket::compare(Ticket * me, Ticket * other)
// Description:
// Ƽ�� ������ ���� sort ���� �� �Լ�
// Parameters : Ticket * me - �� ��û Ƽ�� ������
// Ticket * other - �� ��� Ƽ�� ������
// Return Value : ������ �Ķ���Ͱ� �� ū�� ����
// Created: 2019/05/29 23:30 pm
// Author: �赵��
bool Ticket::compare(Ticket * me, Ticket * other) {
	string mmd = me->getMatchDate();
	string omd = other->getMatchDate();
	mmd.erase(remove(mmd.begin(), mmd.end(), ':'), mmd.end());
	omd.erase(remove(omd.begin(), omd.end(), ':'), omd.end());

	if (atoi(mmd.c_str()) < atoi(omd.c_str())) {
		return true;
	}
	else {
		return false;
	}
}

// Function : bool Ticket::isSame(Ticket *one, Ticket *other) 
// Description: �� Ƽ�ϰ�ü�� ������ ������ �ٸ��� �˻��ϴ� �Լ�
// Parameters :   Ticket *one - Ƽ�� ��ü ������1
//					Ticket *other - Ƽ�� ��ü ������2
// Return Value :  bool - ������ true, �ٸ��� false
// Created: 2019/06/29  
// Author: �����
bool Ticket::isSame(Ticket *one, Ticket *other) {
	int onePrice = one->getPrice();
	int otherPrice = other->getPrice();
	string oneMatchDate = one->getMatchDate();
	string otherMatchDate = other->getMatchDate();
	string oneHomeTeam = one->getHomeTeam();
	string otherHomeTeam = other->getHomeTeam();
	string oneAwayTeam = one->getAwayTeam();
	string otherAwayTeam = other->getAwayTeam();
	string oneSeat = one->getSeat();
	string otherSeat = other->getSeat();

	oneMatchDate.erase(remove(oneMatchDate.begin(), oneMatchDate.end(), ':'), oneMatchDate.end());
	otherMatchDate.erase(remove(otherMatchDate.begin(), otherMatchDate.end(), ':'), otherMatchDate.end());

	if (onePrice==otherPrice && atoi(oneMatchDate.c_str()) == atoi(otherMatchDate.c_str()) && oneHomeTeam.compare(otherHomeTeam)==0 &&oneAwayTeam.compare(otherAwayTeam)==0 && oneSeat.compare(otherSeat)==0) {
		return true;
	}
	else {
		return false;
	}
}
