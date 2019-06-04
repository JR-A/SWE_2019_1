#pragma once
#include "stdafx.h"
class Buyer;

using namespace std;

class Ticket {
private: 
	int price;
	string matchDate; // �Ľ� �ʿ� (�߰��� ���� date typeȮ���ҰԿ�..)
	string homeTeam;
	string awayTeam;
	string seat;
	bool limitedTimeAuction;
	string timeSold;
	string registrationDate;
	bool availability;
	string sellerID;
	string buyerID;

public:
	Ticket();
	// TODO : registrationDate ����ð� �������� �����ڿ��� ���־�� �ϴ� ���� �ƴ���
	// price / matchDate / homeTeam / awayTeam / seat / limitedTimeAuction / sellerID / buyerID / currentTime
	Ticket(int, string, string, string, string, bool,string,string,string);

	virtual ~Ticket();

	bool bookTicket(Buyer *, string);
	Ticket * getTicket();

	// getter / setter
	int getPrice();

	string getMatchDate();

	string getHomeTeam();

	string getAwayTeam();

	string getSeat();

	bool getLimitedTimeAuction();

	bool getAvailability();

	string getRegistrationDate();

	string getTimeSold();
	
	string getSellerID();

	string getBuyerID();

	void updateBuyerID(string buyerID);

	void setAvailability(bool availability);

	// algorithm sorting �� Ŀ���� �񱳿� function ����
	static bool compare(Ticket * me, Ticket * other);

	bool isSame(Ticket *one, Ticket *other);

};