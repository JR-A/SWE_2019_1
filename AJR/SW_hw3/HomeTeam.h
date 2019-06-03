//HomeTeam.h
#ifndef _HOMETEAM_H
#define _HOMETEAM_H
#include <string>
#include"TicketCollection.h"
#include "AuctionTicketCollection.h"

class Ticket;
class AuctionTicketCollection;
using namespace std;
class HomeTeam {
private:
	string name;
	string city;
	TicketCollection *ticketCollection;
	AuctionTicketCollection *auctionTicketCollection;
public:
	HomeTeam();
	HomeTeam(string, string);
	virtual ~HomeTeam();

	string getName();
	string getCity();
	TicketCollection* getTicketCollection(); // ���� ���
	AuctionTicketCollection* getAuctionTicketCollection(); // ���
	vector<Ticket *> listAvailableTickets(); // ���� - Ƽ�ϵ� �����ֵ��� (����) ���� ���� 
											 // ADDED : �÷��� �����ϴ� �Լ��� �ʿ��մϴ�.
	void setTicketCollection(TicketCollection *);
	void setAuctionTicketCollection(AuctionTicketCollection *);

};
#endif // !_HOMETEAM_H
